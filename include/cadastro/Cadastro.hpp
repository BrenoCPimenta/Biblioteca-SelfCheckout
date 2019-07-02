#ifndef CADASTRO_H
#define CADASTRO_H

#include "../excecoes/ExcecaoArquivos.hpp"

#include <iostream>
#include <string>
#include <fstream>

/** @brief Classe Cadastro, tem a função de imprimir comandos em tela para o usuário e coletar as informações basicas para cadastramento do usuário.
*/
class Cadastro
{
private:
    std::string _nome;
    std::string _cpf;
    std::string _endereco;
    std::string _contato;

public:

    /**@param recebe o nome inserido pelo usuário.
    @throw std::runtime_error "Houve um problema com o nome inserido".
    */
    bool setNome();

    /**@param recebe o cpf inserido pelo usuário.
    @throw std::runtime_error "Houve um problema com o CPF inserido".
    */
    bool setCpf();

    /**@param recebe o endereço inserido pelo usuário.
    @throw std::runtime_error "Houve um problema com o endereco do usuario".
    */
    bool setEndereco();

    /**@param recebe o contato inserido pelo usuário.
    @throw std::runtime_error "Houve um problema com o contato do usuario".
    */
    bool setContato();

    /**@param nome.
    @param cpf.
    @param endereço
    @param contato
    @return true caso o cadastro tenha sido bem sucedido, caso contrário, retornará false.
    @throw std::runtime_error "Houve um problema com o cadastramento do usuario".
    */
    bool cadastrarPessoa();
};

#endif
