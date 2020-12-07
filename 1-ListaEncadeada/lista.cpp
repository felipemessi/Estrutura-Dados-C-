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

	string obterValor()
	{
		return v;
	}

	No* obterProx()
	{
		return prox;
	}

	void setProx(No* p) 
	{
		prox = p;
	}
};

// classe Lista
class Lista
{
private:
	No* cabeca; 
	No* cauda; 

public:
	Lista()
	{
		cabeca = NULL;
		cauda = NULL;
	}

	Lista(string v)
	{
		cabeca = new No(v);
		cauda = cabeca;
	}

	// verifica se a lista está vazia
	bool vazia() 
	{
		return (cabeca == NULL);
	}
	
	// mostra todos os elementos da lista
	void mostrar() 
	{
		cout << "\nImprimindo todos os elementos...\n";
		No* c = cabeca;

		if(vazia())
			cout << "A lista NAO possui elementos!!\n";
		else
		{
			while(c) // percorre a lista
			{
				cout << c->obterValor() << endl;
				c = c->obterProx();
			}
			cout << endl;
		}
	}

	// insere no início
	void inserir_inicio(string v)
	{
		No* novo_no = new No(v);

		if(vazia())
		{
			cabeca = novo_no;
			cauda = novo_no;
		}
		else
		{
			novo_no->setProx(cabeca);
			cabeca = novo_no;
		}
	}

	// insere no fim
	void inserir_final(string v)
	{
		No* novo_no = new No(v);

		if(vazia())
		{
			cabeca = novo_no;
			cauda = novo_no;
		}
		else
		{
			cauda->setProx(novo_no);
			cauda = novo_no;
		}
	}

	// retorna o tamanho da lista
	int tamanho()
	{
		if(vazia()) // se for vazia, entã retorna 0
			return 0;

		No* c = cabeca;
		int tam = 0;
		
		// percorre a lista
		do
		{
			c = c->obterProx();
			tam++;
		}
		while(c);
		
		return tam;
	}

	// verifica se um elemento existe na lista
	bool existe(string v)
	{
		No* c = cabeca;
		
		while(c)
		{
			if(c->obterValor() == v)
				return true;
			c = c->obterProx();
		}
		return false;
	}

	// remove da lista, remoção do final (semelhante a pop_back da list)
	void remover()
	{
		if(!vazia())
		{
			// se houver só 1 elemento
			if(cabeca->obterProx() == NULL)
				cabeca = NULL;
			else if(cabeca->obterProx()->obterProx() == NULL) // 2 elementos
				cabeca->setProx(NULL);
			else // > 2 elementos
			{
				No* ant_ant = cabeca;
				No* ant = cabeca->obterProx();
				No* corrente = cabeca->obterProx()->obterProx();

				while(corrente)
				{
					No* aux = ant;
					ant = corrente;
					ant_ant = aux;
					corrente = corrente->obterProx();
				}
				delete ant_ant->obterProx(); // libera memória
				ant_ant->setProx(NULL); // seta o prox como NULL
				cauda = ant_ant; // atualiza a cauda
			}
		}
	}
};

int main(int argc, char *argv[])
{
	// Esta lista encadeada SIMPLES mostra a lista de exercicios
	// do final do ano de um aluno de Banco de Dados da FATEC.
	cout << "----------------------------------\n";
	cout << "Antes de Adicionar os Trabalhos: \n";
	Lista trabalhos_Final_Ano;
	
	if(trabalhos_Final_Ano.vazia())
		cout << "Lista vazia!!\n";
	else
		cout << "Lista NAO vazia!!\n";
	
	trabalhos_Final_Ano.mostrar();
	
	if(trabalhos_Final_Ano.existe("Estrutura de Dados"))
		cout << "\nO trabalho 'Estrutura de Dados' existe na lista!!\n";
	else
		cout << "\nO trabalho 'Estrutura de Dados' NAO existe na lista!!\n";
	
	trabalhos_Final_Ano.inserir_final("PI");
	trabalhos_Final_Ano.inserir_final("Estrutura de Dados");
	trabalhos_Final_Ano.inserir_final("Programacao de Banco de Dados");
	trabalhos_Final_Ano.inserir_final("Listas Encadeadas");
	trabalhos_Final_Ano.inserir_inicio("Redes");
	
	cout << "----------------------------------\n";
	cout << "Depois de Adicionar os Trabalhos: \n";
	
	if(trabalhos_Final_Ano.vazia())
		cout << "Lista vazia?? haha... até parece\n";
	else
		cout << "Voce tem trabalho para entregar (monday.com)!!\n";
		
	trabalhos_Final_Ano.mostrar();
	
	trabalhos_Final_Ano.remover();
	
	if(trabalhos_Final_Ano.existe("Listas Encadeadas"))
		cout << "\nO trabalho ''Listas Encadeadas' existe na lista!!\n";
	else
		cout << "\nO trabalho 'Listas Encadeadas' NAO existe na lista mais, ";
		cout << "porque o aluno esta acabando de fazer!!!\n";
	
	
	trabalhos_Final_Ano.mostrar();
	
	cout << "Sabe quantos trabalhos eu tenho que fazer?: " << trabalhos_Final_Ano.tamanho()<< "!!!\n";
	
	return 0;
}
