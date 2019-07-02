#include "../../include/cadastro/Cadastro.hpp"

bool Cadastro::setNome()
{
    std::string nome;
    getline(std::cin, nome);
    this->_nome = nome;
    return true;
}

bool Cadastro::setCpf()
{
    std::string cpf;
    getline(std::cin, cpf);
    this->_cpf = cpf;
    return true;
}

bool Cadastro::setEndereco()
{
    std::string endereco;
    getline(std::cin, endereco);
    this->_endereco = endereco;
    return true;
}

bool Cadastro::setContato()
{
    std::string contato;
    getline(std::cin, contato);
    this->_contato=contato;
    return true;
}


bool Cadastro::cadastrarPessoa()
{
    std::cout << "CADASTRO DE USUARIO!!" << std::endl;
    std::cout << "NOME: ";
    std::cin.ignore();
    setNome();

    std::cout << "CPF: ";
    setCpf();

    std::cout << "ENDERECO: ";
    setEndereco();

    std::cout << "CONTATO: ";
    setContato();

    std::ofstream autenticacao;
    std::ofstream cadastro;

    autenticacao.open("dados/autenticacao/autenticacao.txt", std::ios::app);
    std::string aux = "dados/pessoas/" + this->_cpf + ".txt";
    cadastro.open(aux.c_str());

    if(!autenticacao.is_open() || !cadastro.is_open())
    {
        throw ExcecaoAberturaDeArquivo();
    }

    cadastro << this->_nome << std::endl;
    autenticacao << this->_cpf << std::endl;
    cadastro << this->_endereco << std::endl;
    cadastro << this->_contato << std::endl;
    cadastro << "[LIVROS]" << std::endl;
    cadastro << "[/LIVROS]";

    cadastro.close();
    autenticacao.close();
    return true;
}

