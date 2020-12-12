#include <iostream>
#include <cstdlib>

using namespace std;

struct Pilha {
	int top;
	int tamanho;
	int *prox;
};

void criarPilha( struct Pilha *p, int c ){

   p->top = -1;
   p->tamanho = c;
   p->prox = (int*) malloc(sizeof(int));

}

bool isEmpty ( struct Pilha *p ){
   if( p-> top == -1 )
      return true; 
   else
      return false;
}

bool isFull ( struct Pilha *p ){
	if (p->top == p->tamanho - 1)
		return true;
	else
		return false;

}

void empilhar ( struct Pilha *p, int v){
	p->top++;
	p->prox [p->top] = v;
}

float desempilhar ( struct Pilha *p ){
   int aux = p->prox [p->top];
   p->top--;
   return aux;

}

int retornatop ( struct Pilha *p ){
   return p->prox [p->top];
}

int main(){

	struct Pilha minhapilha;
	int tamanhoPilha, op;
	int valor;

	cout << "\Qual o tamanho da pilha? ";
	cin >> tamanhoPilha;

	criarPilha (&minhapilha, tamanhoPilha);

	while( 1 ){ /* loop infinito */

		cout << "\n1- Adicionar Elemento a Pilha\n";
		cout << "2- Retirar elemento da Pilha\n";
		cout << "3- Mostrar o topo \n";
		cout << "4- Sair\n";
		cout << "\nDigite o numero da Opcao que você deseja?\n ";
		cout << "Opcao: ";
		cin >> op;

		switch (op){

			case 1: // Adicionar à pilha

				if( isFull( &minhapilha ))

					cout <<"\nPilha cheia! \n";

				else {

					cout <<"\Qual o valor que deseja inserir? ";
					cin >> valor;
					empilhar (&minhapilha, valor);

				}
				break;

			case 2: //Retirar da Pilha
				if ( isEmpty(&minhapilha) )

					printf( "\nPilha vazia! \n" );

				else{

					valor = desempilhar (&minhapilha);
					cout << "\n%.1f Elemento retirado!\n", valor ;

				}
				break;

			case 3: // Mostra o elemento do topo
				if ( isEmpty(&minhapilha))

					cout << "\nA pilha esta vazia!\n";

				else {

					valor = retornatop (&minhapilha);
					cout << "\ntop: %.1f\n", valor;

				}
				break;

			case 4: 
				exit(0);

			default: cout << "\nOpcao Invalida, tente novamente! \n";
		}
	}	
}


