#include<iostream>  


using namespace std;  

int tamanhoLista = 10;
int lista[] = {3, 6, 1, 2, 9, 5, 4, 10, 7, 8};

int menor, aux;

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

// Junta as metades das listas e as ordena
void Merge(int lista[], int ini, int meio, int fim, int listaAux[]) {
    int esq = ini;
    int dir = meio;
    for (int i = ini; i < fim; ++i) {
        if ((esq < meio) and ((dir >= fim) or (lista[esq] < lista[dir]))) {
            listaAux[i] = lista[esq];
            ++esq;
        }
        else {
            listaAux[i] = lista[dir];
            ++dir;
        }
    }
    for (int i = ini; i < fim; ++i) {
        lista[i] = listaAux[i];
    }
}

void MergeSort(int lista[], int inicio, int fim, int listaAux[]) {
    if ((fim - inicio) < 2) return;
    
    int meio = ((inicio + fim)/2);
    // quebra a primeira metade da lista
    MergeSort(lista, inicio, meio, listaAux);
    // quebra a segunda metade da lista
    MergeSort(lista, meio, fim, listaAux);
    // ordena a lista
    Merge(lista, inicio, meio, fim, listaAux);
}

void MergeSort() { 
    int listaAux[tamanhoLista];
    MergeSort(lista, 0, tamanhoLista, listaAux);
    imprimirLista();
}

	
int main(){
	// Merge Sort
	// O Merge Sort � feito usando tr�s passos:
	// 1 - A lista � dividia ao meio, como duas partes de tamanho igual.
	// Se o numero de elementos na lista for 0 ou 1, ent�o a lista � considerada ordenada.
	// 2- Cada sublista � ordenada individualmente usando o Merge Sorte recursivamente.
	// 3 - A ordena��o de sublistas � combinada ou juntada para obter a forma completa
	// da lista ordenada.
	
	
	cout<<"\nLista Inicial \n";
	imprimirLista();
    
    cout<<"\nLista Ordenada por MergeSort \n";
	MergeSort();
	
	return 0;
}	
