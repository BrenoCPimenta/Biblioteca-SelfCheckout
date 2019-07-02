#include "../../third_party/doctest.h"
#include "../../include/busca/Busca.hpp"
#include "../../include/excecoes/ExcecaoBusca.hpp"


TEST_CASE("Teste Pessoa - Casos Base")
{
    Busca b;
    CHECK(b.incluirLivros());
    b.incluirLivros();
    b.buscarLivro("alienista");
    CHECK(b.getLivrosBusca()[0][0] == 'o');
}

TEST_CASE("Teste Pessoa - Casos de Excecoes")
{
    Busca b1;
    CHECK_THROWS_AS(b1.buscarLivro(""), ExcecaoLivrosNaoListados);
}
