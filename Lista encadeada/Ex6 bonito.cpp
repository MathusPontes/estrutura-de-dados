/* Faça um programa que implemente uma lista encadeada de números inteiros com
inserção de dados pelo usuário através de um menu. Escreva uma função que
verifique se esta lista está em ordem crescente e outra função que faça uma busca na
lista, dado um elemento passado pelo usuário. Faça versões recursiva e iterativa. */

#include <iostream>
#include <stdlib.h>
#include <locale.h>
#include <windows.h>

using namespace std;

typedef struct Noh{
	int numero;
	Noh *proximo;
}Noh;

typedef struct Lista{
	Noh *inicio, *fim;
	int tamanho;
}Lista;

int menu(){
	int opcao;
	do{
		system("cls");
		cout << endl << "MENU DE OPCOES" << endl;
		cout << "1 - Inserir no inicio da lista." << endl;
		cout << "2 - Inserir no fim da lista." << endl;
		cout << "3 - Imprimir toda a lista." << endl;
		cout << "4 - Remover da lista." << endl;
		cout << "5 - Esvaziar a lista." << endl;
        cout << "6 - Verificar se esta ordenada. (Interativa)" << endl;
        cout << "7 - Verificar se esta ordenada. (Recursiva)" << endl;
		cout << "8 - Procura numero na lista (Interativa)" << endl;
		cout << "9 - Procura numero na lista (Recursiva)" << endl;
		cout << "0 - Sair." << endl;
		
		cout << "Digite a sua escolha: ";
		cin >> opcao;
		
		cout << endl;
		
		if(opcao < 0 || opcao > 9){
			cout << "Opcao invalida!" << endl;
			system("pause");
		}
	}while(opcao < 0 || opcao > 9);
	
	return opcao;
}

bool eVazia(Lista *lst)
{
	if(lst->inicio == NULL)
		return true;
	return false;
}

void inserirInicio(Lista *lst, int numero)
{
	Noh *novo = new Noh();
	novo->numero = numero;
	
	if(eVazia(lst))
	{
		novo->proximo = NULL;
		lst->inicio = novo;
		lst->fim = novo;
	}
	else
	{
		novo->proximo = lst->inicio;
		lst->inicio = novo;
	}
	lst->tamanho++;
}

void inserirFim(Lista *lst, int numero)
{
	Noh *novo = new Noh();
	novo->numero = numero;
	novo->proximo = NULL;
	
	if(eVazia(lst))
	{
		lst->inicio= novo;
		lst->fim=novo;
	}
	else
	{
		lst->fim->proximo= novo;
		lst->fim = novo;
	}
	lst->tamanho++;
	
}

void imprime(Lista *lst)
{
	if(!eVazia(lst))
	{
		Noh* pAux  = lst->inicio;
		
		while(pAux != NULL)
		{
			cout << pAux->numero << " ";     //regiao numero apontada por pAux
			pAux = pAux->proximo;           // pAux vai apontar para o proximo e testa se é diferente de nulo
		}
		cout << endl << "Tamanho da lista: " << lst->tamanho << endl; 
		cout << endl << endl;
	}
	else
		cout << endl << "Lista vazia..." << endl << endl;
}

void remover(Lista *lst, int valor){
	
	if(!eVazia(lst)){
		
		Noh *pAux = lst->inicio;
		Noh *pApagar = NULL;// ponteiro para o nó a ser removido
		
		if(pAux != NULL && lst->inicio->numero == valor)
		{
			// remover o primeiro elemento
			pApagar = lst->inicio;
			lst->inicio = pApagar->proximo;
			if(lst->inicio == NULL)
				lst->fim = NULL;
		}
		else
		{
			//remover do meio ou final
			while(pAux != NULL && pAux->proximo != NULL && pAux->proximo->numero != valor)
				pAux = pAux->proximo;
				
			if(pAux != NULL && pAux->proximo != NULL)
			{
				pApagar = pAux->proximo;
				pAux->proximo =  pApagar->proximo;
				
				if(pAux->proximo == NULL)// se o ultimo elemento for removido
					lst->fim= pAux;
			}
		}
		if(pApagar)
		{
			delete(pApagar); //libera a memoria do nó
			lst->tamanho--;   //decrementa o tamanho da lista
		}
		
	}
	else
		cout << endl << "Lista Vazia..." << endl << endl;
}

void esvaziar(Lista *lst)
{
	if(!eVazia(lst))
	{
		Noh* pAux;
		
		while(lst->inicio != NULL)
		{
			pAux = lst->inicio;
			lst->inicio = lst->inicio->proximo;
			delete(pAux);
		}
		cout << "Lista esvaziada!" << endl;

	}
	else
		cout << endl << "Lista vazia..." << endl << endl;
}

bool esta_ordenada_interativo(Lista *lst) {
    if (lst->inicio != NULL){
        Noh *pAux = lst->inicio;
        while (pAux->proximo != NULL) {
            if (pAux->numero > pAux->proximo->numero) {
                return false;
            }
            pAux = pAux->proximo;
        }
    }
    return true;
}

bool esta_Ordenada_Recursivo(Noh *pAux){
    if(pAux == NULL || pAux->proximo == NULL) // se a lista estiver vazia ou tiver apenas um elemento, ela está ordenada
        return true;

    if(pAux->numero > pAux->proximo->numero) // se o valor do nó atual for maior que o valor do próximo nó, a lista não está ordenada
        return false;

    return esta_Ordenada_Recursivo(pAux->proximo); // caso contrário, verificamos o próximo par de nós
}

bool procura_iterativo(Lista *lst, int chave) {
    Noh *pAux = lst->inicio;
    while (pAux != NULL) {
        if (pAux->numero == chave) {
            return true;
        }
        pAux = pAux->proximo;
    }
    return false;
}

bool procura_recursivo(Noh *pAux, int chave) {
    if (pAux == NULL) {
        return false;
    }
    if (pAux->numero == chave) {
        return true;
    }
    return procura_recursivo(pAux->proximo, chave);
}

int main(){
	setlocale(LC_ALL, "Portuguese");

	Lista lista;
	system("color 0F");
	//inicializacao da lista;
	
	lista.inicio = NULL;
	lista.fim = NULL;
	lista.tamanho = 0;
	
	int escolha, numero, chave;
	
	do{
        escolha = menu();
        switch(escolha)
        {
            case 1:
                system("cls");
                cout << " Digite o numero a ser inserido no inicio da lista: ";
                cin >> numero;
                inserirInicio(&lista, numero);
                break;
            
            case 2:
                system("cls");
                cout << "Digite o numero a ser inserido no fim da lista: ";
                cin >> numero;
                inserirFim(&lista, numero);
                break;
                
            case 3:
                system("cls");
                cout << " 3 - Imprimindo toda a lista..." << endl;
                imprime(&lista);
                system("pause");
                break;
                
            case 4:
                system("cls");
                cout << " 4 - Digite o numero que quer remover da lista: ";
                cin >> numero;
                remover(&lista, numero);
                break;
            
            case 5:
                system("cls");
                cout << " 5 - Esvaziando a  lista..." <<endl;
                esvaziar(&lista);
                system("pause");
                break;
                
            case 6:
                system("cls");
                if (esta_ordenada_interativo(&lista)) {
                    cout << "A lista esta ordenada.\n";
                } else {
                    cout << "A lista nao esta ordenada.\n";
                }
                system("pause");
                break;
            
            case 7:
                system("cls");
                if (esta_Ordenada_Recursivo(lista.inicio)) {
                    cout << "A lista esta ordenada.\n";
                } else {
                    cout << "A lista nao esta ordenada.\n";
                }
                system("pause");
                break;

			case 8:
                system("cls");
				cout << "Informe o numero que deseja procurar na lista: ";
				cin >> chave;
                if (procura_iterativo(&lista, chave)) {
                    cout << "O numero esta na lista\n";
                } else {
                    cout << "O numero procurado nao esta na lista.\n";
                }
                system("pause");
                break;

			case 9:
				system("cls");
				cout << "Informe o numero que deseja procurar na lista: ";
				cin >> chave;
                if (procura_recursivo(lista.inicio, chave)) {
                    cout << "O numero esta na lista\n";
                } else {
                    cout << "O numero procurado nao esta na lista.\n";
                }
                system("pause");
                break;

            default:
                cout << "Saindo..." <<endl;
        }
    }while(escolha != 0);
}