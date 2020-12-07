#include<iostream>  


using namespace std;  

int tamanhoLista = 10;
int lista[] = {3, 6, 1, 2, 9, 5, 4, 10, 7, 8};

void imprimirLista(){
	for(int i=0;i<10;i++)  
    {  
        cout << lista[i] <<"\t";  
    }  
}

void insertSort(){
	for(int i=1; i<tamanhoLista; i++){  
        int aux = lista[i];  
        int j= i-1;  
        while(j>=0 && aux <= lista[j])  
        {  
            lista[j+1] = lista[j];   
            j = j-1;  
        }  
        lista[j+1] = aux;  
    } 
	imprimirLista(); 
}

int main ()  
{   
	// O Insertion Sort faz a ordenação comparando todos
	// os elementos anteriores dele com o próximo elemento;
	// Feito a comparação ele insere o proximo elemento
	// no local correto da lista, ficando todos elementos
	// anteriores corretamente ordenado. Ele faz isso até
	// o último elemento, resultando em uma lista ordenada.
 
    cout<<"\nLista Inicial \n";
	imprimirLista();
    
    cout<<"\nLista Ordenada por InsertionSort \n";
	insertSort();
}

