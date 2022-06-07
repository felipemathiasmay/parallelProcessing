# parallelProcessing

O documento tem como finalidade a especificação do cenário envolvendo o processamento e tratamento dos dados de um arquivo CSV, o qual será usado a programação paralela utilizando a interface de programação OpenMP

## Cenário

Primeiramente iremos realizar a leitura da massa de dados extraindo assim os valores do dataset. Após termos lidos os dados, começa-se o processamento dos mesmos.
A lógica consiste em separar as colunas em arquivos.csv únicos, sendo nomeados com o título da coluna em questão, como por exemplo demonstrando na figura a seguir:

Colunas as quais apresentam somente dados numéricos não serão processadas pelo nosso sistema, pois como iremos realizar a rotulação dos dados, ou seja para cada elemento será atribuído um código de identificação para ele, sendo assim iremos nos referenciar a esse dados não mais por escrito, mas sim fazendo referência ao seu identificador. 

Após a separação em arquivos únicos e realizado a identificação dos elementos daquela coluna, iremos criar um novo arquivo final o qual iremos passar os ID's que foram atribuídos, tendo assim um banco de dados somente númerico.

## Integrantes
Felipe Mathias May,
Geovanna de Oliveira Névola
