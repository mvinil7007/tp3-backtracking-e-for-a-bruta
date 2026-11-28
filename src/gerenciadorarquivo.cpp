#include "gerenciadorarquivo.hpp"
#include "excecoes.hpp"
#include <fstream>
#include <string>

std::vector<Palestra> GerenciadorArquivo::lerEntrada(const std::string& caminhoArquivo, int& tempoDisponivel) const {
    std::ifstream abrir(caminhoArquivo);
    if (!abrir.is_open()) {
        throw ArquivoException(caminhoArquivo);
    }

    int n = 0;
    int tempoLido = 0;
    tempoDisponivel = 0;

    // Verifica se n e T puderam ser lidos como numeros inteiros
    if (!(abrir >> n >> tempoLido)) {
        throw EntradaInvalidaException();
    }

    // Valida os limites de n (1 a 15) e T (1 a 1000)
    if (n < 1 || n > 15 || tempoLido < 1 || tempoLido > 1000) {
        throw EntradaInvalidaException();
    }

    std::vector<Palestra> palestras;
    // Reserva espaço para n palestras para evitar realocações desnecessárias
    palestras.reserve(static_cast<size_t>(n));

    for (int i = 0; i < n; ++i) {
        std::string nome;
        int duracao = 0;
        int publico = 0;

        // Verifica se a linha existe e se duracao e publico sao numeros validos
        if (!(abrir >> nome >> duracao >> publico)) {
            throw EntradaInvalidaException();
        }

        // Duracao e publico devem ser estritamente positivos
        if (duracao <= 0 || publico <= 0) {
            throw EntradaInvalidaException();
        }
        // Adiciona a palestra ao vetor diretamente, evitando criar vetores temporários como em push_back 
        palestras.emplace_back(nome, duracao, publico);
    }

    tempoDisponivel = tempoLido;
    abrir.close();
    return palestras;
}

void GerenciadorArquivo::escreverSaida(const std::string& caminhoArquivo,int publicoTotal,int tempoTotal,
                                       const std::vector<std::string>& palestrasEscolhidas,int nosCriados) const {
    std::ofstream sair(caminhoArquivo);
    if (!sair.is_open()) {
        throw ArquivoException(caminhoArquivo);
    }

    sair << publicoTotal << "\n";

    sair << tempoTotal << "\n";

    for (size_t i = 0; i < palestrasEscolhidas.size(); ++i) {
        if (i > 0)
            sair << " ";
        sair << palestrasEscolhidas[i];
    }
    sair << "\n";

    sair << "Nos criados: " << nosCriados << "\n";

    sair.close();
}