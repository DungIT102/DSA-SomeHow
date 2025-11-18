#include <iostream>
using namespace std;

class Node {
  public:
    int value;
    Node* next;
    Node* prev;

    Node(int val) {
        value = val;
        next = nullptr;
        prev = nullptr;
    }
};

class DoublyLinkedList {
  private:
    Node* head;
    Node* tail;
    int length;

  public:
    /* Constructor */
    DoublyLinkedList() {
        head = nullptr;
        tail = nullptr;
        length = 0;
    }

    DoublyLinkedList(int value) {
        Node* newNode = new Node(value);
        head = newNode;
        tail = newNode;
        length = 1;
    }

    /* Destructor */
    ~DoublyLinkedList() {
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
        newNode->prev = tail;
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

        Node* temp = tail;
        tail = tail->prev;
        tail->next = nullptr;
        temp->prev = nullptr;
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
        head->prev = newNode;
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
        head->prev = nullptr;
        temp->next = nullptr;
        length--;
        delete temp;
    }

    Node* get(int index) {
        if (index < 0 || index >= length) return nullptr;
        Node* temp = head;
        if (index < length / 2) {
            for (int i = 0; i < index; i++) {
                temp = temp->next;
            }
        } else {
            temp = tail;
            for (int i = length - 1; i > index; i--) {
                temp = temp->prev;
            }
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
        Node* before = get(index - 1);
        Node* after = before->next;

        before->next = newNode;
        newNode->prev = before;
        newNode->next = after;
        after->prev = newNode;
        length++;
        return true;
    }

    void deleteNode(int index) {
        if (index < 0 || index >= length) return;
        if (index == 0) return deleteFirst();
        if (index == length - 1) return deleteLast();

        Node* temp = get(index);
        Node* before = temp->prev;
        Node* after = temp->next;

        before->next = after;
        after->prev = before;
        temp->next = nullptr;
        temp->prev = nullptr;
        length--;
        delete temp;
    }
};

int main() {
    DoublyLinkedList* myDLL = new DoublyLinkedList(1);
    myDLL->append(2);
    myDLL->append(3);
    myDLL->prepend(99);
    myDLL->deleteNode(0);
    myDLL->deleteNode(0);
    myDLL->deleteNode(0);
    myDLL->deleteNode(0);
    myDLL->deleteNode(0);

    myDLL->printList();

    delete myDLL;
    return 0;
}