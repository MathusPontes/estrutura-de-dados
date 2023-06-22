#include <iostream>
#include <string.h>
#include <stdlib.h>

using namespace std;

const int TAM = 5;

struct Funcionario{
	string nome;
	float salario;
};

void cabecalho(){
	cout << "#####################################";
	cout << "\n#      SMART FOLHA DE PAGAMENTO     #";
	cout << "\n#####################################";
}

void entrada_de_dados (struct Funcionario *vFuncionario){
	int i;
	
	struct Funcionario *pAux = vFuncionario;
	
	for (i=0; i<TAM; i++){
		cout << "\nDigite o nome do " << i+1 << "o. funcionario: ";
		_flushall();
		getline(cin,pAux->nome);
		
		cout << "\tSalario: ";
		cin >> pAux->salario;
		pAux = pAux + 1;
	}
	
}

int menu(){
	int escolha;
	
	do{
		cout << "\n1 - Ordenar por salario (crescente)." << endl;
		cout << "2 - Ordenar por salario (decrescente)." << endl;
		cout << "3 - Ordenar por nome (crescente)." << endl;
		cout << "0 - Sair." << endl << endl;
		
		cout << "Digite sua escolha: ";
		cin >> escolha;
		if (escolha < 0 || escolha > 3){
			cout << "\tValor invalido!" << endl;
		}
	}while (escolha < 0 || escolha > 3);
	
	return escolha;
}

void imprime_vetor(struct Funcionario *vFuncionario){
	int i;
	struct Funcionario *pAux = vFuncionario;
	
	cout << "NOME\t\tSALARIO" << endl;
	
	for (i=0; i<TAM; i++){
		cout << pAux->nome << "\t\t" << pAux->salario << endl;
		pAux = pAux + 1;
	}
	cout << endl;
}

void bubblesort_v0_C (struct Funcionario *vfuncionarios){
	int i, n;
	float aux_salario;
	string aux_nome;
	
	for(n=1; n<=TAM; n++){
		for(i=0; i<=TAM-2; i++){
			if (vfuncionarios[i].salario > vfuncionarios[i+1].salario){
				
				aux_salario = vfuncionarios[i].salario;
				vfuncionarios[i].salario = vfuncionarios[i+1].salario;
				vfuncionarios[i+1].salario = aux_salario;
				
				aux_nome = vfuncionarios[i].nome;
				vfuncionarios[i].nome = vfuncionarios[i+1].nome;
				vfuncionarios[i+1].nome = aux_nome;
			}
		}
	}
}

void bubblesort_v2_D (struct Funcionario *vfuncionarios){
	int i, n, troca;
	float aux_salario;
	string aux_nome;
	
	n = 1;
	troca = 1;
	
	while (n<=TAM && troca == 1){
		troca = 0;
		
		for (i = 0; i<=TAM-2; i++){
			if(vfuncionarios[i].salario < vfuncionarios[i+1].salario){
				
				troca = 1;
				
				aux_salario = vfuncionarios[i].salario;
				vfuncionarios[i].salario = vfuncionarios[i+1].salario;
				vfuncionarios[i+1].salario = aux_salario;
				
				aux_nome = vfuncionarios[i].nome;
				vfuncionarios[i].nome = vfuncionarios[i+1].nome;
				vfuncionarios[i+1].nome = aux_nome;
			}
		}
		n = n+1;
	}
}

void bubblesort_v1_C (struct Funcionario *vfuncionarios){
	int i, j;
	float aux_salario;
	string aux_nome;
	
	for (j=1; j<=TAM-1; j++){
		for (i=TAM-1; i>=j; i--){
			if(vfuncionarios[i].nome < vfuncionarios[i-1].nome){
				aux_salario = vfuncionarios[i].salario;
				vfuncionarios[i].salario = vfuncionarios[i-1].salario;
				vfuncionarios[i-1].salario = aux_salario;
				
				aux_nome = vfuncionarios[i].nome;
				vfuncionarios[i].nome = vfuncionarios[i-1].nome;
				vfuncionarios[i-1].nome = aux_nome;
			}
		}
	}
}

int main (){
	struct Funcionario folha[TAM];
	int opcao;
	
	cabecalho();
	
	entrada_de_dados(folha);
	
	cout << endl << "vetor original: " << endl;
	imprime_vetor(folha);

	system("PAUSE");
	system("cls");

	cabecalho();
	do{
		opcao = menu();
	
		switch (opcao)
		{
		case 1:
			cout << "Ordenando dados por salario de forma crescente..." << endl;
			bubblesort_v0_C (folha);
			cout << endl << "Vetor ordenado" << endl;
			imprime_vetor(folha);
		break;
			
		case 2:
			cout << "Ordenando dados por salario de forma decrescente..." << endl;
			bubblesort_v2_D (folha);
			cout << endl << "Vetor ordenado" << endl;
			imprime_vetor(folha);
		break;
		
		case 3:
			cout << "Ordenando dados por nome de forma crescente..." << endl;
			bubblesort_v1_C (folha);
			cout << endl << "Vetor ordenado" << endl;
			imprime_vetor(folha);
		break;
		
		default:
			cout << "Saindo..." << endl;
		}
	} while (opcao != 0);
	return 0;
} 

