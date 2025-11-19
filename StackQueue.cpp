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

class Stack {
  private:
    Node* top;
    int height;

  public:
    /* Constructor */
    Stack() {
        top = nullptr;
        height = 0;
    }

    Stack(int value) {
        Node* newNode = new Node(value);
        top = newNode;
        height = 1;
    }

    /* Destructor */
    ~Stack() {
        Node* temp = top;
        while (temp != nullptr) {
            top = top->next;
            delete temp;
            temp = top;
        }
    }

    /* Methods */
    void printStack() {
        if (top == nullptr) {
            cout << "Empty Stack" << endl;
            return;
        }

        Node* currentNode = top;
        while (currentNode != nullptr) {
            cout << currentNode->value << " ";
            currentNode = currentNode->next;
        }
        cout << endl;
    }

    void getTop() {
        if (top != nullptr) {
            cout << "Top: " << top->value << endl;
            return;
        }
        cout << "Top: nullptr." << endl;
    }

    void getHeight() {
        cout << "Height: " << height << endl;
    }

    void push(int value) {
        Node* newNode = new Node(value);
        newNode->next = top;
        top = newNode;
        height++;
    }

    int pop() {
        if (top == nullptr) return INT16_MIN;

        Node* temp = top;
        int poppedValue = top->value;
        top = top->next;
        temp->next = nullptr;
        height--;
        delete temp;

        return poppedValue;
    }

    Node* get(int index) {
        if (index < 0 || index >= height) return nullptr;
        Node* temp = top;

        for (int i = 0; i < index; i++) {
            temp = temp->next;
        }

        return temp;
    }
};

class Queue {
  private:
    Node* first;
    Node* last;
    int length;

  public:
    /* Constructor */
    Queue() {
        first = nullptr;
        last = nullptr;
        length = 0;
    }

    Queue(int value) {
        Node* newNode = new Node(value);
        first = newNode;
        last = newNode;
        length = 1;
    }

    /* Destructor */
    ~Queue() {
        Node* temp = first;
        while (temp != nullptr) {
            first = first->next;
            delete temp;
            temp = first;
        }
    }

    /* Methods */
    void printQueue() {
        if (first == nullptr) {
            cout << "Empty Queue" << endl;
            return;
        }

        Node* currentNode = first;
        while (currentNode != nullptr) {
            cout << currentNode->value << " ";
            currentNode = currentNode->next;
        }
        cout << endl;
    }

    void getFirst() {
        if (first != nullptr) {
            cout << "First: " << first->value << endl;
            return;
        }
        cout << "Top: nullptr." << endl;
    }

    void getLast() {
        if (last != nullptr) {
            cout << "Last: " << last->value << endl;
            return;
        }
        cout << "last: nullptr." << endl;
    }

    void getLength() {
        cout << "Length: " << length << endl;
    }

    void enqueue(int value) {
        Node* newNode = new Node(value);
        if (first == nullptr) {
            first = newNode;
            last = newNode;
            length++;
            return;
        }

        last->next = newNode;
        last = newNode;
        length++;
    }

    Node* dequeue() {
        if (first == nullptr) return nullptr;

        Node* temp = first;
        if (length == 1) {
            first = nullptr;
            last = nullptr;

        } else {
            first = first->next;
            temp->next = nullptr;
        }

        length--;
        return temp;
    }

    Node* get(int index) {
        if (index < 0 || index >= length) return nullptr;
        Node* temp = first;

        for (int i = 0; i < index; i++) {
            temp = temp->next;
        }

        return temp;
    }
};

int main() {
    Stack* myStack = new Stack();
    myStack->push(1);
    myStack->push(2);
    myStack->push(3);
    myStack->getTop();
    myStack->getHeight();
    myStack->printStack();

    return 0;
}