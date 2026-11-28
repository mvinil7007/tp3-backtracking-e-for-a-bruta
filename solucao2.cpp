#include <iostream>
#include <string>
#include <vector>
#include "gerenciadorarquivo.hpp"
#include "arvoredecisao.hpp"
#include "excecoes.hpp"

// Executavel da solucao por Backtracking.
int main(int argc, char* argv[]) {
    if (argc < 3) {
        std::cerr << "Uso: " << argv[0] << " <arquivo_entrada> <arquivo_saida>" << std::endl;
        return 1;
    }

    try {
        GerenciadorArquivo gerenciador;
        int tempoDisponivel = 0;
        std::vector<Palestra> palestras = gerenciador.lerEntrada(argv[1], tempoDisponivel);

        ArvoreDecisao arvore;
        arvore.construirBacktracking(palestras, tempoDisponivel);

        int melhorPublico = 0;
        int melhorTempo = 0;
        std::vector<std::string> melhorCaminho;

        arvore.encontrarMelhorSolucao(palestras,tempoDisponivel,melhorPublico,melhorTempo,melhorCaminho);

        gerenciador.escreverSaida(argv[2],melhorPublico,melhorTempo,melhorCaminho,arvore.getNosCriados());


    } catch (const std::exception& e) {
        std::cerr << "Erro: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}