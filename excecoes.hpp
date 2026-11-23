#include <stdexcept>
#include <string>

class ArquivoException : public std::runtime_error {
public:
    ArquivoException(const std::string& nome_arquivo)
        : std::runtime_error("Erro: nao foi possivel abrir o arquivo " + nome_arquivo) {}
};

class EntradaInvalidaException : public std::runtime_error {
public:
    EntradaInvalidaException()
        : std::runtime_error("Erro: arquivo de entrada invalido") {}
};