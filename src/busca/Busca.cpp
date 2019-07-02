#include "../../include/busca/Busca.hpp"
#include <iostream>


bool Busca::incluirLivros()
{
    std::fstream arquivo;
    arquivo.open("dados/livros/livros.txt");
    if(!arquivo)
    {
        throw ExcecaoAberturaDeArquivoLivros(); //Verificando se houve problemas na abertura do arquivo
        return 0;
    }

    std::string temp;
    while(getline(arquivo, temp))
    {
        if(temp == "")
        {
            throw ExcecaoLeituraDeArquivoLivros(); //Verificando dados lidos do arquivo
            return 0;
        }
        livros.push_back(temp);
    }

    arquivo.close();
    if(arquivo.is_open())
    {
        throw ExcecaoFechamentoDeArquivoLivros();	//Verificando se houve problemas no fechamento do arquivo
        return 0;
    }
    return 1;
}

void Busca::buscarLivro(std::string palavra_chave)
{
    if( livros.size() == 0 )
    {
        throw ExcecaoLivrosNaoListados(); //Verificando problemas na inclusao dos livros ou arquivo de livros vazio
    }

    std::vector<std::string>::iterator it;

    for( it = livros.begin() ; it != livros.end() ; it++ )
    {
        std::size_t encontrado = it->find(palavra_chave);
        if( encontrado != std::string::npos )
        {
            livros_busca.push_back(*it);
        }
    }
}

void Busca::printBusca()
{
    std::vector<std::string>::iterator it;

    std::cout << "RESULTADOS DA BUSCA:" << std::endl;

    if( livros_busca.size() == 0 )
    {
        std::cout << "Nenhum livro encontrado a partir da busca." << std::endl;
    }
    else
    {
        for( it = livros_busca.begin() ; it != livros_busca.end() ; it++ )
        {
            std::cout << "\t" << (1 + it - livros_busca.begin()) << " - " << *it << std::endl;
        }
    }
}

std::vector<std::string> Busca::getLivrosBusca()
{
    return this->livros_busca;
}
