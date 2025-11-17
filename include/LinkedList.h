#ifndef __LINKEDLIST__
#define __LINKEDLIST__

#include <iostream>
using namespace std;

// Node бүтэц - жагсаалтын элемент
template <typename T>
struct Node {
    T data;
    Node<T>* next;
    
    Node(T value) : data(value), next(nullptr) {}
};

// LinkedList template класс
template <typename T>
class LinkedList {
private:
    Node<T>* head;
    int len;

public:
    // Байгуулагч
    LinkedList() : head(nullptr), len(0) {}

    // Устгагч
    ~LinkedList() {
        while (head != nullptr) {
            Node<T>* temp = head;
            head = head->next;
            delete temp;
        }
        len = 0;
    }

    // Жагсаалтын сүүлд элемент нэмнэ
    void add(T t) {
        Node<T>* newNode = new Node<T>(t);
        
        if (head == nullptr) {
            head = newNode;
        } else {
            Node<T>* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
        }
        len++;
    }

    // index - дүгээрт элемент оруулна
    void insert(T t, int index) {
        if (index < 0 || index > len) {
            cout << "Invalid index!" << endl;
            return;
        }

        Node<T>* newNode = new Node<T>(t);

        if (index == 0) {
            newNode->next = head;
            head = newNode;
        } else {
            Node<T>* current = head;
            for (int i = 0; i < index - 1; i++) {
                current = current->next;
            }
            newNode->next = current->next;
            current->next = newNode;
        }
        len++;
    }

    // index - р элементийн утгыг буцаана
    T get(int index) {
        if (index < 0 || index >= len) {
            cout << "Invalid index!" << endl;
            return T();
        }

        Node<T>* current = head;
        for (int i = 0; i < index; i++) {
            current = current->next;
        }
        return current->data;
    }

    // index - р элементийг устгана
    void deleteAt(int index) {
        if (index < 0 || index >= len) {
            cout << "Invalid index!" << endl;
            return;
        }

        Node<T>* temp;

        if (index == 0) {
            temp = head;
            head = head->next;
            delete temp;
        } else {
            Node<T>* current = head;
            for (int i = 0; i < index - 1; i++) {
                current = current->next;
            }
            temp = current->next;
            current->next = temp->next;
            delete temp;
        }
        len--;
    }

    // Жагсаалтын уртыг буцаана
    int length() const {
        return len;
    }

    // Хүүхлүүрийн хандалтыг дэмжих
    T& operator[](int index) {
        if (index < 0 || index >= len) {
            cout << "Invalid index!" << endl;
            return head->data;
        }
        Node<T>* current = head;
        for (int i = 0; i < index; i++) {
            current = current->next;
        }
        return current->data;
    }
};

#endif
