//#include <stdio.h> 
#include <iostream>
#include <cstdlib>
#include<windows.h>

using namespace std; 
 
typedef struct No{
        struct No *prox;
        int _data;
}No, *Lista;
 
void iniciar(Lista *novoNo){
        *novoNo = NULL;
}
 
int inserir(Lista *no, int data){
        Lista p = new No();
        if(p == NULL)   return -1;
        p->_data = data;
        p->prox = NULL;
        if(*no == NULL){
                *no = p;
        }else{
                p->prox = *no;
                *no = p;
        }
        return 0;
}
 
void imprimir(Lista no){
        Lista aux = no;
        if(aux == NULL) return;
        int count = 0;
        printf("\n=======IMPRIME LISTA======\n");
        do{
                printf("%d\t%d\n", count++, aux->_data);
                aux = aux->prox;
        }while(aux);
        printf("-------FIM IMPRESSAO------\n");
}

bool buscar(Lista no, int v){
	Lista aux = no;
	if(aux == NULL) return false;
	while (aux->prox != NULL){
		if (aux->_data == v){
			return true;
		}
		aux = aux->prox;
	}
	return false;
}
 
void removeProximo(No *no){
    No *aux = no->prox;
   	no->prox = aux->prox;
	free(aux);	
}
 
Lista lista;
int main(){
		cout << "\nInicializando a Lista e Inserindo os primeiros valores ...\n\n";
		// inicializando a lista
        iniciar(&lista);
        // inserindo elementos na lista
        inserir(&lista, 111);
        inserir(&lista, 222);
        inserir(&lista, 333);
        // imprime lista
        imprimir(lista);
        
        cout << "\nO valor 333 existe na lista?\n";
        
        bool existe = buscar(lista, 333);
 		if (existe == true){
 			cout << "O valor existe na lista!\n";
		 }
		 else {
		 	cout << "O valor NAO existe na lista!\n";
		 }
		
		// remove o elemento 222 da lista 
        removeProximo(lista);
        // imprime a lista
        imprimir(lista);
 
 		cout << "\nO valor 222 existe na lista?\n";
 		
 		//existe = buscar(lista, 333);
 		if (buscar(lista, 222) == true){
 			cout << "O valor existe na lista\n";
		 }
		 else {
		 	cout << "O valor NAO existe na lista\n";
		 }
		 
        return 0;
}
