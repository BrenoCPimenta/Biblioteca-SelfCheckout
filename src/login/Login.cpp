#include "../../include/login/Login.hpp"
#include "../../include/excecoes/ExcecaoArquivos.hpp"
#include "../../include/excecoes/ExcecaoLogin.hpp"



bool Login::autenticacao()
{
    std::ifstream arquivo;
    arquivo.open("dados/autenticacao/autenticacao.txt");
    if(!arquivo)
    {
        throw ExcecaoAberturaDeArquivo();
    }

    std::cout << "INSIRA SEU USUARIO (CPF): ";
    std::cin >> usuarioTentativa;

    while(!arquivo.eof())
    {
        getline(arquivo, this -> usuarioArquivo);
        if(this ->usuarioArquivo == usuarioTentativa)
        {
            std::cout << "INSIRA SUA SENHA: ";
            std::cin >> senhaTentativa;

            getline(arquivo, this -> senhaArquivo);
            if(this -> senhaArquivo != senhaTentativa)
            {
                throw ExcecaoAcesso();
            }
            else
            {
                arquivo.close();
                return true;
            }
        }
    }
    arquivo.close();
    throw ExcecaoUsuarioNaoCadastrado();
}


std::string Login::getCpf()
{
    return this->usuarioTentativa;
}
