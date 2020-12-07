#include <iostream>
#include <queue>
#include<windows.h>

using namespace std;

queue <string> fila_preferencial;
queue <string> fila_normal;	

// Atualiza o status da Fila
filaStatus(){
	cout << "----------STATUS----------";
	if (fila_normal.empty()){
		cout << "\nA fila normal esta vazia";
	}
	else {
		cout << "A fila normal esta com " << fila_normal.size() << " pessoas.\n";
		cout << "O ultimo da fila eh a(o): " << fila_normal.back() << "\n";
	}
	cout  << "\n";
	
	if (fila_preferencial.empty()){
		cout << "A fila preferencial esta vazia\n";
	}
	else {
		cout << "A fila preferencial esta com " << fila_preferencial.size() << " pessoas.\n";
		cout << "O ultimo da fila é a(o): " << fila_preferencial.back() << "\n";
	}
	cout  << "\n----------------------------\n";
}

// Insere uma pessoa na Fila normal
entrarFilaNormal(){
	string nome;
	cout << "Qual o seu nome?\n";
	cin >> nome;
	fila_normal.push(nome);
	cout << "\nVoce entrou na fila normal, voce esta na posicao: " << fila_normal.size() << "\n";
}

// Insere uma pessoa na Fila Preferencial
entrarFilaPreferencial(){
	string nome;
	cout << "Qual o seu nome?\n";
	cin >> nome;
	fila_preferencial.push(nome);
	cout << "\nVoce entrou na fila preferencial, voce esta na posicao: " << fila_preferencial.size() << "\n";
}

// Atender um cliente
atenderUmCliente(){
	// Caso as duas filas estejam vazias
	if (fila_preferencial.empty() and fila_normal.empty()){
		cout << "Sem pessoas na fila"; 
	}
	// Caso a fila preferencial esteja vazia e a normal não
	else if (fila_preferencial.empty()){
		cout << "Atendendo a pessoa: " << fila_normal.front();
		fila_normal.pop();
	}
	// Caso a fila normal esteja muuuuuito maior que a fila preferencial
	else if (fila_normal.size() > fila_preferencial.size()*3){
		cout << "Atendendo a pessoa: " << fila_normal.front();
		fila_normal.pop();
	}
	// Outros casos
	else {
		cout << "Atendendo a pessoa: " << fila_preferencial.front();
		fila_preferencial.pop();
	}
	cout << "\n";
}


// Função Principal
int main(int argc, char** argv) {
	
	// FILAS
	// Em um Fast-Food existem 2 filas: a preferencial e a normal.
	// No nosso exercicio vamos gerenciar essas filas. Para um melhor atendimento
	// é anotado o nome de cada pessoa que entra na fila e um painel exibe a 
	// situacao atual da fila.
	
	int operacao = 1000;
	
	while (operacao > 0){
		
		filaStatus();
		
		cout << "Digite uma operacao\n1 - Entrar na Fila Normal\n2 - Entrar na Fila Preferencial\n";
		cout << "3 - Atender um Cliente\n0 - Sair do Sistema\n\nOperacao: ";
		cin >> operacao;
		
		if (operacao == 1){
			entrarFilaNormal();
		}	
		else if (operacao == 2){
			entrarFilaPreferencial();
		}		
		else if (operacao == 3){
			atenderUmCliente();
		}
		else{
			return 0;
		}
		cout << "\n";
		Sleep(2000);
	}
	
	return 0;
}
