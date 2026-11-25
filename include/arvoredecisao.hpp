#ifndef ARVORE_DECISAO_HPP
#define ARVORE_DECISAO_HPP

#include <string>
#include <vector>
#include "palestra.hpp"

// Estrutura que representa um no da arvore binaria de decisao.

struct No {
    int tempo;
    int publico;
    No* esq; // inclui a palestra atual
    No* dir; // nao inclui a palestra atual

    No(int t, int p) : tempo(t), publico(p), esq(nullptr), dir(nullptr) {}
};

// Classe responsavel por construir, percorrer e liberar a arvore de decisao
// utilizando Forca Bruta ou Backtracking.
 
class ArvoreDecisao {
private:
    No* _raiz;
    int _nosCriados;

    // Metodos auxiliares recursivos
    No* construirForcaBrutaRec(const std::vector<Palestra>& palestras,unsigned int indice,int tempoAtual,int publicoAtual);

    No* construirBacktrackingRec(const std::vector<Palestra>& palestras,
                                 size_t indice,
                                 int tempoAtual,
                                 int publicoAtual,
                                 int tempoDisponivel);

    void buscarMelhorPreOrdem(No* atual,
                              const std::vector<Palestra>& palestras,
                              size_t nivel,
                              int tempoDisponivel,
                              std::vector<std::string>& caminhoAtual,
                              int& melhorPublico,
                              int& melhorTempo,
                              std::vector<std::string>& melhorCaminho) const;

    void liberarArvore(No* no);

public:
    ArvoreDecisao();
    ~ArvoreDecisao();

    // Evita copia acidental de ponteiros da arvore
    ArvoreDecisao(const ArvoreDecisao&) = delete;
    ArvoreDecisao& operator=(const ArvoreDecisao&) = delete;

    // Constroi a arvore completa (Forca Bruta)
    void construirForcaBruta(const std::vector<Palestra>& palestras);

    // Constroi a arvore podando ramos que excedem o tempo disponivel (Backtracking)
    void construirBacktracking(const std::vector<Palestra>& palestras, int tempoDisponivel);

    // Percorre a arvore em pre-ordem e preenche os dados da melhor programacao
    void encontrarMelhorSolucao(const std::vector<Palestra>& palestras,
                                int tempoDisponivel,
                                int& melhorPublico,
                                int& melhorTempo,
                                std::vector<std::string>& melhorCaminho) const;

    int getNosCriados() const;
};

#endif