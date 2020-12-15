#include <iostream>

using namespace std;

// classe No
class No
{
private:
	string v;
	No* prox;
public:
	// construtor
	No(string v) 
	{
		this->v = v;
		this->prox = NULL;
	}

	string getValor()
	{
		return v;
	}

	No* getProx()
	{
		return prox;
	}

	void setProx(No* p) 
	{
		this->prox = p;
	}
	
	// mostra todos os elementos da lista
	void mostrar() 
	{
		int a;
		No* auxiliar;
		auxiliar = this;
		while (auxiliar != NULL){
			cout << auxiliar->getValor() << "\n";
			auxiliar = auxiliar->getProx();
		}
	}

	// insere depois do nó passado no parâmetro.
	void inserir(string v, No* no)
	{
		if (no->getProx() == NULL){
			No* auxiliar = new No(v);
			no->setProx(auxiliar);
			auxiliar->prox = NULL;
		}
		else {
			No* auxiliar;
			auxiliar = new No(v);
			auxiliar->setProx(no->getProx());
			no->setProx(auxiliar);
		}
		
	}

	// verifica se um elemento existe na lista
	bool existe(string v)
	{
		No* auxiliar;
		for (auxiliar = this; auxiliar != NULL; auxiliar = auxiliar->getProx()){
			if (auxiliar->getValor() == v){
				return true;
			}
		}	
		return false;
	}

	// remove da lista
	void remover(string v)
	{	
		No* auxiliar;
		No* proximo;
		auxiliar = this;
		proximo = this->getProx();
		while (proximo != NULL and proximo->getValor() != v){
			auxiliar = proximo;
			proximo = proximo->getProx();
		}
		if (proximo != NULL){
			auxiliar->setProx(proximo->getProx());
			delete(proximo);
		}
	}
};



int main(int argc, char *argv[])
{
	// Esta lista encadeada SIMPLES mostra a lista de exercicios
	// do final do ano de um aluno de Banco de Dados da FATEC.
	cout << "----------------------------------\n";
	// Adicionando trabalhos à lista:
	No* lista = new No("lista encadeada com cabeca");
	lista->inserir("lista encadeada sem cabeca", lista);
	lista->inserir("select sort", lista);
	lista->inserir("shell sort", lista);
	lista->inserir("insert sort", lista);
	lista->inserir("quick sort", lista);
	
	lista->mostrar();
	
	
	cout << "\n\nO elemento 'lista encadeada com cabeca' pertence a lista?\n";
	if (lista->existe("lista encadeada com cabeca")){
		cout << "'lista encadeada com cabeca' esta na lista.\n";
	}
	else {
		cout << "'lista encadeada com cabeca' NAO esta na lista.\n";
	}
	
	lista->remover("lista encadeada sem cabeca");
	cout << "\n\nFeito a lista encadeada sem cabeca\n\n";
	
	return 0;

}
