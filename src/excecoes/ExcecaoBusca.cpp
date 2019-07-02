#include "../../include/excecoes/ExcecaoBusca.hpp"

const char* ExcecaoLivrosNaoListados::what() const throw()
{
    return "Nao ha livros catalogados na biblioteca ou houve um erro na inclusao dos livros a partir do arquivo\nPor favor contactar o suporte";
}

const char* ExcecaoAberturaDeArquivoLivros::what() const throw()
{
    return "Houve um problema com a abertura da listagem de livros\nPor favor contactar o suporte";
}

const char* ExcecaoFechamentoDeArquivoLivros::what() const throw()
{
    return "Houve um problema com o fechamento da listagem de livros\nPor favor contactar o suporte";
}

const char* ExcecaoLeituraDeArquivoLivros::what() const throw()
{
    return "Houve um problema com a leitura da listagem de livros\nPor favor contactar o suporte";
}
