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
    std::vector<string> uniquecontent;

    auto it = uniquecontent.insert(uniquecontent.begin(), content[1][col]);

    // Realiza o loop copiando os dados para o arquivo 
    #pragma omp parallel for
    for(long unsigned int i = 0; i < content.size(); i++)
    {
        //Especificar coluna dos códigos
        #pragma omp critical
        if(std::find(uniquecontent.begin(), uniquecontent.end(), content[i][col]) != uniquecontent.end()) {
            continue;
        } else {
            uniquecontent.insert(it, content[i][col]);
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
	string fname = "dataset_00_1000_sem_virg.csv";
    
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

    // Verificando a presença de números na coluna,
    // realizando a chama da função para escrita dos CSV únicos.
    for(int col = 0; col < 31; col++)
    {
        if(isNumber(content[1][col]) == false){
            write_csv(content[0][col], content, col);
        }
    }
    return 0;
}