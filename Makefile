CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -Iinclude

SRCS = src/Palestra.cpp src/ArvoreDecisao.cpp src/GerenciadorArquivo.cpp

all: solucao1 solucao2

solucao1: solucao1.cpp $(SRCS)
	$(CXX) $(CXXFLAGS) solucao1.cpp $(SRCS) -o solucao1

solucao2: solucao2.cpp $(SRCS)
	$(CXX) $(CXXFLAGS) solucao2.cpp $(SRCS) -o solucao2

clean:
	rm -f solucao1 solucao2