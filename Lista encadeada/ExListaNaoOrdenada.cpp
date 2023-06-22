//exemplo lista simples NÃO ordenada
#include <iostream>

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
		cout << endl << "MENU DE OPCOES" << endl;
		cout << "1 - Inserir no inicio da lista." << endl;
		cout << "2 - Inserir no fim da lista." << endl;
		cout << "3 - Imprimir toda a  lista." << endl;
		cout << "4 - Remover  da lista." << endl;
		cout << "5 - Esvaziar a  lista." << endl;
		cout << "6 - Sair." << endl;
		
		cout << "Digite a sua escolha: ";
		cin >> opcao;
		
		cout << endl;
		
		if(opcao < 1 || opcao > 6)
			cout << "Opcao invalida!" << endl;	
	}while(opcao < 1 || opcao > 6);
	
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

int main(){
	
	Lista lista;
	
	//inicializacao da lista;
	
	lista.inicio = NULL;
	lista.fim = NULL;
	lista.tamanho = 0;
	
	int escolha, numero;
	
	do{
        escolha = menu();
        switch(escolha)
        {
            case 1:
                cout << " Digite o numero a ser inserido no inicio da lista: " << endl;
                cin >> numero;
                inserirInicio(&lista, numero);
                break;
            
            case 2:
                cout << " Digite o numero a ser inserido no fim da lista: " << endl;
                cin >> numero;
                inserirFim(&lista, numero);
                break;
                
            case 3:
                cout << " 3 - Imprimindo toda a lista..." << endl;
                imprime(&lista);
                break;
                
            case 4:
                cout << " 4 - Digite o numero que quer remover da lista..." <<endl;
                cin >> numero;
                remover(&lista, numero);
                break;
            
            case 5:
                cout << " 5 - Esvaziando a  lista..." <<endl;
                esvaziar(&lista);
                break;
                
            default:
                cout << " 6 - Saindo..." <<endl;
        }
    }while(escolha != 6);
}