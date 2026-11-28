#ifndef EXCECOES_HPP
#define EXCECOES_HPP

#include <stdexcept>
#include <string>

// Excecao lancada quando ocorre falha ao abrir ou acessar um arquivo.
class ArquivoException : public std::runtime_error {
public:
    explicit ArquivoException(const std::string& caminhoArquivo);
};

// Excecao lancada quando o conteudo do arquivo viola regras ou limites da entrada.
class EntradaInvalidaException : public std::runtime_error {
public:
    explicit EntradaInvalidaException(const std::string& mensagem = "Entrada invalida.");
};

#endif