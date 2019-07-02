#include "../../third_party/doctest.h"
#include "../../include/menu/Menu.hpp"


TEST_CASE("Teste Menu - Casos Base")
{
    Menu m;
    CHECK(m.cabecalho());
    CHECK(m.textoLogin());
    CHECK(m.textoMenu());
    CHECK(m.textoBusca());
    CHECK(m.textoTeclaErrada());
    CHECK(m.systemPause());
}