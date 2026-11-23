

int main(int argc, char* argv[]) {
    try {
        if (argc != 3) {
            throw std::invalid_argument(std::string("Uso: ") + argv[0] + " <palestras> <saida>");
        }
        // 1. Ler e validar arquivo argv[1]
        // 2. Construir árvore (força bruta na solucao1, backtracking na solucao2)
        // 3. Buscar melhor folha e gravar resultado no arquivo argv[2]
    } catch (const ArquivoException& e) {
        std::cerr << e.what() << std::endl;
        return 1;
    } catch (const EntradaInvalidaException& e) {
        std::cerr << e.what() << std::endl;
        return 1;
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }
    return 0;
}