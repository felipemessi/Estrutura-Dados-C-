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
class Fila
{
private:
	No* cabeca; 
	No* cauda; 

public:
	Fila()
	{
		cabeca = NULL;
		cauda = NULL;
	}

	Fila(string v)
	{
		cabeca = new No(v);
		cauda = cabeca;
	}

	// verifica se a Fila está vazia
	bool vazia() 
	{
		return (cabeca == NULL);
	}
	
	// mostra todos os elementos da Fila
	void mostrar() 
	{
		cout << "\nImprimindo todos os elementos...\n";
		No* c = cabeca;

		if(vazia())
			cout << "A Fila NAO possui elementos!!\n";
		else
		{
			while(c) // percorre a Fila
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

	// retorna o tamanho da Fila
	int tamanho()
	{
		if(vazia()) // se for vazia, entã retorna 0
			return 0;

		No* c = cabeca;
		int tam = 0;
		
		// percorre a Fila
		do
		{
			c = c->obterProx();
			tam++;
		}
		while(c);
		
		return tam;
	}

	// verifica se um elemento existe na Fila
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

	// remove da Fila, remoção do inicio
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
	// Esta FILA mostra a Fila de exercicios
	// do final do ano de um aluno de Banco de Dados da FATEC.
	cout << "----------------------------------\n";
	cout << "Adicionando a TO DO list de trabalhos: \n";
	Fila trabalhos_Final_Ano;

	trabalhos_Final_Ano.inserir("PI");
	trabalhos_Final_Ano.inserir("Estrutura de Dados");
	trabalhos_Final_Ano.inserir("Programacao de Banco de Dados");
	trabalhos_Final_Ano.inserir("Filas Encadeadas");
	trabalhos_Final_Ano.inserir("Redes");
	
	cout << "----------------------------------\n";
	cout << "TO DO list de trabalhos a fazer: \n";
	
	if(trabalhos_Final_Ano.vazia())
		cout << "Fila vazia?? haha... até parece\n";
		
	trabalhos_Final_Ano.mostrar();
	
	cout << "Como bom aluno já fiz o primeiro trabalho da Fila! \nOlhe minha Fila atualizada de trabalhos! \n";
	trabalhos_Final_Ano.remover();
	
	trabalhos_Final_Ano.mostrar();
	
	cout << "Obrigado :D\n";
	
	return 0;
}
