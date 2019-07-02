#ifndef USUARIO_H
#define USUARIO_H

#include "Pessoa.hpp"
#include "../excecoes/ExcecaoManipulacaoLivros.hpp"


class Usuario : public Pessoa
{
private:
    std::vector<std::string> _livros;

public:
    Usuario(std::string);

    bool verificarSeHaLivrosEmprestado() override;
    bool verificarLivroEspecifico(std::string) override;
    bool pegarLivroEmprestado(std::string) override;
    bool devolverLivro(std::string) override;
    bool printLivrosEmprestados() override;
    std::vector<std::string>  getLivros() override;
};
#endif
