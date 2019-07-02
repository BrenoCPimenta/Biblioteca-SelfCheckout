#include "../../include/excecoes/ExcecaoManipulacaoLivros.hpp"

const char* ExcecaoMesmoLivro::what() const throw()
{
    return "O usuario ja esta com esse livro emprestado";
}

const char* ExcecaoProblemaDevolucao::what() const throw()
{
    return "Houve um problema com a devolucao do Livro";
}
