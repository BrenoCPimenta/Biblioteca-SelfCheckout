#include "../../include/excecoes/ExcecaoArquivos.hpp"

const char* ExcecaoAberturaDeArquivo::what() const throw()
{
    return "\n\nHouve um problema com a abertura do seu registro\nPor favor contactar o suporte";
}

const char* ExcecaoFechamentoDeArquivo::what() const throw()
{
    return "\n\nHouve um problema com o acesso do seu registro\nPor favor contactar o suporte";
}

const char* ExcecaoEntradaDeArquivo::what() const throw()
{
    return "\n\nHouve um problema com o conteudo do seu registro\nPor favor contactar o suporte";
}
