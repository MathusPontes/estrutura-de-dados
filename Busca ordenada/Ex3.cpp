#include <iostream>
#include <cctype>

using namespace std;

int main()
{
    const int n = 10; // tamanho do vetor
    char v[n] = {'a', 'b', 'c', 'd', 'e', '1', '2', '3', '4', '5'}; // vetor de exemplo

    char c; // caractere a ser buscado
    cout << "Digite o caractere a ser buscado: ";
    cin >> c;

    // converter letra para minúsculo caso necessário
    if (isalpha(c)) {
        c = tolower(c);
    }

    // busca binária
    int inicio = 0;
    int fim = n - 1;
    int meio;

    while (inicio <= fim) {
        meio = (inicio + fim) / 2;
        if (v[meio] == c) {
            cout << "Caractere encontrado na posição " << meio << endl;
            return 0;
        } else if (v[meio] < c) {
            inicio = meio + 1;
        } else {
            fim = meio - 1;
        }
    }

    cout << "Caractere não encontrado" << endl;
    return 0;
}