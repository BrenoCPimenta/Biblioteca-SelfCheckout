#ifndef BUSCA_H
#define BUSCA_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <exception>
#include "../excecoes/ExcecaoBusca.hpp"

/** @brief Classe Busca é responsável por buscar os exemplares de Livros Cadastrados em um arquivo de texto e retornar o resultado na tela.
*/
class Busca
{
private:
    std::vector<std::string> livros, livros_busca;

public:
    /**@param Faz a leitura de um arquivo de texto com o acervo de livros e o armazena em um vetor de strings.
    	@return true caso o armazenamento dos livros no vetor tenha ocorrido com exito.
    	@throw std::runtime_error "Houve um problema com a abertura da listagem de livros\nPor favor contactar o suporte"
    	@throw std::runtime_error "Houve um problema com o fechamento da listagem de livros\nPor favor contactar o suporte"
    	@throw std::runtime_error "Houve um problema com a leitura da listagem de livros\nPor favor contactar o suporte"
    */
    bool incluirLivros();

    /** @param recebe uma string contendo o nome do livro desejado e procura em uma lista do acervo.
    	@throw std::runtime_error "Nao ha livros catalogados na biblioteca ou houve um erro na inclusao dos livros a partir do arquivo\nPor favor contactar o suporte"
    */
    void buscarLivro(std::string palavra_chave);

    /** @param Método buscarLivro.
    	@return Retorna na tela do usuário os resultados da busca realizada.
    */

    void printBusca();

    std::vector<std::string> getLivrosBusca();
};

#endif
