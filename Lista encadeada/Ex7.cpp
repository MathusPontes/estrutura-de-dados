#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

// Função para inserir um novo elemento no final da lista encadeada
void insert(Node** head, int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = NULL;
    if (*head == NULL) {
        *head = newNode;
    }
    else {
        Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Função para encontrar o nó que contenha o menor valor
Node* findMin(Node* head) {
    if (head == NULL) {
        return NULL;
    }
    Node* minNode = head;
    while (head != NULL) {
        if (head->data < minNode->data) {
            minNode = head;
        }
        head = head->next;
    }
    return minNode;
}

// Função iterativa para verificar se duas listas encadeadas são iguais
bool isEqualIterative(Node* head1, Node* head2) {
    while (head1 != NULL && head2 != NULL) {
        if (head1->data != head2->data) {
            return false;
        }
        head1 = head1->next;
        head2 = head2->next;
    }
    return (head1 == NULL && head2 == NULL);
}

// Função recursiva para verificar se duas listas encadeadas são iguais
bool isEqualRecursive(Node* head1, Node* head2) {
    if (head1 == NULL && head2 == NULL) {
        return true;
    }
    if (head1 == NULL || head2 == NULL) {
        return false;
    }
    if (head1->data != head2->data) {
        return false;
    }
    return isEqualRecursive(head1->next, head2->next);
}

// Função para imprimir a lista encadeada
void printList(Node* head) {
    if (head == NULL) {
        cout << "Lista vazia." << endl;
    }
    else {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
}

int main() {
    Node* head1 = NULL;
    Node* head2 = NULL;
    int choice, value;
    do {
        cout << "Menu:" << endl;
        cout << "1. Inserir elemento na primeira lista" << endl;
        cout << "2. Inserir elemento na segunda lista" << endl;
        cout << "3. Encontrar o no que contenha o menor valor" << endl;
        cout << "4. Verificar se as duas listas sao iguais (versao iterativa)" << endl;
        cout << "5. Verificar se as duas listas sao iguais (versao recursiva)" << endl;
        cout << "6. Imprimir a primeira lista" << endl;
        cout << "7. Imprimir a segunda lista" << endl;
        cout << "0. Sair" << endl;
        cout << "Escolha uma opcao: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Digite o valor a ser inserido na primeira lista: ";
                cin >> value;
                insert(&head1, value);
                break;
            case 2:
                cout << "Digite o valor a ser inserido na segunda lista: ";
                cin >> value;
                insert(&head2, value);
                break;
            case 3:
                cout << "Menor valor da primeira lista: ";
                Node* minNode1 = findMin(head1);
                if (minNode1 == NULL) {
                    cout << "Lista vazia." << endl;
                }
                else {
                    cout << minNode1->data << endl;
                }
                cout << "Menor valor da segunda lista: ";
                Node* minNode2 = findMin(head2);
                if (minNode2 == NULL) {
                    cout << "Lista vazia." << endl;
                }
                else {
                    cout << minNode2->data << endl;
                }
                break;
            case 4:
                if (isEqualIterative(head1, head2)) {
                    cout << "As duas listas sao iguais." << endl;
                }
                else {
                    cout << "As duas listas sao diferentes." << endl;
                }
                break;
            case 5:
                if (isEqualRecursive(head1, head2)) {
                    cout << "As duas listas sao iguais." << endl;
                }
                else {
                    cout << "As duas listas sao diferentes." << endl;
                }
                break;
            case 6:
                cout << "Primeira lista: ";
                printList(head1);
                break;
            case 7:
                cout << "Segunda lista: ";
                printList(head2);
                break;
            case 0:
                cout << "Saindo do programa..." << endl;
                break;
            default:
                cout << "Opcao invalida. Tente novamente." << endl;
                break;
        }
    } while (choice != 0);
    return 0;
}