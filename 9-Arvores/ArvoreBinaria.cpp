#include <iostream>
#include <cstdlib>
#include<windows.h>

using namespace std;

// ------------------------------------
//       	CLASSE NÓ
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
	//          OUTROS MÉTODOS
	// ------------------------------------

		void imprimir(No* no){
			if(no != NULL){
				imprimir(no->getEsq());
				cout << no->getChave() << " ";
				imprimir(no->getDir());
			}
		}	
		
	// ------------------------------------
	//       MÉTODOS DE CRIAÇÃO
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
	//       MÉTODOS DE BUSCA
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
	//       MÉTODOS DE REMOCAO
	// ------------------------------------	

		No* remover(No* raiz){	
			if (raiz != NULL){
				// Se a raiz possui ramos/folhas apenas à direita
				if (raiz->getEsq() == NULL and raiz->getDir() != NULL){
					No* aux = raiz->getDir();
					free(raiz);	
					return aux;
				}					
				// Se a raiz possui ramos/folhas dos dois lados ou apenas à esquerda
				else {
					// Para substituir a raiz a gente pode usar o menor nó
					// à direita ou o maior à esquerda. Usaremos o maior nó à esquerda.
					No* aux = raiz;
					No* auxProx = raiz->getEsq();
					// Captura o nó mais a direita a partir do primeiro nó à esquerda da raiz.
					while(auxProx->getDir() != NULL) {
						aux = auxProx;
						auxProx = auxProx->getDir();
					}
					// Se o auxiliar for diferente da raiz, ele atualiza o valor do auxProx.
					if ( aux != raiz) {
						aux->setDir(auxProx->getEsq());
						auxProx->setEsq(raiz->getEsq());
					}
					// atualiza a árvore sendo auxProx a nova raiz da árvore.
					auxProx->setDir(raiz->getDir());
					free(raiz);
					return auxProx;
				}
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
	arv.setRaiz(arv.remover(arv.getRaiz()));
	cout << "Nova Raiz: "<< arv.getRaiz()->getChave() << " ";

	cout << "\n\nPercorrendo em ordem o novo vetor...\n";
	arv.imprimir(arv.getRaiz());


	
	return 0;
}
