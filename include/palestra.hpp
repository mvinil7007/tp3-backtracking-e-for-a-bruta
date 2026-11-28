#ifndef PALESTRA_HPP
#define PALESTRA_HPP

#include <string>

class Palestra {
private:
    std::string _nome;
    int _duracao;
    int _publico;

public:
    Palestra(const std::string& nome = "", int duracao = 0, int publico = 0);

    const std::string& getNome() const;
    int getDuracao() const;
    int getPublico() const;
};

#endif