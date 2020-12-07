#include <iostream>
#include <stack>

using namespace std;


stack <int> A;
stack <int> B;
stack <int> C;

exibirSituacaoTorres(){
	if (A.empty()){
		cout << "\nTorre A :\n***A torre A est� vazia***\n";
	}
	else {
		cout << "\nTorre A :\n***Item do Topo: " << A.top() << " Quantidade de Itens: " << A.size() << "***\n";
	}
	if (B.empty()){
		cout << "\nTorre B :\n***A torre B est� vazia***\n";
	}
	else {
		cout << "\nTorre B :\n***Item do Topo: " << B.top() << " Quantidade de Itens: " << B.size() << "***\n";
	}
	if (C.empty()){
		cout << "\nTorre C :\n***A torre C est� vazia***\n";
	}
	else {
		cout << "\nTorre C :\n***Item do Topo: " << C.top() << " Quantidade de Itens: " << C.size() << "***\n";
	}
	cout << "\n";	
}

string moverItem(string tirar, string receber){
	int disco;
	// Captura o item a ser movido
	if (tirar == "A"){
		cout << A.top();
		disco = A.top();
		cout << disco;
	}
	else if (tirar == "B"){
		disco = B.top();
	}
	else if (tirar == "C"){
		disco = C.top();
	}
	
	// Verifica se o Item pode ser movido. Se sim, adiciona ele a nova fila
	if (receber == "A"){
		// Verifica se a Torre est� vazia, se sim, adiciona o disco
		if (A.empty()){
			A.push(disco);
		}
		// Se a torre n�o estiver vazia, verifica se o item pode ser movido.
		// Se sim, move o item, sen�o exibe uma mensagem de erro
		else {
			if (A.top() < disco){
				return "O disco n�o pode ser movido para torres com discos menores no topo.";
			}
			else {
				A.push(disco);
			}
		}
	}
	else if (receber == "B"){
		// Verifica se a Torre est� vazia, se sim, adiciona o disco
		if (B.empty()){
			B.push(disco);
		}
		// Se a torre n�o estiver vazia, verifica se o item pode ser movido.
		// Se sim, move o item, sen�o exibe uma mensagem de erro
		else {
			if (B.top() < disco){
				return "O disco n�o pode ser movido para torres com discos menores no topo.";
			}
			else {
				B.push(disco);
			}
		}
	} else if (receber == "C"){
		// Verifica se a Torre est� vazia, se sim, adiciona o disco
		if (C.empty()){
			C.push(disco);
		}
		// Se a torre n�o estiver vazia, verifica se o item pode ser movido.
		// Se sim, move o item, sen�o exibe uma mensagem de erro
		else {
			if (C.top() < disco){
				return "O disco n�o pode ser movido para torres com discos menores no topo.";
			}
			else {
				C.push(disco);
			}
		}
	}
	// Retira o item da torre Anterior do item
	if (tirar == "A"){
		A.pop();
	}
	else if (tirar == "B"){
		B.pop();
	}
	else if (tirar == "C"){
		C.pop();
	}
	
	cout << "Disco " << disco;
	return " foi movido da torre " + tirar + " para a torre " + receber + "\n\n";
}

string escolherTorreParaMover(){
	// Declarando vari�veis
	stack <int> torre;
	string torreEscolha;
	cout << "A" << "\n" << "B" << "\n" << "C" << "\nTorre: ";
	cin >> torreEscolha;
	cout < "\n\n";
	
	// Verifica se a torre Escolhida foi a A
	if (torreEscolha == "A"){
		return  "A";
	}
	// Verifica se a torre Escolhida foi a A
	else if (torreEscolha == "B"){
		return  "B";
	}
	else if (torreEscolha == "C"){
		return  "C";
	}
	else {
		cout << "Torre Inv�lida. Tente novamente ..." << "\n\n\n";
		escolherTorreParaMover();	
	}
	// Verifica se a torre Escolhida tem algum item.
	if (torre.empty()){
		cout << "Torre Vazia. Tente novamente ..." << "\n\n\n";
		escolherTorreParaMover();	
	}
	return "";	
}

	
int main(int argc, char** argv) {
	
	// JOGO DE TRANSFERIR PILHAS
	// Nesse jogo voc� n�o pode empilhar discos de valor maior do que o que j� esta na pilha,
	// ou seja, se na pilha tem um disco com valor 2 no topo, voc� s� pode empilhar o disco 
	// de valor 1.
	// Existem 3 torres em que os discos podem ser empilhados, as torres : A, B e C
	// No in�cio, todos os discos est�o na torre A. O Objetivo � passa-los para a torre C.

	
	// Configurando o in�cio
	A.push(5);
	A.push(4);
	A.push(3);
	A.push(2);
	A.push(1);
	
	// O Jogo:
	
	while (C.size() < 5) {
		exibirSituacaoTorres();
	
		cout << "\nDeseja mover o disco de qual torre?" << "\n";
		string tirarTorre = escolherTorreParaMover();
	
		cout << "Deseja mover o disco para qual torre?" << "\n";
		string receberTorre = escolherTorreParaMover();
			
		cout << moverItem(tirarTorre, receberTorre) << "\n";
		cout << "------------ FIM DA RODADA -----------" << "\n\n";
	}
	
	cout << "+++++++++++++++ PARABENS, VOCE VENCEU! + ++++++++++++++++++";
	
	return 0;
}
