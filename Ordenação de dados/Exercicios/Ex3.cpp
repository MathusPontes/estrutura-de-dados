#include <iostream>
#include <string>
using namespace std;

const int TAM = 3;

// Estrutura do aluno
struct Aluno {
    string nome;
    float nota1;
    float nota2;
};

// Função que calcula a média ponderada das notas do aluno
float mediaPonderada(Aluno a) {
    return (a.nota1*2 + a.nota2*3)/5;
}

// Bubble Sort
void bubbleSort(Aluno* alunos) {
    for(int i=0; i<TAM-1; i++) {
        for(int j=0; j<TAM-i-1; j++) {
            if(mediaPonderada(alunos[j]) < mediaPonderada(alunos[j+1])) {
                Aluno temp = alunos[j];
                alunos[j] = alunos[j+1];
                alunos[j+1] = temp;
            }
        }
    }
}

// Insertion Sort
void insertionSort(Aluno* alunos) {
    for(int i=1; i<TAM; i++) {
        Aluno temp = alunos[i];
        int j = i-1;
        while(j >= 0 && alunos[j].nota1 > temp.nota1) {
            alunos[j+1] = alunos[j];
            j--;
        }
        alunos[j+1] = temp;
    }
}

// Selection Sort
void selectionSort(Aluno* alunos,int n) {
    for(int i=0; i<n-1; i++) {
        int minIndex = i;
        for(int j=i+1; j<TAM; j++) {
            if(alunos[j].nome < alunos[minIndex].nome) {
                minIndex = j;
            }
        }
        if(minIndex != i) {
            Aluno temp = alunos[i];
            alunos[i] = alunos[minIndex];
            alunos[minIndex] = temp;
        }
    }
}

int main() {
    // Cadastrar os alunos
    Aluno alunos[TAM];
    for(int i=0; i<TAM; i++) {
        cout << "Cadastro do aluno " << i+1 << endl;
        cout << "Nome: ";
        cin >> alunos[i].nome;
        cout << "Nota 1: ";
        cin >> alunos[i].nota1;
        cout << "Nota 2: ";
        cin >> alunos[i].nota2;
    }
    
    // Bubble Sort
    cout << endl << "Alunos ordenados pela media ponderada (bubble sort):" << endl;
    bubbleSort(alunos);
    for(int i=0; i<TAM; i++) {
        cout << alunos[i].nome << " - Media ponderada: " << mediaPonderada(alunos[i]) << endl;
    }
    
    // Insertion Sort
    cout << endl << "Alunos ordenados pela nota1 (insertion sort):" << endl;
    insertionSort(alunos);
    for(int i=0; i<TAM; i++) {
        cout << alunos[i].nome << " - Nota1: " << alunos[i].nota1 << endl;
    }
    
    // Selection Sort
    cout << endl << "Alunos reprovados em ordem alfabetica (selection sort):" << endl;
    Aluno reprovados[TAM];
    int numReprovados = 0;
    for(int i=0; i<8; i++) {
        if(mediaPonderada(alunos[i]) < 7) {
            reprovados[numReprovados] = alunos[i];
            numReprovados++;
        }
    }
    selectionSort(reprovados, numReprovados);
    for(int i=0; i<numReprovados; i++) {
        cout << reprovados[i].nome << endl;
    }

return 0;
}