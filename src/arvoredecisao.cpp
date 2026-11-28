#include "arvoredecisao.hpp"

ArvoreDecisao::ArvoreDecisao() : _raiz(nullptr), _nosCriados(0) {

}

ArvoreDecisao::~ArvoreDecisao() {
    liberarArvore(_raiz);
    _raiz = nullptr;
}

void ArvoreDecisao::liberarArvore(No* no) {
    if (no == nullptr) {
        return;
    }
    // Libera os filhos primeiro antes de deletar o no atual
    liberarArvore(no->esq);
    liberarArvore(no->dir);
    delete no;
}

void ArvoreDecisao::construirForcaBruta(const std::vector<Palestra>& palestras) {
    liberarArvore(_raiz);
    _nosCriados = 0;
    _raiz = construirForcaBrutaRec(palestras, 0, 0, 0);
}

No* ArvoreDecisao::construirForcaBrutaRec(const std::vector<Palestra>& palestras,unsigned int indice,int tempoAtual,int publicoAtual) {
    No* novo = new No(tempoAtual, publicoAtual);
    _nosCriados++;

    // Caso base: todas as palestras ja foram decididas
    if (indice == palestras.size()) {
        return novo;
    }

    // inclui palestras[indice] sem verificar se estoura o tempo
    novo->esq = construirForcaBrutaRec(palestras,indice + 1,tempoAtual + palestras[indice].getDuracao(),publicoAtual + palestras[indice].getPublico());

    // nao inclui palestras[indice]
    novo->dir = construirForcaBrutaRec(palestras,
                                       indice + 1,
                                       tempoAtual,
                                       publicoAtual);

    return novo;
}

void ArvoreDecisao::construirBacktracking(const std::vector<Palestra>& palestras, int tempoDisponivel) {
    liberarArvore(_raiz);
    _nosCriados = 0;
    _raiz = construirBacktrackingRec(palestras, 0, 0, 0, tempoDisponivel);
}

No* ArvoreDecisao::construirBacktrackingRec(const std::vector<Palestra>& palestras,unsigned int indice,int tempoAtual,int publicoAtual,int tempoDisponivel) {
    No* novo = new No(tempoAtual, publicoAtual);
    _nosCriados++;

    if (indice == palestras.size()) {
        return novo;
    }

    int proximoTempo = tempoAtual + palestras[indice].getDuracao();

    // Poda: so cria o ramo da esquerda (incluir) se couber no tempo disponivel
    if (proximoTempo <= tempoDisponivel) {
        novo->esq = construirBacktrackingRec(palestras,indice + 1,proximoTempo,publicoAtual + palestras[indice].getPublico(),tempoDisponivel);
    }

    // Ramo da direita (nao incluir) nunca aumenta o tempo, entao sempre e valido
    novo->dir = construirBacktrackingRec(palestras,indice + 1,tempoAtual,publicoAtual,tempoDisponivel);

    return novo;
}

void ArvoreDecisao::encontrarMelhorSolucao(const std::vector<Palestra>& palestras,int tempoDisponivel,int& melhorPublico,int& melhorTempo,std::vector<std::string>& melhorCaminho) const {
    melhorPublico = -1;
    melhorTempo = 0;
    melhorCaminho.clear();

    std::vector<std::string> caminhoAtual;
    caminhoAtual.reserve(palestras.size());

    buscarMelhorPreOrdem(_raiz,palestras,0,tempoDisponivel,caminhoAtual,melhorPublico,melhorTempo,melhorCaminho);
}

void ArvoreDecisao::buscarMelhorPreOrdem(No* atual,const std::vector<Palestra>& palestras,unsigned int nivel,int tempoDisponivel,
                                         std::vector<std::string>& caminhoAtual,int& melhorPublico,int& melhorTempo,std::vector<std::string>& melhorCaminho) const {
    if (atual == nullptr) {
        return;
    }

    // Visita o no atual e verifica se é uma folha valida no ultimo nivel
    if (nivel == palestras.size()) {
        if (atual->tempo <= tempoDisponivel && atual->publico > melhorPublico) {
            melhorPublico = atual->publico;
            melhorTempo = atual->tempo;
            melhorCaminho = caminhoAtual;
        }
        return;
    }

    // Percorre subarvore esquerda (inclui palestras[nivel])
    if (atual->esq != nullptr) {
        caminhoAtual.push_back(palestras[nivel].getNome());
        buscarMelhorPreOrdem(atual->esq,palestras,nivel + 1,tempoDisponivel,caminhoAtual,melhorPublico,melhorTempo,melhorCaminho);
        caminhoAtual.pop_back();
    }

    // Percorre subarvore direita
    if (atual->dir != nullptr) {
        buscarMelhorPreOrdem(atual->dir,palestras,nivel + 1,tempoDisponivel,caminhoAtual,melhorPublico,melhorTempo,melhorCaminho);
    }
}

int ArvoreDecisao::getNosCriados() const {
    return _nosCriados;
}