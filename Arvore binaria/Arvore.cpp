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
		cout << "2 - Consulta noh na arvore." << endl;
		cout << "3 - Consulta toda a arvore em ordem." << endl;
		cout << "4 - Consulta toda a arvore em pre-ordem." << endl;
        cout << "5 - Consulta toda a arvore em pos-ordem." << endl;
		cout << "6 - Excluir um noh da arvore." << endl;
		cout << "7 - Esvaziar a arvore." << endl;
		cout << "8 - Sair." << endl;
		
		cout << "Digite a sua escolha: ";
		cin >> opcao;
		
		cout << endl;
		
		if(opcao < 1 || opcao > 8){
			cout << "Opcao invalida!" << endl;
			system("pause");
		}
	}while(opcao < 1 || opcao > 8);
	
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

void mostraPreOrdem(Arvore *arvore){
	if(arvore != NULL){
		cout << arvore->numero << " ";
		mostraEmOrdem(arvore->esquerda);
		mostraEmOrdem(arvore->direita);
	}
}

void mostraPosOrdem(Arvore *arvore){
	if(arvore != NULL){
		mostraEmOrdem(arvore->esquerda);
		mostraEmOrdem(arvore->direita);
		cout << arvore->numero << " ";
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

Arvore* remover(Arvore* arvore, int numero){
	Arvore *pAux1, *pAux2;
	
	if(arvore->numero = numero){
		if(arvore->esquerda == arvore->direita){
			// O elemento a ser removido não possui filhos
			delete arvore;
			return NULL;
		}
		
		else if(arvore->esquerda == NULL){
			// O elemento a ser removido não possui filho a esquerda
			pAux1 = arvore->direita;
			delete arvore;
			return pAux1;
		}
		
		else if (arvore->direita == NULL){
			// O elemento a ser removido não possui filho a direita
			pAux1 = arvore->esquerda;
			delete arvore;
			return pAux1;
		}
		
		else{
			// O elemento a ser removido possui filhos dos dois lados
			pAux2 = arvore->direita;
			pAux1 = arvore->direita;
			
			while(pAux1->esquerda != NULL){
				pAux1 = pAux1->esquerda;
			}
			pAux1->esquerda = arvore->esquerda;
			delete arvore;
			return pAux2;
		}
	}
	else if(arvore->numero < numero){
		arvore->direita = remover(arvore->direita, numero);
	}
	else{
		arvore->esquerda = remover(arvore->esquerda, numero);
	}
	return arvore;
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
	
	int escolha, numero, achou;
	
	do{
		escolha = menu();
		
		switch(escolha){
			case 1:
				cout << "Digite o numero: ";
				cin >> numero;
				
				raiz = inserir(raiz, numero);
				cout << "Numero inserido na arvore" << endl;
				break;
			
			case 2:
				if (eVazia(raiz)){
					cout << "Arvore vazia!" << endl;
				}
				else{
					cout << "Digite o numero: ";
					cin >> numero;
					
					achou = 0;
					
					achou = consulta(raiz, numero, achou);
					
					if(achou = 0){
						cout << "Numero nao encontrado na arvore" << endl;
					}
					
					else{
						cout << "Numero encontrado na arvore" << endl;
					}
				}
				break;
				
			case 3:
				if (eVazia(raiz)){
					cout << "Arvore vazia!" << endl;
				}
				else{
					cout << "Listando os elementos da arvore em ordem";
					mostraEmOrdem(raiz);
					cout << endl;
					system("PAUSE");
				}
				break;
			
			case 4:
				if (eVazia(raiz)){
					cout << "Arvore vazia!" << endl;
				}
				else{
					cout << "Listando os elementos da arvore em pre ordem";
					mostraPreOrdem(raiz);
					cout << endl;
					system("PAUSE");
				}
				break;
				
			case 5:
				if (eVazia(raiz)){
					cout << "Arvore vazia!" << endl;
				}
				else{
					cout << "Listando os elementos da arvore em pos ordem";
					mostraPosOrdem(raiz);
					cout << endl;
					system("PAUSE");
				}
				break;
			
			case 6:
				if (eVazia(raiz)){
					cout << "Arvore vazia!" << endl;
				}
				else{
					cout << "Digite o numero que deseja excluir: ";
					cin >> numero;
					
					achou = 0;
					achou = consulta(raiz, numero, achou);
					
					if(achou = 0){
						cout << "Numero nao encontrado na arvore" << endl;
					}
					
					else{
						raiz = remover(raiz, numero);
						cout << "Numero excluido da arvore!" << endl;
					}
				}
				break;
			
			case 7:
				if (eVazia(raiz)){
					cout << "Arvore vazia!" << endl;
				}
				else{
					raiz = desalocar(raiz);
					cout << "Arvore esvaziada!";
				}
				break;
				
			default:
				cout << "Saindo..." << endl;
		}
	}while(escolha != 8);
	
	raiz = desalocar(raiz);
}
