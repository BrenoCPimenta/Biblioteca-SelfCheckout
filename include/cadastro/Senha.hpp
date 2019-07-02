#ifndef SENHA_H
#define SENHA_H

#include "../excecoes/ExcecaoArquivos.hpp"

#include <iostream>
#include <string>
#include <fstream>

/** @brief Classe Senha é responsável pela dupla comparação das senhas no momento do cadastramento.
*/
class Senha
{
private:
    std::string _senha;
    std::string _contraSenha;

public:
    /** @param recebe a informação inserida pelo usuário.
    */
    void setSenha();

    /** @param recebe novamente a informação inseria pleo usuário, utilizada para confirmação através de comparação.
    */
    void setContraSenha();

    /** @param senha inserida
    	@param contra senha inserida
    	@return true caso a comparação seja idêntica e false em caso de divergências
    	@throw std::runtime_error "As senhas não conferem"
    */
    bool comparaSenha();

    /**@param resultado do método comparaSenha(). Em caso afirmativo, a senha é armazenada no arquivo autenticação.
    */
    bool cadastraSenha();
};

#endif
