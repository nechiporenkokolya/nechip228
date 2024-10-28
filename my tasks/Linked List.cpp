#include <iostream>

struct Node {
    int data;
    Node* next;
};

// ������� ��� ���������� �������� � ������ ������
inline void addToFront(Node** head, int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = *head;
    *head = newNode;
}

// ������� ��� ���������� �������� � ����� ������
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

// ������� ��� �������� �������� � ����� ������
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

// ������� ��� ������ �������� �� ��������
inline Node* searchElement(Node* head, int value) {
    Node* current = head;
    while (current != nullptr) {
        if (current->data == value) return current;
        current = current->next;
    }
    return nullptr;
}

// ������� ��� ������� ������
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

// ������� ��� ���������� ������ (����������� ����������)
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

// ������� ��� ������� ������
inline void clearList(Node** head) {
    while (*head != nullptr) {
        Node* temp = *head;
        *head = (*head)->next;
        delete temp;
    }
}

// ������� ��� ������ ��������� ������
inline void printList(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        std::cout << current->data << " -> ";
        current = current->next;
    }
    std::cout << "null" << std::endl;
}

// ������� �������
int main() {
    Node* head = nullptr;

    // ���������� ��������� � ������ ������
    addToFront(&head, 10);
    addToFront(&head, 20);
    addToFront(&head, 30);

    // ���������� �������� � ����� ������
    addToEnd(&head, 5);

    // ����� ������
    std::cout << "������ ����� ���������� ���������: ";
    printList(head);

    // �������� �������� � �����
    removeFromEnd(&head);
    std::cout << "������ ����� �������� �������� � �����: ";
    printList(head);

    // ����� ��������
    int searchVal = 20;
    Node* searchResult = searchElement(head, searchVal);
    std::cout << "������� " << searchVal << (searchResult ? " ������." : " �� ������.") << std::endl;

    // ������ ������
    reverseList(&head);
    std::cout << "������ ����� ��������������: ";
    printList(head);

    // ���������� ������
    sortList(head);
    std::cout << "������ ����� ����������: ";
    printList(head);

    // ������� ������
    clearList(&head);
    std::cout << "������ ����� �������: ";
    printList(head);

    return 0;
}
