#include "palestra.hpp"

Palestra::Palestra(const std::string& nome, int duracao, int publico)
    : _nome(nome), _duracao(duracao), _publico(publico) {}

const std::string& Palestra::getNome() const {
    return _nome;
}

int Palestra::getDuracao() const {
    return _duracao;
}

int Palestra::getPublico() const {
    return _publico;
}