#include "../../include/gestao/Usuario.hpp"

Usuario::Usuario(std::string cpf):Pessoa(cpf) {}

bool Usuario::verificarSeHaLivrosEmprestado()
{
    std::string cpf = this->getCpf();
    std::ifstream arquivo;
    std::string nome_arquivo;
    std::string linha_arquivo;

    nome_arquivo = "dados/pessoas/"+cpf+".txt";
    arquivo.open(nome_arquivo, std::ifstream::in);

    if(!arquivo.is_open())
    {
        throw ExcecaoAberturaDeArquivo(); //Verificando se houve ṕoblemas na abertura do arquivo
    }

    //Lendo arquivo
    while(std::getline(arquivo, linha_arquivo))
    {
        if(linha_arquivo.find("[LIVROS]") != std::string::npos)
        {
            std::getline(arquivo, linha_arquivo);
            if(linha_arquivo=="[/LIVROS]")
            {
                return false; 	//Nao ha livros emprestados com esse usuario
            }
            else
            {
                return true; 	//Ha livros emprestado com esse usuario
            }
        }
    }
    throw ExcecaoEntradaDeArquivo();	//Caso nao encontre as chaves acima ha um problema com o arquivo
}


bool Usuario::verificarLivroEspecifico(std::string nome_livro)
{
    std::string cpf = this->getCpf();
    std::ifstream arquivo;
    std::string nome_arquivo;
    std::string linha_arquivo;

    nome_arquivo = "dados/pessoas/"+cpf+".txt";
    arquivo.open(nome_arquivo, std::ifstream::in);

    //Lendo arquivo
    while(std::getline(arquivo, linha_arquivo))
    {
        if(linha_arquivo == nome_livro)
        {
            return true;
        }
    }
    arquivo.close();
    return false;
}

bool Usuario::pegarLivroEmprestado(std::string nome_livro)
{
    std::string livros_key = "[/LIVROS]";
    std::string nome_arquivo;
    std::ifstream arquivo_inicial;
    std::ofstream arquivo_final;
    std::string linha;

    std::string cpf = this->getCpf();
    nome_arquivo = "dados/pessoas/"+cpf+".txt";

    arquivo_inicial.open(nome_arquivo);
    arquivo_final.open("dados/pessoas/temp.txt");

    while (getline(arquivo_inicial,linha))
    {
        //Caso ja tenha esse livro emprestado
        if(linha == nome_livro)
        {
            arquivo_final.close();
            arquivo_inicial.close();
            remove("dados/pessoas/temp.txt");
            throw ExcecaoMesmoLivro();
            //Adicionando livro ao banco
        }
        else if(linha == livros_key)
        {
            arquivo_final<<nome_livro<<std::endl;
            arquivo_final<<livros_key<<std::endl;
            //Transcrevendo arquivo
        }
        else
        {
            arquivo_final<< linha<< std::endl;
        }
    }
    arquivo_final.close();
    arquivo_inicial.close();
    remove(nome_arquivo.c_str());
    rename("dados/pessoas/temp.txt", nome_arquivo.c_str());
    return true;
}



bool Usuario::devolverLivro(std::string nome_livro)
{
    if(! this->verificarLivroEspecifico(nome_livro))
    {
        throw ExcecaoProblemaDevolucao();
    }
    std::ifstream arquivo_inicial;
    std::ofstream arquivo_final;
    std::string linha;
    std::string nome_arquivo;


    std::string cpf = this->getCpf();
    nome_arquivo = "dados/pessoas/"+cpf+".txt";

    arquivo_inicial.open(nome_arquivo);
    arquivo_final.open("dados/pessoas/temp.txt");

    while (getline(arquivo_inicial,linha))
    {
        if(linha != nome_livro)
        {
            arquivo_final<< linha<< std::endl;
        }

    }
    arquivo_final.close();
    arquivo_inicial.close();
    remove(nome_arquivo.c_str());
    rename("dados/pessoas/temp.txt", nome_arquivo.c_str());
    return true;
}

bool Usuario::printLivrosEmprestados()
{
    if(! this->verificarSeHaLivrosEmprestado())
    {
        return false;
    }
    std::string cpf = this->getCpf();
    std::ifstream arquivo;
    std::string nome_arquivo;
    std::string linha_arquivo;
    std::vector<std::string> livros;

    nome_arquivo = "dados/pessoas/"+cpf+".txt";
    arquivo.open(nome_arquivo, std::ifstream::in);

    std::cout << "LIVROS EMPRESTADOS:" << std::endl;
    int aux = 0;
    //Lendo arquivo
    while(std::getline(arquivo, linha_arquivo))
    {
        if(linha_arquivo == "[/LIVROS]")
        {
            this->_livros = livros;
            arquivo.close();
            return true;
        }
        else if(aux!=0)
        {
            std::cout<<aux<<" - "<<linha_arquivo<<std::endl;
            livros.push_back(linha_arquivo);
            aux++;
        }
        else if(linha_arquivo == "[LIVROS]")
        {
            aux++;
        }
    }
    arquivo.close();
    return false;//throw exception;
}

std::vector<std::string> Usuario::getLivros()
{
    return this->_livros;
}
