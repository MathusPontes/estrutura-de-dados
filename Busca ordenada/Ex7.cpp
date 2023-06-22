/* Para implementar uma versão generalizada da busca binária para matrizes, podemos tratar a matriz como um 
vetor unidimensional e fazer a busca normalmente. Para isso, podemos mapear as coordenadas (i, j) da 
matriz para um índice k do vetor unidimensional usando a fórmula k = i * n + j, onde n é o número de 
colunas da matriz.

Em seguida, podemos aplicar a busca binária normalmente no vetor, substituindo as comparações com valores da 
matriz pelas correspondentes no vetor. Para isso, precisamos também passar como argumento o número de 
colunas da matriz para que possamos calcular o índice correto. */

#include <iostream>

using namespace std;

int buscaBinaria(int mat[3][3], int m, int n, int valor) {
    int esquerda = 0;
    int direita = m * n - 1;
    while (esquerda <= direita) {
        int meio = (esquerda + direita) / 2;
        int i = meio / n;
        int j = meio % n;
        if (mat[i][j] == valor) {
            return meio;
        } else if (mat[i][j] < valor) {
            esquerda = meio + 1;
        } else {
            direita = meio - 1;
        }
    }
    return -1;
}

int main() {
    const int m = 3;
    const int n = 3;
    int mat[m][n] = {{1, 3, 5}, {7, 9, 11}, {13, 15, 17}};

    int valorBusca = 9;
    int indice = buscaBinaria(mat, m, n, valorBusca);
    if (indice != -1) {
        int i = indice / n;
        int j = indice % n;
        cout << "O valor " << valorBusca << " foi encontrado na posição (" << i << ", " << j << ")." << endl;
    } else {
        cout << "O valor " << valorBusca << " não foi encontrado." << endl;
    }

    return 0;
}