#include "../../include/menu/Menu.hpp"

bool Menu::cabecalho()
{
    std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
    std::cout << "---------------------------------------------------------------------------" <<std::endl;
    std::cout << "PROGRAMACAO E DESENVOLVIMENTO DE SOFTWARE II - SISTEMA PARA BIBLIOTECA" << std::endl;
    std::cout << "---------------------------------------------------------------------------" <<std::endl;
    return true;
}

bool Menu::textoLogin()
{
    std::cout << "Opcoes: Digite um valor." << std::endl;
    std::cout << "  Login: L" << std::endl;
    std::cout << "  Cadastramento: C" << std::endl;
    std::cout << "  Sair do sistema: S" << std::endl;
    return true;
}

bool Menu::textoMenu()
{
    std::cout << "BIBLIOTECA" << std::endl;
    std::cout << "Opcoes: Digite um valor." << std::endl;
    std::cout << "  Buscar livro e emprestimo: B" << std::endl;
    std::cout << "  Verificar livros emprestados e devolucoes: V" << std::endl;
    std::cout << "  Sair: S" << std::endl;
    return true;
}

bool Menu::textoBusca()
{
    std::cout << "BUSCAR LIVRO!" << std::endl;
    std::cout << "ATENCAO!!! \nNAO UTILIZE CARACTERES ESPECIAIS OU LETRAS MAIUSCULAS! FACA REFERENCIA APENAS AO TITULO DO LIVRO!" << std::endl;
    std::cout << "Digite sua busca: ";
    return true;
}

bool Menu::textoTeclaErrada()
{
    std::cout << "POR FAVOR, DIGITE ALGUM VALOR VALIDO" << std::endl;
    return true;
}

bool Menu::systemPause()
{
    std::string aux;
    std::cout<<"\nPressione enter para continuar";
    std::cin.ignore();
    std::cin.get();
    return true;
}
