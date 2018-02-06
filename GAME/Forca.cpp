#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

int main () {
	
	char palavra [30], letra, secreta[30];
	int tamanho=0,indice=0,chances=6,acertos=0;
	bool acerto = false;
	
	cout <<"======================== JOGO DA FORCA ==========================\n";
	cout << "Digite a palavra secreta em que seu amigo que ira jogar com voce observe\n";
	cout << ": ";
	cin >> palavra;
	
	system("cls");
	
    while (palavra[indice] != '\0') {
    	tamanho++;
    	indice++;
	}
	
	for(indice=0; indice < 30; indice++) {
		secreta[indice] = '-';
	}
	
	
	cout << "Palavra armazenada com sucesso!\n";
	printf("Palavras guardadas tem %d posicoes...\n", tamanho);
	

	
	
	
	return 0;
} 
