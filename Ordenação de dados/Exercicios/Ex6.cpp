#include <iostream>
#include <string>

using namespace std;

// Definindo a estrutura para armazenar os dados
struct Pessoa {
    string nome;
    int idade;
    char sexo;
};

// Função para realizar o quick sort em ordem alfabética de nome
void quickSortNome(Pessoa *p, int esq, int dir) {
    int i = esq, j = dir;
    Pessoa temp;
    Pessoa pivo = p[(esq + dir) / 2];

    while (i <= j) {
        while (p[i].nome < pivo.nome) {
            i++;
        }
        while (p[j].nome > pivo.nome) {
            j--;
        }
        if (i <= j) {
            temp = p[i];
            p[i] = p[j];
            p[j] = temp;
            i++;
            j--;
        }
    }

    if (esq < j) {
        quickSortNome(p, esq, j);
    }
    if (i < dir) {
        quickSortNome(p, i, dir);
    }
}

// Função para realizar o bubble sort em ordem decrescente de idade
void bubbleSortIdade(Pessoa *p, int n) {
    Pessoa temp;

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (p[j].idade < p[j + 1].idade) {
                temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }
}

int main() {
    // Definindo o vetor de pessoas
    Pessoa pessoas[5];

    // Preenchendo o vetor com os dados
    pessoas[0] = {"João", 30, 'M'};
    pessoas[1] = {"Maria", 25, 'F'};
    pessoas[2] = {"Pedro", 40, 'M'};
    pessoas[3] = {"Ana", 20, 'F'};
    pessoas[4] = {"Lucas", 35, 'M'};

    // Ordenando o vetor em ordem alfabética de nome
    quickSortNome(pessoas, 0, 4);

    // Imprimindo os dados em ordem alfabética de nome
    cout << "Dados em ordem alfabética de nome:" << endl;
    for (int i = 0; i < 5; i++) {
        cout << pessoas[i].nome << ", " << pessoas[i].idade << ", " << pessoas[i].sexo << endl;
    }

    // Ordenando o vetor em ordem decrescente de idade
    bubbleSortIdade(pessoas, 5);

    // Imprimindo os dados em ordem decrescente de idade
    cout << endl << "Dados em ordem decrescente de idade:" << endl;
    for (int i = 0; i < 5; i++) {
        cout << pessoas[i].nome << ", " << pessoas[i].idade << ", " << pessoas[i].sexo << endl;
    }

    return 0;
}
