#ifndef LOGIN_H
#define LOGIN_H

#include <iostream>
#include <string>
#include <fstream>

/** @brief Classe Login, compara a linha referente a senha no arquivo de autenticação e a senha digitada pelo usuário.
*/
class Login
{
private:
    std::string senhaArquivo;
    std::string usuarioArquivo;

public:
    std::string usuarioTentativa;
    std::string senhaTentativa;

    /** @param Pega o numero do cpf no arquivo de autenticação que serve como autenticador de usuário.
    	@return valor do cpf
    	@throw std::runtime_error "ACESSO NEGADO\nO usuario apresentado nao esta cadastrado\nPor favor tente novamente ou cadastre um novo usuario"

    */
    std::string getCpf();

    /** Compara a senha cadastrada, presente no arquivo autenticação, com a senha inserida pelo usuário.
    	@param senhaArquivo, armazena a informação contida no arquivo
    	@param senhaTentativa, é a senha inserida pelo usuário.
    	@return true se as senhas forem idênticas, false, se ao contrário.
    	@throw std::runtime_error "ACESSO NEGADO Por favor confira se digitou a senha corretamente"
    */
    bool autenticacao();
};

#endif
