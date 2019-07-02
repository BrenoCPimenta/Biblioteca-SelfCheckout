#ifndef MENU_H
#define MENU_H

#include <iostream>

/** A classe Menu possui métodos exclusivamente dedicados à impressão de informações na tela do usuário.
*/
class Menu
{
public:
    /** Imprime o cabeçalho do sistema.
    	@return texto contendo o cabeçalho do sistema.
    */
    bool cabecalho();

    /** Imprime textos referente as opção de login.
    	@return texto de comando para login, cadastramente e saída.
    */
    bool textoLogin();

    /** Imprime texto referente as opção de emprestimo.
    	@return texto de compando para busca, emprestimo/devolução e saída.
    */
    bool textoMenu();

    /** Imprime texto referente a busca.
    	@return informações necessárias para realização das buscas.
    */
    bool textoBusca();

    /** Imprime aviso de digitação inválida.
    	@return Informação para concientização do usuário.
    */
    bool textoTeclaErrada();

    /** Tem função de parar o programa até que alguma tecla seja pressionada.
    	@param Qualquer tecla pode ser pressionada
    	@return Fim do metódo e continuação no fluxo do sistema.
    */
    bool systemPause();
};

#endif
