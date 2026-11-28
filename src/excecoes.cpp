#include "excecoes.hpp"

ArquivoException::ArquivoException(const std::string& caminhoArquivo)
    : std::runtime_error("Erro: nao foi possivel abrir o arquivo " + caminhoArquivo) {
}

EntradaInvalidaException::EntradaInvalidaException(const std::string& mensagem)
    : std::runtime_error(mensagem.empty() ? "Erro: arquivo de entrada invalido" : mensagem) {
}