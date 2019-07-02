#ifndef EXCECAO_BUSCA_H
#define EXCECAO_BUSCA_H

#include <exception>

/**@brief ExcecaoLivrosNaoListados retorna erro caso o usuário busque por um livro que não esteja cadastrado no acervo.
*/
class ExcecaoLivrosNaoListados : public std::exception
{
public:
    /**@throw std::runtime_error "Nao ha livros catalogados na biblioteca ou houve um erro na inclusao dos livros a partir do arquivo. Por favor contactar o suporte".
    */
    virtual const char* what() const throw();
};

/**@brief ExcecaoAberturaDeArquivoLivros retorna erro caso ocorra algum problema na listagem de livros.
*/
class ExcecaoAberturaDeArquivoLivros : public std::exception
{
public:
    /**@throw std::runtime_error "Houve um problema com a abertura da listagem de livros\nPor favor contactar o suporte"
    */
    virtual const char* what() const throw();
};

/**@brief ExcecaoFechamentoDeArquivoLivros retorna erro caso ocorrra algum problema no fechamento da lista de livros.
*/
class ExcecaoFechamentoDeArquivoLivros : public std::exception
{
public:
    /**@throw std::runtime_error "Houve um problema com o fechamento da listagem de livros\nPor favor contactar o suporte"
    */
    virtual const char* what() const throw();
};

/**@brief ExcecaoLeituraDeArquivoLivros retorna erro casso ocorra erro na leitura do arquivo de listagem de livros.
*/
class ExcecaoLeituraDeArquivoLivros : public std::exception
{
public:
    /**@throw std::runtime_error "Houve um problema com a leitura da listagem de livros\nPor favor contactar o suporte"
    */
    virtual const char* what() const throw();
};

#endif
