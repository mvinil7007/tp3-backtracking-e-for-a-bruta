#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include "gerenciadorarquivo.hpp"
#include "arvoredecisao.hpp"
#include "excecoes.hpp"

// Executavel da solucao por Forca Bruta.
int main(int argc, char* argv[]) {
    try {
        if (argc != 3) {
            throw std::invalid_argument(std::string("Uso: ") + argv[0] + " <palestras> <saida>");
        }

        GerenciadorArquivo gerenciador;
        int tempoDisponivel = 0;
        std::vector<Palestra> palestras = gerenciador.lerEntrada(argv[1], tempoDisponivel);

        ArvoreDecisao arvore;
        arvore.construirForcaBruta(palestras);

        int melhorPublico = 0;
        int melhorTempo = 0;
        std::vector<std::string> melhorCaminho;

        arvore.encontrarMelhorSolucao(palestras, tempoDisponivel, melhorPublico, melhorTempo, melhorCaminho);

        gerenciador.escreverSaida(argv[2], melhorPublico, melhorTempo, melhorCaminho, arvore.getNosCriados());
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }

    return 0;
}