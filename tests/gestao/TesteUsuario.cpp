#include "../../third_party/doctest.h"
#include "../../include/gestao/Usuario.hpp"
#include "../../include/excecoes/ExcecaoArquivos.hpp"
#include "../../include/excecoes/ExcecaoManipulacaoLivros.hpp"


TEST_CASE("Teste Usuario - verificarSeHaLivrosEmprestado")
{
    Pessoa* u1= new Usuario("59902427600");
    CHECK( ! u1->verificarSeHaLivrosEmprestado());
    CHECK( ! u1->printLivrosEmprestados());
    delete u1;

    Pessoa* u2= new Usuario("89793922656");
    CHECK(u2->pegarLivroEmprestado("Politica e educacao - Paulo Freire"));
    CHECK(u2->verificarLivroEspecifico("Politica e educacao - Paulo Freire"));
    CHECK(u2->verificarSeHaLivrosEmprestado());
    CHECK(u2->printLivrosEmprestados());
    CHECK(u2->getLivros()[0] == "Politica e educacao - Paulo Freire");
    CHECK(u2->devolverLivro("Politica e educacao - Paulo Freire"));

    delete u2;
}


TEST_CASE("Teste Usuario - verificarSeHaLivrosEmprestado Excecoes")
{
    Pessoa* p1 = new Usuario("11111111111");
    CHECK_THROWS_AS(p1->verificarSeHaLivrosEmprestado(), ExcecaoAberturaDeArquivo);
    delete p1;

    Pessoa* p2 = new Usuario("111");
    CHECK_THROWS_AS(p2->verificarSeHaLivrosEmprestado(), ExcecaoEntradaDeArquivo);
    delete p2;


    Pessoa* u2= new Usuario("89793922656");
    u2->pegarLivroEmprestado("Politica e educacao - Paulo Freire");
    CHECK_THROWS_AS(u2->pegarLivroEmprestado("Politica e educacao - Paulo Freire"), ExcecaoMesmoLivro);
    CHECK_THROWS_AS(u2->devolverLivro("Nao existente"), ExcecaoProblemaDevolucao);
    u2->devolverLivro("Politica e educacao - Paulo Freire");
    delete u2;


}
