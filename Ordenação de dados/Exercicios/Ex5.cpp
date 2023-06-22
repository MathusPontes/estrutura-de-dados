#include <iostream>
#include <ctime>
using namespace std;

void insertionSort(int arr[], int n) {
    for(int i=1; i<n; i++) {
        int key = arr[i];
        int j = i-1;
        while(j>=0 && arr[j]>key) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

void selectionSort(int arr[], int n) {
    for(int i=0; i<n-1; i++) {
        int minIndex = i;
        for(int j=i+1; j<n; j++) {
            if(arr[j] > arr[minIndex]) {
                minIndex = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}

void printArray(int arr[], int n) {
    for(int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    srand(time(NULL)); // inicializa o gerador de números aleatórios

    int mat[4][4];

    // preenche a matriz com números aleatórios entre 0 e 99
    for(int i=0; i<4; i++) {
        for(int j=0; j<4; j++) {
            mat[i][j] = rand() % 100;
        }
    }

    // imprime a matriz original
    cout << "Matriz original:" << endl;
    for(int i=0; i<4; i++) {
        for(int j=0; j<4; j++) {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }

    int arr[16];
    int k = 0;

    // copia os elementos da matriz para o array
    for(int i=0; i<4; i++) {
        for(int j=0; j<4; j++) {
            arr[k] = mat[i][j];
            k++;
        }
    }

    int opcao;

    do {
        cout << "Escolha uma opcao: " << endl;
        cout << "1. Colocar os elementos em ordem crescente" << endl;
        cout << "2. Colocar os elementos em ordem decrescente" << endl;
        cout << "0. Sair" << endl;
        cin >> opcao;

        switch(opcao) {
            case 1:
                insertionSort(arr, 16);
                cout << "Elementos em ordem crescente:" << endl;
                printArray(arr, 16);
                break;
            case 2:
                selectionSort(arr, 16);
                cout << "Elementos em ordem decrescente:" << endl;
                printArray(arr, 16);
                break;
            case 0:
                cout << "Saindo..." << endl;
                break;
            default:
                cout << "Opcao invalida!" << endl;
                break;
        }

    } while(opcao != 0);

    return 0;
}