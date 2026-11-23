#ifndef GERENCIADOR_ARQUIVO_HPP
#define GERENCIADOR_ARQUIVO_HPP

#include <string>
#include <vector>
#include "palestra.hpp"


// Classe responsavel pela leitura e validacao do arquivo de entrada
// e pela gravacao formatada do arquivo de saida.

class GerenciadorArquivo {
public:
    
    // Le as palestras e o tempo disponivel no auditorio a partir do arquivo de entrada.
    // Lanca ArquivoException se o arquivo nao puder ser aberto.
    // Lanca EntradaInvalidaException se qualquer restricao de formato ou limite for violada.
     
    std::vector<Palestra> lerEntrada(const std::string& caminhoArquivo, int& tempoDisponivel) const;

    
    // Grava o resultado da melhor programacao no arquivo de saida.
    // Lanca ArquivoException se o arquivo de saida nao puder ser criado/aberto.

    void escreverSaida(const std::string& caminhoArquivo,int publicoTotal,int tempoTotal,
                       const std::vector<std::string>& palestrasEscolhidas,int nosCriados) const;
};

#endif