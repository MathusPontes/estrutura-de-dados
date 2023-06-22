#include <iostream>
#include <cmath>

using namespace std;

typedef struct Arvore {
    int numero;
    Arvore* esquerda;
    Arvore* direita;
} Arvore;

int menu() {
    int opcao;
    do {
        system("cls");
        cout << endl << "MENU DE OPCOES" << endl;
        cout << "1 - Inserir numero na arvore." << endl;
        cout << "2 - Mostrar altura da arvore." << endl;
        cout << "3 - Mostrar o nivel de um noh." << endl;
        cout << "4 - Sair." << endl;

        cout << "Digite a sua escolha: ";
        cin >> opcao;

        cout << endl;

        if (opcao < 1 || opcao > 4) {
            cout << "Opcao invalida!" << endl;
            system("pause");
        }
    } while (opcao < 1 || opcao > 4);

    return opcao;
}

Arvore* inserir(Arvore* arvore, int numero) {
    if (arvore == NULL) {
        arvore = new Arvore();
        arvore->numero = numero;
        arvore->esquerda = NULL;
        arvore->direita = NULL;
    } 
	else if (numero < arvore->numero) {
        arvore->esquerda = inserir(arvore->esquerda, numero);
    } 
	else {
        arvore->direita = inserir(arvore->direita, numero);
    }

    return arvore;
}

int altura(Arvore* arvore) {
    if (arvore == NULL) {
        return -1;
    } 
	else {
        int esquerda = altura(arvore->esquerda);
        int direita = altura(arvore->direita);
        if (esquerda > direita) {
            return esquerda + 1;
        } 
		else {
            return direita + 1;
        }
    }
}

int nivel(Arvore* arvore, int numero, int nivelAtual) {
    if (arvore == NULL) {
        return -1; // Nó não encontrado
    }
    if (arvore->numero == numero) {
        return nivelAtual;
    }
    int nivelEsquerda = nivel(arvore->esquerda, numero, nivelAtual + 1);
    if (nivelEsquerda != -1) {
        return nivelEsquerda;
    }
    return nivel(arvore->direita, numero, nivelAtual + 1);
}

void desalocar(Arvore* arvore) {
    if (arvore != NULL) {
        desalocar(arvore->esquerda);
        desalocar(arvore->direita);
        delete arvore;
    }
}

bool eVazia(Arvore* arvore) {
    return (arvore == NULL);
}

int main() {
    Arvore* raiz = NULL;

    int escolha, numero;

    do {
        escolha = menu();

        switch (escolha) {
            case 1:
                cout << "Digite o numero: ";
                cin >> numero;

                raiz = inserir(raiz, numero);
                cout << "Numero inserido na arvore" << endl;
                system("PAUSE");
                break;

            case 2:
                if (eVazia(raiz)) {
                    cout << "Arvore vazia!" << endl;
                } 
				else {
                    cout << "A altura da arvore eh: " << altura(raiz) << endl;
                }
                system("PAUSE");
                break;

            case 3:
                if (eVazia(raiz)) {
                    cout << "Arvore vazia!" << endl;
                } 
				else {
                    cout << "Digite o numero: ";
                    cin >> numero;

                    int nivelNo = nivel(raiz, numero, 0);
                    if (nivelNo == -1) {
                        cout << "Numero nao encontrado na arvore" << endl;
                    } 
					else {
                        cout << "O nivel do noh " << numero << " eh: " << nivelNo << endl;
                    }
                }
                system("PAUSE");
                break;

            default:
                cout << "Saindo..." << endl;
        }
    } while (escolha != 4);

    desalocar(raiz);
    return 0;
}