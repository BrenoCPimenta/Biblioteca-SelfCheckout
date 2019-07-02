# PROJETO DE PDS - SISTEMA DE BIBLIOTECA

## Integrantes:
* Breno Pimenta
* Eduardo Paraíso
* Gustavo Santos
* Yuri Mol 

## Instalando e rodando:
1. deve ir até o diretório principal do projeto
2. compila usando o seguinte comando:
```bash
make
```
3. executa usando o seguinte comando: 
```bash
make run
```
4. (OPCIONAL) como boa pratica para limpar os arquivos compilados, pode-se usar:
```bash
make clean
```
## Documentação (pasta docs)
* Modelagem CRC
* User Stories
* Relatório
* Doxygen

## Banco de Dados (pasta dados)
* Livros, onde se localizam os livros
* Pessoas, onde se localizam os dados dos usuários registrados e seus dados
* Autenticação, onde se localizam as senhas e logins dos usuários registrados

## Outros:
* O Código está divido com os headers na pasta include e os demais na pasta src. 
* Testes se encontram na pasta tests.
* A cobertura está na pasta coverage e caso queira conferir a mesma, basta abrir o arquivo *index.html*.
* Os objetos, quando criados, se encontram na pasta build.
* As bibliotecas importadas se encontram na pasta third-party.
