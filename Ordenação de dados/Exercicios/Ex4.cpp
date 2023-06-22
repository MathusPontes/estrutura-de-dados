#include <iostream>
using namespace std;

void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
 
    int L[n1], R[n2];
 
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
 
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
 
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
 
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}
 
void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
 
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
 
        merge(arr, l, m, r);
    }
}
 
int main() {
    int tamanho = 20;
    int vetor1[tamanho], vetor2[tamanho], vetor3[tamanho * 2];
 
    cout << "Digite os elementos do primeiro vetor:\n";
    for (int i = 0; i < tamanho; i++) {
        cout << "Digite o " << i + 1 << "o elemento: ";
        cin >> vetor1[i];
    }
 
    cout << "\nDigite os elementos do segundo vetor:\n";
    for (int i = 0; i < tamanho; i++) {
        cout << "Digite o " << i + 1 << "o elemento: ";
        cin >> vetor2[i];
    }
 
    // Copiando os elementos dos vetores 1 e 2 para o vetor 3
    for (int i = 0; i < tamanho; i++) {
        vetor3[i] = vetor1[i];
        vetor3[i + tamanho] = vetor2[i];
    }
 
    // Ordenando o vetor 3 com o Merge Sort
    mergeSort(vetor3, 0, tamanho * 2 - 1);
 
    cout << "\nO vetor resultante em ordem crescente eh:\n";
    for (int i = 0; i < tamanho * 2; i++) {
        cout << vetor3[i] << " ";
    }
 
    cout << endl;
 
    return 0;
}
