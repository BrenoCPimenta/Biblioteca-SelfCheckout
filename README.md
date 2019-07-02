# SISTEMA DE BIBLIOTECA CHECKOUT
## Projeto final da disciplina Produção e Desenvolvimento de Software II - DCC/UFMG

### Projeto:
Sistema de biblioteca onde o usuário é responsável por buscar, escolher e devolver o livro, sem a necessidade de um mediador.

### Arquitetura:
Este projeto foi desenvolvido em C++ com foco nas melhores práticas.<br>
Possui testes unitários automatizados com cobertura de código, banco de dados (em arquivos, como exigido pela disciplina) e documetação usando modelagem CRC, UserStories, Doxygem, além de um relatório geral. <br>
Há um resumo da distribuição de arquivos mais abaixo neste texto, ou se preferir, para informações mais completas sobre a arquitetura do projeto pode-se acessar o relatório geral na pasta _'Docs'_.


---
## Instalando e rodando:
1. Deve-se ir até o diretório principal do projeto
2. Compila-se usando o seguinte comando:
```bash
make
```
3. Executa-se usando o seguinte comando: 
```bash
make run
```
4. (OPCIONAL) Como boa prática para limpar os arquivos compilados, pode-se usar:
```bash
make clean
```

---
## Resumo da distribuição dos arquivos:
### Documentação (pasta docs)
* Modelagem CRC
* User Stories
* Relatório
* Doxygen

### Banco de Dados (pasta dados)
* Livros, onde se localizam os livros
* Pessoas, onde se localizam os dados dos usuários registrados e seus dados
* Autenticação, onde se localizam as senhas e logins dos usuários registrados

### Outros:
* O Código está divido com os headers na pasta include e os demais na pasta src. 
* Testes se encontram na pasta tests.
* A cobertura está na pasta coverage e caso queira conferir a mesma, basta abrir o arquivo *index.html*.
* Os objetos, quando criados, se encontram na pasta build.
* As bibliotecas importadas se encontram na pasta third-party.

---
**Obs: Esse projeto foi desenvolvido em equipe, dentro do próprio GitHub, mas em um repositório privado, as informações de desenvolvimento deste repositório são apenas para a sua cópia.**

#### Integrantes:
* Breno Pimenta
* Eduardo Paraíso
* Gustavo Santos
