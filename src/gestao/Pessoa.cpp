#include "../../include/gestao/Pessoa.hpp"

Pessoa::Pessoa(std::string cpf):_cpf(cpf) {}

bool Pessoa::buscarDados()
{
    std::ifstream arquivo;
    std::string nome_arquivo;
    std::string linha_arquivo;
    std::vector<std::string> linhas_arquivo;


    //Abrindo arquivo
    nome_arquivo = "dados/pessoas/" + this->_cpf + ".txt";
    arquivo.open(nome_arquivo, std::ifstream::in);

    if(!arquivo.is_open())
    {
        throw ExcecaoAberturaDeArquivo(); //Verificando se houve ṕoblemas na abertura do arquivo
    }

    //Lendo arquivo
    for(int i=0; i<4; i++)
    {
        getline(arquivo, linha_arquivo);

        if(linha_arquivo == "")
        {
            throw ExcecaoEntradaDeArquivo(); //Verificando dados lidos do arquivo
        }
        linhas_arquivo.push_back(linha_arquivo);
    }
    this->_nome = linhas_arquivo[0];
    this->_endereco = linhas_arquivo[1];
    this->_contato = linhas_arquivo[2];

    //Fechando arquivo e verificando se houve erros
    arquivo.close();
    if(arquivo.is_open())
    {
        throw ExcecaoFechamentoDeArquivo();
    }
    return true;
}
Pessoa::~Pessoa() {}


std::string Pessoa::getNome()
{
    return this->_nome;
}

std::string Pessoa::getCpf()
{
    return this->_cpf;
}

std::string Pessoa::getEndereco()
{
    return this->_endereco;
}

std::string Pessoa::getContato()
{
    return this->_contato;
}
