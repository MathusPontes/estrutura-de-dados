/*
Faça um programa que implemente uma lista duplamente encadeada de números
inteiros com inserção de dados pelo usuário através de um menu. Escreva uma
função que remova da lista a célula apontada por p e outra função que insira uma
nova célula com conteúdo x nesta lista duplamente encadeada logo após a célula
apontada por p. Dê duas soluções: uma iterativa e uma recursiva
*/


#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};

Node* head = nullptr;

void insertIterative(int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->prev = nullptr;
    newNode->next = nullptr;

    if (head == nullptr) {
        head = newNode;
    } else {
        Node* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
        newNode->prev = current;
    }
    cout << "Elemento " << value << " inserido na lista." << endl;
}

Node* insertRecursive(Node* current, int value) {
    if (current == nullptr) {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->prev = nullptr;
        newNode->next = nullptr;
        cout << "Elemento " << value << " inserido na lista." << endl;
        return newNode;
    }

    current->next = insertRecursive(current->next, value);
    current->next->prev = current;
    return current;
}

void removeIterative(Node* p) {
    if (p == nullptr) {
        cout << "Noh invalido." << endl;
        return;
    }

    if (p == head) {
        head = p->next;
        if (head != nullptr) {
            head->prev = nullptr;
        }
        delete p;
    } else {
        p->prev->next = p->next;
        if (p->next != nullptr) {
            p->next->prev = p->prev;
        }
        delete p;
    }
    cout << "Noh removido da lista." << endl;
}

void removeRecursive(Node* p) {
    if (p == nullptr) {
        cout << "Noh invalido." << endl;
        return;
    }

    if (p == head) {
        head = p->next;
        if (head != nullptr) {
            head->prev = nullptr;
        }
        delete p;
    } else {
        p->prev->next = p->next;
        if (p->next != nullptr) {
            p->next->prev = p->prev;
        }
        delete p;
    }
    cout << "Noh removido da lista." << endl;
}

void display() {
    Node* current = head;
    if (current == nullptr) {
        cout << "Noh invalido." << endl;
        return;
    }
    cout << "Lista: ";
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

int main() {
    int choice, value;
    Node* node = nullptr;

    while (true) {
        system("cls");
        cout << "MENU" << endl;
        cout << "1- Inserir elemento (iterativo)" << endl;
        cout << "2- Inserir elemento (recursivo)" << endl;
        cout << "3- Remover elemento (iterativo)" << endl;
        cout << "4- Remover elemento (recursivo)" << endl;
        cout << "5- Exibir lista" << endl;
        cout << "6- Sair" << endl;
        cout << "Digite a opcao desejada: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Digite o elemento a ser inserido: ";
                cin >> value;
                insertIterative(value);
                break;
            case 2:
                cout << "Digite o elemento a ser inserido: ";
                cin >> value;
                head = insertRecursive(head, value);
                break;
            case 3:
                cout << "Digite o elemento a ser removido (iterativo): ";
                cin >> value;
                node = head;
                while (node != nullptr && node->data != value) {
                    node = node->next;
                }
                removeIterative(node);
                break;
            case 4:
                cout << "Digite o elemento a ser removido (recursivo): ";
                cin >> value;
                node = head;
                while (node != nullptr && node->data != value) {
                    node = node->next;
                }
                removeRecursive(node);
                break;
            case 5:
                display();
                break;
            case 6:
                return 0;
            default:
                cout << "Opcao invalida." << endl;
        }
        cout << endl;
        system("pause");
    }
}

