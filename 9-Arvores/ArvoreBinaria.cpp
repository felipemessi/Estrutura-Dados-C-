#include <iostream>
#include <cstdlib>
#include<windows.h>

using namespace std;

// ------------------------------------
//       	CLASSE N�
// ------------------------------------
class No {
	private:
		No *esq, *dir;
		int chave;

	public:
		No(int chave){
			this -> chave = chave;
			esq = NULL;
			dir = NULL;
		}
		
		int getChave(){
			return chave;
		}
		
		int setChave(int novaChave){
			chave = novaChave;
		}
		
		No* getEsq(){
			return esq;
		}
		
		No* getDir(){
			return dir;
		}
		
		void setEsq(No* no){
			esq = no;
		}
		
		void setDir(No* no){
			dir = no;
		}
};
		
// ------------------------------------
//       	CLASSE ARVORE
// ------------------------------------
class Arvore {
	private:
		No* raiz;
		
	public:
		Arvore(){
			raiz = NULL;
		}
		
		No* getRaiz() {
			return raiz;
		}
		
		void setRaiz(No* no){
			raiz= no;
		}
	
	// ------------------------------------
	//          OUTROS M�TODOS
	// ------------------------------------

		void imprimir(No* no){
			if(no != NULL){
				imprimir(no->getEsq());
				cout << no->getChave() << " ";
				imprimir(no->getDir());
			}
		}	
		
	// ------------------------------------
	//       M�TODOS DE CRIA��O
	// ------------------------------------
		
		void criar(int chave){
			if (raiz == NULL)
				raiz = new No(chave);
			else
				criarAux(raiz, chave);
		}
		
		void criarAux( No* no, int chave) {
			if(chave < no->getChave()){
				if(no->getEsq() == NULL){
					No* novoNo = new No(chave);
					no->setEsq(novoNo);
				}
				else {
					criarAux(no->getEsq(), chave);
				}
			}
			else if (chave > no->getChave()){
				if (no->getDir() == NULL){
					No* novoNo = new No(chave);
					no->setDir(novoNo);
				}
				else {
					criarAux(no->getDir(), chave);
				}
			}
		}
		
	// ------------------------------------
	//       M�TODOS DE BUSCA
	// ------------------------------------
		void buscar(No* no, int valorBuscado) {
			if (no == NULL){
				cout << "Valor NAO encontrado!\n";
			}
			else if (no->getChave() == valorBuscado){
				cout << "Valor Encontrado!\n";
			}
			else if (no->getChave() > valorBuscado){
				buscar(no->getEsq(), valorBuscado);
			}
			else {
				buscar(no->getDir(), valorBuscado);	
			}
		}


	// ------------------------------------
	//       M�TODOS DE REMOCAO
	// ------------------------------------	
		// Retorna ultimo n� da Esquerda
		No* menorNoDireita(No* noEsquerda){
			while(noEsquerda->getEsq() != NULL){
				noEsquerda= noEsquerda->getEsq();
			}
			cout << "NoEsquerdaRetorno: " << noEsquerda->getChave() << "\n";
			return noEsquerda;
		}
		
		No* remover(No* raiz, int valorRemover){
			if (raiz != NULL){
				// Valor > Raiz -> Percorre a arvore pela direita.
				if(valorRemover > raiz->getChave()){
					raiz->setDir(remover(raiz->getDir(), valorRemover));
				}
				// Valor < Raiz -> Percorre a arvore pela esquerda.
				else if (valorRemover < raiz->getChave()){
					raiz->setEsq(remover(raiz->getEsq(), valorRemover));
				}
				// Valor que eu quero remover est� na raiz.
				else{
					// Se a raiz n�o possui ramos/folhas nem a direita e nem a esquerda.
					if (raiz->getEsq() == NULL and raiz->getDir() == NULL){
						free(raiz);
						return NULL;
					}
					// Se a raiz possui ramos/folhas apenas � direita
					else if (raiz->getEsq() == NULL and raiz->getDir() != NULL){
						No* aux = raiz->getDir();
						free(raiz);	
						return aux;
					}
					// Se a raiz possui ramos/folhas apenas � esquerda
					else if (raiz->getEsq() != NULL and raiz->getDir() == NULL){
						No* aux = raiz->getEsq();
						free(raiz);
						return aux;	
					}
					// Se a raiz possui ramos/folhas dos dois lados.
					else {
						// Para substituir a raiz a gente pode usar o menor n�
						// � direita ou o maior � esquerda. Usaremos o m�todo 
						// menorNoDireita para pegar o menor n� da direita
						No* aux = menorNoDireita(raiz->getDir());
						// Salvo o valor que est� no n�.
						int valor = aux->getChave();
						// Removo o n�.
						raiz = remover(raiz, aux->getChave());
						// atribuo o valor que estava contido no n� na raiz.
						raiz->setChave(valor);
						return raiz;
					}
				}
				return raiz;
			}
			 return NULL;
		}			
};
	

int main(int argc, char *argv[])
{
	Arvore arv;

	// Alimentando a arvore
	arv.criar(3);
	arv.criar(6);
	arv.criar(1);
	arv.criar(2);
	arv.criar(9);
	arv.criar(5);
	arv.criar(4);
	arv.criar(10);
	arv.criar(7);
	arv.criar(8);
	
	/* percorre em ordem iniciando da raiz
	cout << "Percorrendo em ordem...\n";
	arv.imprimir(arv.getRaiz());
	
	cout << "\n\nBuscando valor 10 na arvore:\n";
	arv.buscar(arv.getRaiz(), 10);

	cout << "\n\nBuscando valor 11 na arvore:\n";
	arv.buscar(arv.getRaiz(), 11);
	*/

	cout << "\n\nRemovendo o valor 10 na arvore:\n";	
	arv.setRaiz(arv.remover(arv.getRaiz(), 10));
	
	cout << "\n\nPercorrendo em ordem o novo vetor...\n";
	arv.imprimir(arv.getRaiz());


	
	return 0;
}
