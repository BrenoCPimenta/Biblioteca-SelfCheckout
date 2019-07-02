CC=g++

CFLAGS=	-std=c++11	-g	-w

all:	main

TAD1=menu/Menu
TAD2=login/Login
TAD3=gestao/Pessoa
TAD4=gestao/Usuario
TAD5=cadastro/Cadastro
TAD6=cadastro/Senha
TAD7=busca/Busca

EXCE1=excecoes/ExcecaoArquivos
EXCE2=excecoes/ExcecaoLogin
EXCE3=excecoes/ExcecaoManipulacaoLivros
EXCE4=excecoes/ExcecaoBusca



OBJ=./build
SRC=./src
INC=./include


$(OBJ)/$(TAD1).o:	$(SRC)/$(TAD1).cpp	$(INC)/$(TAD1).hpp
	@$(CC)	$(CFLAGS) -I $(INC) -c $(SRC)/$(TAD1).cpp	-o	$(OBJ)/Menu.o

$(OBJ)/$(TAD2).o:	$(SRC)/$(TAD2).cpp	$(INC)/$(TAD2).hpp	$(SRC)/$(EXCE1).cpp	$(INC)/$(EXCE1).hpp	$(SRC)/$(EXCE2).cpp	$(INC)/$(EXCE2).hpp
	@$(CC)	$(CFLAGS) -I $(INC) -c $(SRC)/$(TAD2).cpp	-o	$(OBJ)/Login.o

$(OBJ)/$(TAD3).o:	$(SRC)/$(TAD3).cpp	$(INC)/$(TAD3).hpp	$(SRC)/$(EXCE1).cpp	$(INC)/$(EXCE1).hpp
	@$(CC)	$(CFLAGS) -I $(INC) -c $(SRC)/$(TAD3).cpp	-o	$(OBJ)/Pessoa.o

$(OBJ)/$(TAD4).o:	$(SRC)/$(TAD4).cpp	$(INC)/$(TAD4).hpp	$(SRC)/$(EXCE1).cpp	$(INC)/$(EXCE1).hpp	$(SRC)/$(EXCE3).cpp	$(INC)/$(EXCE3).hpp
	@$(CC)	$(CFLAGS) -I $(INC) -c $(SRC)/$(TAD4).cpp	-o	$(OBJ)/Usuario.o

$(OBJ)/$(TAD5).o:	$(SRC)/$(TAD5).cpp	$(INC)/$(TAD5).hpp
	@$(CC)	$(CFLAGS) -I $(INC) -c $(SRC)/$(TAD5).cpp	-o	$(OBJ)/Cadastro.o

$(OBJ)/$(TAD6).o:	$(SRC)/$(TAD6).cpp	$(INC)/$(TAD6).hpp
	@$(CC)	$(CFLAGS) -I $(INC) -c $(SRC)/$(TAD6).cpp	-o	$(OBJ)/Senha.o

$(OBJ)/$(TAD7).o:	$(SRC)/$(TAD7).cpp	$(INC)/$(TAD7).hpp	$(SRC)/$(EXCE1).cpp	$(INC)/$(EXCE1).hpp	$(SRC)/$(EXCE4).cpp	$(INC)/$(EXCE4).hpp
	@$(CC)	$(CFLAGS) -I $(INC) -c $(SRC)/$(TAD7).cpp	-o	$(OBJ)/Busca.o



$(OBJ)/$(EXCE1).o:	$(SRC)/$(EXCE1).cpp	$(INC)/$(EXCE1).hpp
	@$(CC)	$(CFLAGS) -I $(INC) -c $(SRC)/$(EXCE1).cpp	-o	$(OBJ)/ExcecaoArquivos.o

$(OBJ)/$(EXCE2).o:	$(SRC)/$(EXCE2).cpp	$(INC)/$(EXCE2).hpp
	@$(CC)	$(CFLAGS) -I $(INC) -c $(SRC)/$(EXCE2).cpp	-o	$(OBJ)/ExcecaoLogin.o

$(OBJ)/$(EXCE3).o:	$(SRC)/$(EXCE3).cpp	$(INC)/$(EXCE3).hpp
	@$(CC)	$(CFLAGS) -I $(INC) -c $(SRC)/$(EXCE3).cpp	-o	$(OBJ)/ExcecaoManipulacaoLivros.o

$(OBJ)/$(EXCE4).o:	$(SRC)/$(EXCE4).cpp	$(INC)/$(EXCE4).hpp
	@$(CC)	$(CFLAGS) -I $(INC) -c $(SRC)/$(EXCE4).cpp	-o	$(OBJ)/ExcecaoExcecaoBusca.o


$(OBJ)/main.o:	$(SRC)/main.cpp $(INC)/$(TAD1).hpp $(INC)/$(TAD2).hpp $(INC)/$(TAD3).hpp	$(INC)/$(TAD4).hpp	$(INC)/$(TAD5).hpp	$(INC)/$(TAD6).hpp	$(INC)/$(TAD7).hpp	$(INC)/$(EXCE1).hpp	$(INC)/$(EXCE2).hpp	$(INC)/$(EXCE3).hpp	$(INC)/$(EXCE4).hpp 
	@$(CC)	$(CFLAGS) -I $(INC) -c $(SRC)/main.cpp -o $(OBJ)/main.o

main:	$(OBJ)/main.o $(OBJ)/$(TAD1).o $(OBJ)/$(TAD2).o $(OBJ)/$(TAD3).o $(OBJ)/$(TAD4).o  $(OBJ)/$(TAD5).o	$(OBJ)/$(TAD6).o	$(OBJ)/$(TAD7).o $(OBJ)/$(EXCE1).o	$(OBJ)/$(EXCE2).o	$(OBJ)/$(EXCE3).o	$(OBJ)/$(EXCE4).o
	@$(CC)	$(CFLAGS) $(OBJ)/*.o -o ./system_biblioteca

run:	main
	./system_biblioteca

clean: 
	@rm	-f	$(OBJ)/*.o










