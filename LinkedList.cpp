#include <iostream>
using namespace std;

class Node {
  public:
    int value;
    Node* next;
    Node(int val) {
        value = val;
        next = nullptr;
    }
};

class LinkedList {
  private:
    Node* head;
    Node* tail;
    int length;

  public:
    /* Constructor */
    LinkedList() {
        head = nullptr;
        tail = nullptr;
        length = 0;
    }

    LinkedList(int value) {
        Node* newNode = new Node(value);
        head = newNode;
        tail = newNode;
        length = 1;
    }

    /* Destructor */
    ~LinkedList() {
        Node* temp = head;
        while (temp != nullptr) {
            head = head->next;
            delete temp;
            temp = head;
        }
    }

    /* Methods */
    void printList() {
        if (head == nullptr) {
            cout << "Empty Linked List" << endl;
            return;
        }

        Node* currentNode = head;
        while (currentNode != nullptr) {
            cout << currentNode->value << " ";
            currentNode = currentNode->next;
        }
        cout << endl;
    }

    void getHead() {
        if (head != nullptr) {
            cout << "Head: " << head->value << endl;
            return;
        }
        cout << "Head: nullptr." << endl;
    }

    void getTail() {
        if (tail != nullptr) {
            cout << "Tail: " << tail->value << endl;
            return;
        }
        cout << "Tail: nullptr." << endl;
    }

    void getLength() {
        cout << "Length: " << length << endl;
    }

    bool append(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
            length++;
            return true;
        }

        tail->next = newNode;
        tail = newNode;
        length++;
        return true;
    }

    void deleteLast() {
        if (head == nullptr) return;
        if (length == 1) {
            delete head;
            head = nullptr;
            tail = nullptr;
            length--;
            return;
        }

        Node* temp = head;
        Node* prev = nullptr;
        while (temp->next != nullptr) {
            prev = temp;
            temp = temp->next;
        }

        tail = prev;
        tail->next = nullptr;
        length--;
        delete temp;
    }

    bool prepend(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
            length++;
            return true;
        }

        newNode->next = head;
        head = newNode;
        length++;
        return true;
    }

    void deleteFirst() {
        if (head == nullptr) return;
        if (length == 1) {
            delete head;
            head = nullptr;
            tail = nullptr;
            length--;
            return;
        }

        Node* temp = head;
        head = head->next;
        temp->next = nullptr;
        length--;
        delete temp;
    }

    Node* get(int index) {
        if (index < 0 || index >= length) return nullptr;
        Node* temp = head;
        for (int i = 0; i < index; i++) {
            temp = temp->next;
        }
        return temp;
    }

    bool set(int index, int value) {
        Node* temp = get(index);
        if (temp == nullptr) return false;
        temp->value = value;
        return true;
    }

    bool insert(int index, int value) {
        if (index < 0 || index > length) return false;
        if (index == 0) return prepend(value);
        if (index == length) return append(value);

        Node* newNode = new Node(value);
        Node* prev = get(index - 1);
        newNode->next = prev->next;
        prev->next = newNode;
        length++;
        return true;
    }

    void deleteNode(int index) {
        if (index < 0 || index >= length) return;
        if (index == 0) return deleteFirst();
        if (index == length - 1) return deleteLast();

        Node* prev = get(index - 1);
        Node* temp = prev->next;
        prev->next = temp->next;
        temp->next = nullptr;
        length--;
        delete temp;
    }

    void reverse() {
        Node* temp = head;
        head = tail;
        tail = temp;

        Node* after = temp->next;
        Node* before = nullptr;
        for (int i = 0; i < length; i++) {
            after = temp->next;
            temp->next = before;
            before = temp;
            temp = after;
        }
    }
};

int main() {
    LinkedList* myLinkedList = new LinkedList(1);

    myLinkedList->append(2);
    myLinkedList->append(3);

    myLinkedList->deleteLast();
    myLinkedList->deleteLast();
    myLinkedList->deleteLast();

    myLinkedList->prepend(4);
    myLinkedList->prepend(5);

    // myLinkedList->deleteFirst();
    // myLinkedList->set(0, 88);

    myLinkedList->insert(2, 99);
    myLinkedList->insert(1, 77);

    myLinkedList->getHead();
    myLinkedList->getTail();
    myLinkedList->getLength();
    myLinkedList->printList();

    myLinkedList->reverse();
    myLinkedList->printList();

    delete myLinkedList;
    return 0;
}