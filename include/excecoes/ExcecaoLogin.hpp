#ifndef EXCECAO_LOGIN_H
#define EXCECAO_LOGIN_H

#include <exception>

/**@brief A classe ExcecaoAcesso retorna um erro caso a senha inserida pelo usuário não seja igual a senha a cadastrada.
*/
class ExcecaoAcesso : public std::exception
{
public:
    /**@throw std::runtime_error "ACESSO NEGADO. Por favor confira se digitou a senha corretamente"
    */
    virtual const char* what() const throw();
};

/** @brief A clase ExcecaoUsuarioNaoCadastrado retorna um erro caso o usuario inserido não esteja presente no arquivo de autenticação.
*/
class ExcecaoUsuarioNaoCadastrado : public std::exception
{
public:
    /**@throw std::runtime_error "ACESSO NEGADO. O usuario apresentado nao esta cadastrado. Por favor tente novamente ou cadastre um novo usuario"
    */
    virtual const char* what() const throw();
};

#endif
