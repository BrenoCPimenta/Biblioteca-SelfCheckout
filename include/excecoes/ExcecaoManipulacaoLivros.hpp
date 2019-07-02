#ifndef EXCECAO_MANIPULACAO_LIVROS_H
#define EXCECAO_MANIPULACAO_LIVROS_H

#include<exception>

/** @brief Classe ExcecaoMesmoLivro retorna um erro caso o usuário tente realizar um emprestimo duplicado.
*/
class ExcecaoMesmoLivro : public std::exception
{
public:
    /**@throw std::runtime_error "O usuario ja esta com esse livro emprestado"
    */
    virtual const char* what() const throw();

};

/** @brief Classe ExcecaoProblemaDevolucao retorna um erro caso ocorra algum problema com a devolução do livro.
*/
class ExcecaoProblemaDevolucao : public std::exception
{
public:
    /**@throw std::runtime_error "Houve um problema com a devolucao do Livro".
    */
    virtual const char* what() const throw();
};

#endif

