#include <iostream>
#include <stdlib.h> 
 

using namespace std;

int tamanholista = 10;
int lista[] = {3, 6, 1, 2, 9, 5, 4, 10, 7, 8};

int menor, aux;

void imprimirLista(){
	cout << "lista = {";
	for (int i = 0; i < tamanholista; i++) {
		cout << lista[i];
		if (i != tamanholista- 1){
			cout << ", ";
		}
	}
	cout << "}\n";
}

void selectSort() {
	for (int i = 0; i < tamanholista-1; i++){
		menor = i;
		for (int j = i + 1; j < tamanholista; j++){
			if (lista[menor] > lista[j]){
				menor = j;
			}
		}
		if (i != menor)	{
			aux=lista[i];
			lista[i] = lista[menor];
			lista[menor] = aux;	
		}
	}
	
	imprimirLista();
}

int main(){
	// Select Sort
	// O Select Sort seleciona o primeiro elemento
	// da lista vai comparando com cada elemento da lista.
	// Caso ele encontre um elemento menor do que o atual,
	// Ele efetua uma troca de posicao entre os elementos,
	// E adota este (menor) como elemento de comparacao.
	// Ele repete o procedimento até o penúltimo item da
	// lista, resultando em uma lista ordenada.
	cout<<"\nlista Inicial \n";
	imprimirLista();
    
	cout<<"\nlista Ordenada por SelectSort \n";
	selectSort();
	
	return 0;
}
