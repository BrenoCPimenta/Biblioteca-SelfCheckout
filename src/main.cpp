#include <iostream>
#include <string>
#include <vector>
#include <ctype.h>
#include "../include/busca/Busca.hpp"
#include "../include/login/Login.hpp"
#include "../include/cadastro/Cadastro.hpp"
#include "../include/cadastro/Senha.hpp"
#include "../include/menu/Menu.hpp"
#include "../include/gestao/Pessoa.hpp"
#include "../include/gestao/Usuario.hpp"
#include "../include/excecoes/ExcecaoArquivos.hpp"
#include "../include/excecoes/ExcecaoLogin.hpp"

int main()
{
    bool sair_login = false;
    bool sair_senha = false;
    bool sair_menu = false;
    char opcao;
    std::string cpf_usuario;
    Pessoa* user = nullptr;
    Menu menuObj;

    while(!sair_login)
    {
        menuObj.cabecalho();
        menuObj.textoLogin();

        std::cin>>opcao;
        if(isupper(opcao))
        {
            opcao = tolower(opcao);
        }
        switch(opcao)
        {
        case 'c':
        {
            menuObj.cabecalho();
            Cadastro cadastroObj;
            Senha senhaObj;
            try
            {
                cadastroObj.cadastrarPessoa();
            }
            catch(ExcecaoAberturaDeArquivo& e)
            {
                std::cout<<e.what()<<std::endl;
                menuObj.systemPause();
                break;
            }

            try
            {
                while(!senhaObj.cadastraSenha());
                menuObj.systemPause();
            }
            catch(ExcecaoAberturaDeArquivo& e)
            {
                std::cout<<e.what()<<std::endl;
                menuObj.systemPause();
                break;
            }
            break;
        }

        case 'l':
        {
            menuObj.cabecalho();
            Login loginObj;
            try
            {
                loginObj.autenticacao();
            }
            catch(ExcecaoAberturaDeArquivo& e)
            {
                std::cout<<e.what()<<std::endl;
                menuObj.systemPause();
                break;
            }
            catch(ExcecaoUsuarioNaoCadastrado& e)
            {
                std::cout<<e.what()<<std::endl;
                menuObj.systemPause();
                break;
            }
            catch(ExcecaoAcesso& e)
            {
                std::cout<<e.what()<<std::endl;
                menuObj.systemPause();
                break;
            }

            sair_login = true;
            cpf_usuario = loginObj.getCpf();
            user = new Usuario(cpf_usuario);

            try
            {
                user->buscarDados();
            }
            catch(ExcecaoAberturaDeArquivo& e)
            {
                sair_login = false;
                delete user;
                std::cout<<e.what()<<std::endl;
                menuObj.systemPause();
            }
            catch(ExcecaoAberturaDeArquivo& e)
            {
                sair_login = false;
                delete user;
                std::cout<<e.what()<<std::endl;
                menuObj.systemPause();
            }
            catch(ExcecaoFechamentoDeArquivo& e)
            {
                sair_login = false;
                delete user;
                std::cout<<e.what()<<std::endl;
                menuObj.systemPause();
            }
            break;
        }

        case 's':
        {
            return 0;
        }

        default:
        {
            menuObj.textoTeclaErrada();
            menuObj.systemPause();

        }
        }

    }
//--------------------------------------------------------------------
    while(!sair_menu)
    {
        menuObj.cabecalho();
        menuObj.textoMenu();

        std::cin >> opcao;
        if(isupper(opcao))
        {
            opcao = tolower(opcao);
        }
        switch(opcao)
        {
        case 'b':
        {
            menuObj.cabecalho();
            menuObj.textoBusca();
            std::string texto_busca;
            std::cin>> texto_busca;

            Busca buscaObj;
            buscaObj.incluirLivros();
            buscaObj.buscarLivro(texto_busca);
            buscaObj.printBusca();
            std::cout << "\n\nDESEJA PEGAR ALGUM DOS EXEMPLARES ENCOTRADOS EMPRESTADO? SIM (S)";
            std::cout << "ou NAO (N)" << std::endl;

            std::cin >> opcao;
            opcao = tolower(opcao);
            if( opcao == 's' )
            {
                std::cout << "\n\nDIGITE O NUMERO DO EXEMPLAR A SER EMPRESTADO: ";
                int n;
                std::cin >> n;
                user->pegarLivroEmprestado(buscaObj.getLivrosBusca()[n-1]);
                break;
            }
            else if ( opcao == 'n' )
            {
                break;
            }
            else
            {
                menuObj.textoTeclaErrada();
                menuObj.systemPause();
                break;
            }
        }

        case 'v':
        {
            menuObj.cabecalho();
            if(!user->verificarSeHaLivrosEmprestado())
            {
                std::cout<<"VOCE NAO POSSUI NENHUM LIVRO EMPRESTADO NO MOMENTO"<<std::endl;
                menuObj.systemPause();
                break;
            }
            user->printLivrosEmprestados();
            std::vector<std::string> livros_emprestados = user->getLivros();
            std::cout << "\nDESEJA DEVOLVER ALGUM DOS EXEMPLARES? SIM (S) ou NAO (N)";

            std::cin>>opcao;
            opcao = tolower(opcao);
            if( opcao == 's' )
            {
                menuObj.cabecalho();
                user->printLivrosEmprestados();
                std::cout << "\nDIGITE O NUMERO DO EXEMPLAR A SER DEVOLVIDO: ";
                int n;
                std::cin >> n;
                try
                {
                    if(user->devolverLivro(livros_emprestados[n-1]))
                    {
                        std::cout<<"LIVRO DEVOLVIDO COM SUCESSO"<<std::endl;
                    }
                }
                catch(ExcecaoProblemaDevolucao& e)
                {
                    std::cout<<e.what()<<std::endl;
                    menuObj.systemPause();
                    break;
                }

                break;
            }
            else if ( opcao == 'n' )
            {
                break;
            }
            else
            {
                menuObj.textoTeclaErrada();
                menuObj.systemPause();
                break;
            }

        }

        case 's':
        {
            delete user;
            return 0;
        }

        default:
        {
            menuObj.textoTeclaErrada();
            menuObj.systemPause();
        }

        }
    }
}
