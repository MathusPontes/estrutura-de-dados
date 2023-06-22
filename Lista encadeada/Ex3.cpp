#include <iostream>
#include <string>

using namespace std;

struct Aluno {
    int numero;
    string nome;
    Aluno* proximo;
};

struct Nota {
    int numeroAluno;
    double valor;
    Nota* proxima;
};

void cadastrarAluno(Aluno*& topo, int& numeroAluno, const string& nome) {
    Aluno* novoAluno = new Aluno;
    novoAluno->numero = numeroAluno;
    novoAluno->nome = nome;
    novoAluno->proximo = topo;
    topo = novoAluno;
    numeroAluno++;
    cout << "Aluno cadastrado." << endl;
}

void cadastrarNota(Nota*& inicio, int numeroAluno, double nota) {
    Nota* novaNota = new Nota;
    novaNota->numeroAluno = numeroAluno;
    novaNota->valor = nota;
    novaNota->proxima = nullptr;

    if (inicio == nullptr) {
        inicio = novaNota;
    } else {
        Nota* atual = inicio;
        while (atual->proxima != nullptr) {
            atual = atual->proxima;
        }
        atual->proxima = novaNota;
    }
    cout << "Nota cadastrada." << endl;
}

double calcularMedia(Nota* inicio, int numeroAluno) {
    Nota* atual = inicio;
    double soma = 0.0;
    int contador = 0;

    while (atual != nullptr) {
        if (atual->numeroAluno == numeroAluno) {
            soma += atual->valor;
            contador++;
        }
        atual = atual->proxima;
    }

    if (contador == 0) {
        cout << "Aluno sem notas." << endl;
        return 0.0;
    } else {
        double media = soma / contador;
        cout << "Media do aluno = " << media << endl;
        return media;
    }
}

void listarAlunosSemNotas(Aluno* topo, Nota* inicio) {
    Aluno* atual = topo;
    bool possuiNota;

    while (atual != nullptr) {
        possuiNota = false;
        Nota* notaAtual = inicio;
        while (notaAtual != nullptr) {
            if (notaAtual->numeroAluno == atual->numero) {
                possuiNota = true;
                break;
            }
            notaAtual = notaAtual->proxima;
        }
        if (!possuiNota) {
            cout << atual->nome << endl;
        }
        atual = atual->proximo;
    }

    if (topo == nullptr) {
        cout << "Todos os alunos possuem notas." << endl;
    }
}

void excluirAluno(Aluno*& topo, Nota*& inicio, int numeroAluno) {
    Aluno* alunoAtual = topo;
    Aluno* alunoAnterior = nullptr;

    while (alunoAtual != nullptr) {
        if (alunoAtual->numero == numeroAluno) {
            Nota* notaAtual = inicio;
            bool possuiNota = false;

            while (notaAtual != nullptr) {
                if (notaAtual->numeroAluno == numeroAluno) {
                    possuiNota = true;
                    break;
                }
                notaAtual = notaAtual->proxima;
            }

            if (possuiNota) {
                cout << "Este aluno possui notas, logo, nao podera ser excluído." << endl;
                return;
            }

            if (alunoAnterior == nullptr) {
                topo = alunoAtual->proximo;
            } else {
                alunoAnterior->proximo = alunoAtual->proximo;
            }

            delete alunoAtual;
            cout << "Aluno excluido." << endl;
            return;
        }

        alunoAnterior = alunoAtual;
        alunoAtual = alunoAtual->proximo;
    }

    cout << "Aluno nao cadastrado." << endl;
}

void excluirNota(Nota*& inicio) {
    if (inicio == nullptr) {
        cout << "Fila vazia." << endl;
    } else {
        Nota* notaExcluida = inicio;
        inicio = inicio->proxima;
        delete notaExcluida;
        cout << "Nota excluida." << endl;
    }
}

void exibirMenu() {
    cout << "MENU" << endl;
    cout << "1- Cadastrar aluno" << endl;
    cout << "2- Cadastrar nota" << endl;
    cout << "3- Calcular media de um aluno" << endl;
    cout << "4- Listar os nomes dos alunos sem notas" << endl;
    cout << "5- Excluir aluno" << endl;
    cout << "6- Excluir nota" << endl;
    cout << "7- Sair" << endl;
    cout << "Digite a opcao desejada: ";
}

int main() {
    Aluno* topo = nullptr;
    Nota* inicio = nullptr;
    int numeroAluno = 1;

    while (true) {
        system("cls");
        exibirMenu();
        int opcao;
        cin >> opcao;

        switch (opcao) {
            case 1: {
                string nome;
                cout << "Digite o nome do aluno: ";
                cin.ignore();
                getline(cin, nome);
                cadastrarAluno(topo, numeroAluno, nome);
                break;
            }
            case 2: {
                int numeroAluno;
                double nota;
                cout << "Digite o numero do aluno: ";
                cin >> numeroAluno;
                cout << "Digite a nota: ";
                cin >> nota;
                cadastrarNota(inicio, numeroAluno, nota);
                break;
            }
            case 3: {
                int numeroAluno;
                cout << "Digite o numero do aluno: ";
                cin >> numeroAluno;
                Aluno* alunoAtual = topo;
                bool alunoCadastrado = false;

                while (alunoAtual != nullptr) {
                    if (alunoAtual->numero == numeroAluno) {
                        cout << "Nome: " << alunoAtual->nome << endl;
                        calcularMedia(inicio, numeroAluno);
                        alunoCadastrado = true;
                        break;
                    }
                    alunoAtual = alunoAtual->proximo;
                }

                if (!alunoCadastrado) {
                    cout << "Aluno nao cadastrado." << endl;
                }
                break;
            }
            case 4:
                cout << "A listagem dos nomes sem nota: " << endl;
                listarAlunosSemNotas(topo, inicio);
                break;
            case 5: {
                int numeroAluno;
                cout << "Digite o numero do aluno: ";
                cin >> numeroAluno;
                excluirAluno(topo, inicio, numeroAluno);
                break;
            }
            case 6:
                excluirNota(inicio);
                break;
            case 7:
                return 0;
            default:
                cout << "Opcao invalida." << endl;
        }

        cout << endl;
        system("pause");
    }
}