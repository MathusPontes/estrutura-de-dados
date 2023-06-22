#include <iostream>

using namespace std;

struct Produto {
    int codigo;
    float preco;
    int quantidade;
    Produto* prox;
};

void cadastrarProduto(Produto** lista, int codigo, float preco, int quantidade) {
    Produto* novoProduto = new Produto;
    novoProduto->codigo = codigo;
    novoProduto->preco = preco;
    novoProduto->quantidade = quantidade;
    novoProduto->prox = *lista;
    *lista = novoProduto;
}

void aplicarDesconto(Produto* lista, float taxaDesconto) {
    while (lista != NULL) {
        lista->preco = lista->preco * (1 - taxaDesconto / 100);
        lista = lista->prox;
    }
}

void mostrarRelatorio(Produto* lista) {
    int qtdProdutosSuperior500 = 0;
    cout << "Codigo \t Preco" << endl;
    while (lista != NULL) {
        cout << lista->codigo << "\t" << lista->preco << endl;
        if (lista->quantidade > 500) {
            qtdProdutosSuperior500++;
        }
        lista = lista->prox;
    }
    cout << "Quantidade de produtos com quantidade estocada superior a 500: " << qtdProdutosSuperior500 << endl;
}

int main() {
    Produto* lista = NULL;

    // cadastra 5 produtos
    cadastrarProduto(&lista, 1, 10.0, 100);
    cadastrarProduto(&lista, 2, 20.0, 200);
    cadastrarProduto(&lista, 3, 30.0, 300);
    cadastrarProduto(&lista, 4, 40.0, 400);
    cadastrarProduto(&lista, 5, 50.0, 500);

    // recebe a taxa de desconto do usuário
    float taxaDesconto;
    cout << "Digite a taxa de desconto (em %): ";
    cin >> taxaDesconto;

    // aplica o desconto aos produtos
    aplicarDesconto(lista, taxaDesconto);

    // mostra o relatório
    mostrarRelatorio(lista);

    return 0;
}