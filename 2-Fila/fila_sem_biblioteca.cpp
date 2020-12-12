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

	// insere no fim da fila
	void inserir(string v)
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

	// remove da lista, remoção do inicio
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
				No* aux = cabeca->obterProx();
				delete cabeca;
				cabeca = aux;
			}
		}
	}
};

int main(int argc, char *argv[])
{
	// Esta FILA mostra a lista de exercicios
	// do final do ano de um aluno de Banco de Dados da FATEC.
	cout << "----------------------------------\n";
	cout << "Adicionando a TO DO list de trabalhos: \n";
	Lista trabalhos_Final_Ano;

	trabalhos_Final_Ano.inserir("PI");
	trabalhos_Final_Ano.inserir("Estrutura de Dados");
	trabalhos_Final_Ano.inserir("Programacao de Banco de Dados");
	trabalhos_Final_Ano.inserir("Listas Encadeadas");
	trabalhos_Final_Ano.inserir("Redes");
	
	cout << "----------------------------------\n";
	cout << "TO DO list de trabalhos a fazer: \n";
	
	if(trabalhos_Final_Ano.vazia())
		cout << "Lista vazia?? haha... até parece\n";
		
	trabalhos_Final_Ano.mostrar();
	
	cout << "Como bom aluno já fiz o primeiro trabalho da lista! \nOlhe minha lista atualizada de trabalhos! \n";
	trabalhos_Final_Ano.remover();
	
	trabalhos_Final_Ano.mostrar();
	
	cout << "Obrigado :D\n";
	
	return 0;
}
