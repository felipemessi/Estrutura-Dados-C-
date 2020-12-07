#include<iostream>  


using namespace std;  

int tamanhoLista = 10;
int lista[] = {3, 6, 1, 2, 9, 5, 4, 10, 7, 8};

int menor, aux;

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

void shellSort() 
{ 
    for (int intervalo = tamanhoLista/2; intervalo > 0; intervalo /= 2){ 
	    for (int i = intervalo; i < tamanhoLista; i ++) {        
			int aux = lista[i]; 
			 
			int j; 
			for (j = i; j >= intervalo && lista[j - intervalo] > aux; j -= intervalo) 
			lista[j] = lista[j - intervalo]; 
			               
			lista[j] = aux; 
	    } 
    } 
	imprimirLista();
} 
   


int main(){
	// Shell Sort
	// É um refinamento do método de inserção direta.O algoritmo difere 
	// do método de inserção direta pelo fato de no lugar de considerar 
	// o array a ser ordenado como um único segmento, ele considera 
	// vários segmentos sendo aplicado o método de inserção direta em 
	// cada um deles. Basicamente o algoritmo passa várias vezes pela 
	// lista dividindo o grupo maior em menores. Nos grupos menores é 
	// aplicado o método da ordenação por inserção. Implementações do 
	// algoritmo.
	
	
	cout<<"\nLista Inicial \n";
	imprimirLista();
    
    cout<<"\nLista Ordenada por ShellSort \n";
	shellSort();
	
	return 0;
}
