#include "../../include/cadastro/Senha.hpp"
#include "../../include/excecoes/ExcecaoArquivos.hpp"

void Senha::setSenha()
{
    std::string senha;
    std::cin >> senha;
    this-> _senha = senha;
}

void Senha::setContraSenha()
{
    std::string cs;
    std::cin >> cs;
    this ->_contraSenha = cs;
}

bool Senha::comparaSenha()
{
    if(this->_senha == this->_contraSenha)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Senha::cadastraSenha()
{
    std::cout << "SENHA: ";
    setSenha();

    std::cout << "NOVAMENTE: ";
    setContraSenha();

    if(comparaSenha()==true)
    {
        std::ofstream autenticacao;
        if(this->comparaSenha())
        {
            std::ofstream autenticacao;
            autenticacao.open("dados/autenticacao/autenticacao.txt", std::ios::app);
            if(!autenticacao.is_open())
            {
                throw ExcecaoAberturaDeArquivo();
            }

            std::cout << "CADASTRADO" <<std::endl;
            autenticacao << this->_senha <<std::endl;
            autenticacao.close();
            return true;
        }
    }
    else
    {
        std::cout << "ERRO! TENTE NOVAMENTE!" <<std::endl;
        return false;
    }
}
