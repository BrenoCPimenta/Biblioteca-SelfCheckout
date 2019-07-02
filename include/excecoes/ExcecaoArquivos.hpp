#ifndef EXCECAO_ARQUIVOS_H
#define EXCECAO_ARQUIVOS_H

#include <exception>

/**@brief Classe ExcecaoAberturaDeArquivo retorna um erro caso ocorra um problema na abertura de um arquivo.
*/
class ExcecaoAberturaDeArquivo : public std::exception
{
public:
    /**@throw std::runtime_error "Houve um problema com a abertura do seu registro. Por favor contactar o suporte"
    */
    virtual const char* what() const throw();
};

/**@brief Classe ExcecaoFechamentoDeArquivo retorna um erro caso ocorra um problema no fechamento de um arquivo.
*/
class ExcecaoFechamentoDeArquivo : public std::exception
{
public:
    /**@throw std::runtime_error "Houve um problema com o acesso do seu registro\nPor favor contactar o suporte".
    */
    virtual const char* what() const throw();
};

/**@brief Classe ExcecaoEntradaDeArquivo retorna erro caso ocorra um problema na passagem das informações para um arquivo.
*/
class ExcecaoEntradaDeArquivo : public std::exception
{
public:
    /**@throw std::runtime_error "Houve um problema com o conteudo do seu registro.Por favor contactar o suporte".
    */
    virtual const char* what() const throw();
};


#endif
