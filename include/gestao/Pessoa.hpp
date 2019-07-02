#ifndef PESSOA_H
#define PESSOA_H

#include "../excecoes/ExcecaoArquivos.hpp"

#include <iostream>
#include <string>
#include <fstream>
#include <vector>

/** @brief A classe Pessoa é uma classe abstrata.
*/
class Pessoa
{
private:
    std::string _nome;
    std::string _cpf;
    std::string _endereco;
    std::string _contato;

public:
    /**Construtor simples.
    @param recebe o cpf e setar o atributo da classe.
    @return @Pessoa
    @throw
    */
    Pessoa(std::string cpf);

    /** O destrutor deve ser virtual uma vez que a classe é abstrata e haverá substituição de Liskov em Usuario.
    */
    virtual ~Pessoa();

    /** Seta todos os atributos com as informações contidas em arquivo. O tipo booleano é para que fosse possivel atender aos testes.
    	@param nome
    	@param cpf
    	@param endereço
    	@param contato
    	@throw std::runtime_error "Houve um problema com a abertura do seu registro\nPor favor contactar o suporte"
    	@throw std::runtime_error "Houve um problema com o conteudo do seu registro\nPor favor contactar o suporte"
    */
    bool buscarDados();


    /** Seta o atributo nome atraves das informções contidas em arquivo.
    	@param nome no arquivo
    	@return retorna o nome no atributo privado _nome.
    */
    std::string getNome();

    /** Seta o atributo cpf atraves das informções contidas em arquivo.
    	@param cpf no arquivo
    	@return retorna o cpf no atributo privado _cpf.
    */
    std::string getCpf();

    /** Seta o atributo endereço atraves das informções contidas em arquivo.
    	@param endereço no arquivo
    	@return retorna o endereço no atributo privado _endereco.
    */
    std::string getEndereco();

    /** Seta o atributo contato atraves das informções contidas em arquivo.
    	@param contato no arquivo
    	@return retorna o contato no atributo privado _contato.
    */
    std::string getContato();

    /**Método Virtual Puro
    	@param cpf do usuario e verifica se o mesmo possui algum emprestimo
    	@return true se existir emprestimo e false caso negativo
    */
    virtual bool verificarSeHaLivrosEmprestado() = 0;

    /**Método Virtual Puro
    	@param Possui uma string como parametro, no caso, o nome do livro
    	@return Retorna true caso consigo colocar emprestar um livro e falso caso contrário.
    */
    virtual bool pegarLivroEmprestado(std::string) = 0;

    /**Método Virtual Puro
    	@param Possui uma string como parametro, no caso, o nome do livro
    	@return Retorna true caso consigo devolver um livro e falso caso contrário.
    */
    virtual bool devolverLivro(std::string) = 0;

    /**Método Virtual Puro
    	@return Retorna na tela todos os livros em posse do usuário, caso o usuario deseje devolver algum livro, este livro será passado
    	como parametro no metodo devolverLivro.
    */
    virtual bool printLivrosEmprestados() = 0;

    /**@return um vetor de string que ordena e enumera os livros emprestados para passagem de parametros em outro métodos descritos anteriormente.
    */
    virtual std::vector<std::string> getLivros() = 0;

    /**Método Virtual Puro
    	@param Possui uma string como parametro, no caso, o nome do livro
    	@return Retorna true caso o livro passado esteja emprestado para a pessoa que chamou o metodo e falso caso contrario.
    */
    virtual bool verificarLivroEspecifico(std::string) = 0;
};
#endif
