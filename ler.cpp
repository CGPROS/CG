#include <iostream>
#include <fstream>
#include <string>
#include "ler.h"
using namespace std;

int lerFicheiro(char* fich) {
	//declarar e abrir o ficheiro
	ifstream input_file(fich);

	if (!input_file) {
		//ocorreu um erro
		return -1;
	}

	string word, line;
	int i;

	//ler uma linha
	getline(input_file, line);
	//line fica com a string "uma frase!"

	//extrair uma palavra e um inteiro
	input_file >> word >> i;
	//word fica com a string "palavra" e i com o valor 1234

	printf("%s ++ %s %d", line, word, i);

	return 0;
}

