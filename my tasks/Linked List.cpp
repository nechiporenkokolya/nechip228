#include <iostream>

struct Node {
    int data;
    Node* next;
};

// Функция для добавления элемента в начало списка
inline void addToFront(Node** head, int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = *head;
    *head = newNode;
}

// Функция для добавления элемента в конец списка
inline void addToEnd(Node** head, int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = nullptr;

    if (*head == nullptr) {
        *head = newNode;
    }
    else {
        Node* temp = *head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Функция для удаления элемента с конца списка
inline void removeFromEnd(Node** head) {
    if (*head == nullptr) return;

    if ((*head)->next == nullptr) {
        delete* head;
        *head = nullptr;
        return;
    }

    Node* temp = *head;
    while (temp->next->next != nullptr) {
        temp = temp->next;
    }
    delete temp->next;
    temp->next = nullptr;
}

// Функция для поиска элемента по значению
inline Node* searchElement(Node* head, int value) {
    Node* current = head;
    while (current != nullptr) {
        if (current->data == value) return current;
        current = current->next;
    }
    return nullptr;
}

// Функция для реверса списка
inline void reverseList(Node** head) {
    Node* prev = nullptr;
    Node* current = *head;
    Node* next = nullptr;

    while (current != nullptr) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head = prev;
}

// Функция для сортировки списка (пузырьковая сортировка)
inline void sortList(Node* head) {
    if (head == nullptr) return;

    bool swapped;
    Node* ptr1;
    Node* lptr = nullptr;

    do {
        swapped = false;
        ptr1 = head;

        while (ptr1->next != lptr) {
            if (ptr1->data > ptr1->next->data) {
                std::swap(ptr1->data, ptr1->next->data);
                swapped = true;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);
}

// Функция для очистки списка
inline void clearList(Node** head) {
    while (*head != nullptr) {
        Node* temp = *head;
        *head = (*head)->next;
        delete temp;
    }
}

// Функция для печати элементов списка
inline void printList(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        std::cout << current->data << " -> ";
        current = current->next;
    }
    std::cout << "null" << std::endl;
}

// Главная функция
int main() {
    Node* head = nullptr;

    // Добавление элементов в начало списка
    addToFront(&head, 10);
    addToFront(&head, 20);
    addToFront(&head, 30);

    // Добавление элемента в конец списка
    addToEnd(&head, 5);

    // Вывод списка
    std::cout << "Список после добавления элементов: ";
    printList(head);

    // Удаление элемента с конца
    removeFromEnd(&head);
    std::cout << "Список после удаления элемента с конца: ";
    printList(head);

    // Поиск элемента
    int searchVal = 20;
    Node* searchResult = searchElement(head, searchVal);
    std::cout << "Элемент " << searchVal << (searchResult ? " найден." : " не найден.") << std::endl;

    // Реверс списка
    reverseList(&head);
    std::cout << "Список после реверсирования: ";
    printList(head);

    // Сортировка списка
    sortList(head);
    std::cout << "Список после сортировки: ";
    printList(head);

    // Очистка списка
    clearList(&head);
    std::cout << "Список после очистки: ";
    printList(head);

    return 0;
}
