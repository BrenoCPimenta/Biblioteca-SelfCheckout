#include "../../include/excecoes/ExcecaoLogin.hpp"

const char* ExcecaoAcesso::what() const throw()
{
    return "\nACESSO NEGADO\nPor favor confira se digitou a senha corretamente";
}

const char* ExcecaoUsuarioNaoCadastrado::what() const throw()
{
    return "\nACESSO NEGADO\nO usuario apresentado nao esta cadastrado\nPor favor tente novamente ou cadastre um novo usuario";
}
