#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

#include <omp.h>

using namespace std;

//Função que realiza a escrita dos arquivos.csv
void write_csv(std::string filename, std::vector<vector<string>> content, int col){
    // Criar um CSV de uma determinada coluna
    // filename - o nome arquivo a ser criado
    // content - um vetor de vetor de string contento os dados
    
    // Cria o arquivo
    std::ofstream targetFile(filename);
    // Map para armazenamento dos códigos e seus respectivos dados
    std::unordered_map<std::string, int> uniquecontent;
    
    // Realiza o loop atribuindo o código para valores únicos
    // Lê a massa de dados discartando valores repetidos e rotulando novos valores
    for(long unsigned int i = 1; i < content.size(); i++)
    {
        //Verificar se o dado já foi encontrado
        if (uniquecontent.find(content[i][col]) != uniquecontent.end()) {
            continue;
        }
        //Caso não, adiciona no map com seu id
        else {
            uniquecontent.insert({content[i][col], uniquecontent.size()+1});
            targetFile << uniquecontent.size() << '\n';
        }
    }

    // Fecha o arquivo
    targetFile.close();
}

//Função que realiza a verificação se o elemento é dígito ou não
bool isNumber(const string& s)
{
    for (char const &ch : s) {
        if (std::isdigit(ch) == 0) 
            return false;
    }
    return true;
}

int main()
{
    //Nome do arquivo base
	string fname = "teste.csv";
    
    //Variáveis do sistema 
	vector<vector<string>> content;
	vector<string> row;
	string line, word;
    
    //Abertura e leitura dos dados
    fstream file (fname, ios::in);
    if(file.is_open())
    {
        while(getline(file, line))
        {
            row.clear();
    
            stringstream str(line);
    
            while(getline(str, word, ','))
                row.push_back(word);
            content.push_back(row);
        }
    }
    else{
        cout<<"Could not open the file\n";
    }

    file.close();

    // Verificando a presença de números na coluna,
    // realizando a chama da função para escrita dos CSV únicos.
    for(int col = 0; col < 3; col++)
    {
        if(isNumber(content[1][col]) == false){
            write_csv(content[0][col], content, col);
        }
    }
    return 0;
}