#include<iostream>  


using namespace std;  

int tamanhoLista = 10;
int lista[] = {3, 6, 1, 2, 9, 5, 4, 10, 7, 8};

// imprime a lista
void imprimirLista(){
	cout << "Lista = {";
	for (int i = 0; i < tamanhoLista; i++) {
		cout << lista[i];
		if (i != tamanhoLista- 1){
			cout << ", ";
		}
	}
	cout << "}\n";
}

// Quick Sort - ordenacao
void QuickSort(int inicio, int fim) {
	int i, j, pivo, aux;
	i = inicio;
	j = fim-1;
	pivo = lista[(inicio + fim) / 2];
	while(i <= j) {
		while(lista[i] < pivo && i < fim){
			i++;
		}
		while(lista[j] > pivo && j > inicio) {
			j--;
		}
		if(i <= j){
			aux = lista[i];
			lista[i] = lista[j];
			lista[j] = aux;
			i++;
			j--;
		}
	}
	if(j > inicio)
		QuickSort(inicio, j++);
	if(i < fim)
		QuickSort(i, fim);
}


// -------------------

int main(){
// O quicksort adota a estratégia de divisão e conquista. A estratégia 
// consiste em rearranjar as chaves de modo que as chaves "menores" 
// precedam as chaves "maiores". Em seguida o quicksort ordena as duas 
// sublistas de chaves menores e maiores recursivamente até que a lista 
// completa se encontre ordenada. Os passos são:
//
// 1 - Escolha um elemento da lista, denominado pivô;
// 2 - Particiona: rearranje a lista de forma que todos os elementos 
// anteriores ao pivô sejam menores que ele, e todos os elementos 
// posteriores ao pivô sejam maiores que ele. Ao fim do processo o pivô 
// estará em sua posição final e haverá duas sub listas não ordenadas. 
// Essa operação é denominada partição;
// 3 - Recursivamente ordene a sub lista dos elementos menores e a sub 
// lista dos elementos maiores;
//
// O caso base da recursão são as listas de tamanho zero ou um, que estão 
// sempre ordenadas. O processo é finito, pois a cada iteração pelo menos 
// um elemento é posto em sua posição final e não será mais manipulado na 
// iteração seguinte.
	
	
	cout<<"\nLista Inicial \n";
	imprimirLista();
    
    cout<<"\nLista Ordenada por QuickSort \n";
	QuickSort(0, tamanhoLista);
	imprimirLista();
	
	return 0;
}	
