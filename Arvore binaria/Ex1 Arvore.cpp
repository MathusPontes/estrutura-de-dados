#include <iostream>

using namespace std;

typedef struct Arvore{
	int numero;
	Arvore *esquerda, *direita;
}Arvore;

int menu(){
	int opcao;
	do{
		system("cls");
		cout << endl << "MENU DE OPCOES" << endl;
		cout << "1 - Inserir numero na arvore." << endl;
		cout << "2 - Mostrar todos os numeros" << endl;
		cout << "3 - Mostrar o maior numero." << endl;
        cout << "4 - Mostrar o menor numero." << endl;
        cout << "5 - Mostrar quantos numeros tem na arvore." << endl;
		cout << "6 - Sair." << endl;
		
		cout << "Digite a sua escolha: ";
		cin >> opcao;
		
		cout << endl;
		
		if(opcao < 1 || opcao > 6){
			cout << "Opcao invalida!" << endl;
			system("pause");
		}
	}while(opcao < 1 || opcao > 6);
	
	return opcao;
}

Arvore* inserir (Arvore *arvore, int numero){
	if(arvore == NULL){
		arvore = new Arvore();
		arvore->numero = numero;
		arvore->esquerda = NULL;
		arvore->direita = NULL;
	}
	
	else if(numero < arvore->numero){
		arvore->esquerda = inserir(arvore->esquerda, numero);
	}
	
	else{
		arvore->direita = inserir(arvore->direita, numero);
	}
	
	return arvore;		
}

void mostraEmOrdem(Arvore *arvore){
	if(arvore != NULL){
		mostraEmOrdem(arvore->esquerda);
		cout << arvore->numero << " ";
		mostraEmOrdem(arvore->direita);
	}
}

int consulta(Arvore *arvore, int numero, int achou){
	if(arvore != NULL && achou == 0){
		if(arvore->numero == numero){
			achou = 1;
		}
		else if(numero < arvore->numero){
			achou = consulta(arvore->esquerda, numero, achou);
		}
		else{
			achou = consulta(arvore->direita, numero, achou);
		}
	}
	return achou;
}

void mostraMaior (Arvore *arvore){
	if(arvore != NULL){
		mostraMaior(arvore->direita);
		if (arvore->direita == NULL){
			cout << "O maior numero da arvore: " << arvore->numero;
		}
	}
}

void mostraMenor (Arvore *arvore){
	if(arvore != NULL){
		mostraMenor(arvore->esquerda);
		if (arvore->esquerda == NULL){
			cout << "O menor numero da arvore: " << arvore->numero;
		}
	}
}

Arvore *desalocar(Arvore *arvore){
	if(arvore != NULL){
		arvore->esquerda = desalocar(arvore->esquerda);
		arvore->direita = desalocar(arvore->direita);
		delete arvore;
	}
	return NULL;
}

bool eVazia(Arvore *arvore){
	if(arvore == NULL){
		return true;
	}
	return false;
}

int main(){
	Arvore *raiz = NULL, *aux;
	
	int escolha, numero, achou, quant;
	
	do{
		escolha = menu();
		
		switch(escolha){
			case 1:
				cout << "Digite o numero: ";
				cin >> numero;
				
				raiz = inserir(raiz, numero);
				cout << "Numero inserido na arvore";
				quant ++;
				cout << endl;
				system("PAUSE");
				break;
				
			case 2:
				if (eVazia(raiz)){
					cout << "Arvore vazia!" << endl;
				}
				else{
					cout << "Listando os elementos da arvore em ordem ";
					mostraEmOrdem(raiz);
				}
				cout << endl;
				system("PAUSE");
				break;
			
			case 3:
				if (eVazia(raiz)){
					cout << "Arvore vazia!" << endl;
				}
				else{
					mostraMaior(raiz);
				}
				cout << endl;
				system("PAUSE");
				break;
			
			case 4:
				if (eVazia(raiz)){
					cout << "Arvore vazia!" << endl;
				}
				else{
					mostraMenor(raiz);
				}
				cout << endl;
				system("PAUSE");
				break;
				
			case 5:
				if (eVazia(raiz)){
					cout << "Arvore vazia!" << endl;
				}
				else{
					cout << "A arvore possui " << quant << " elementos dentro dela.";
				}
				cout << endl;
				system("PAUSE");
				break;
				
			default:
				cout << "Saindo..." << endl;
		}
	}while(escolha != 6);
	
	raiz = desalocar(raiz);
}
