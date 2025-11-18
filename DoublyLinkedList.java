class Node {

  int value;
  Node next;
  Node prev;

  Node(int value) {
    this.value = value;
  }
}

public class DoublyLinkedList {

  private Node head;
  private Node tail;
  private int length;

  public DoublyLinkedList() {
    head = null;
    tail = null;
    length = 0;
  }

  public DoublyLinkedList(int value) {
    Node newNode = new Node(value);
    head = newNode;
    tail = newNode;
    length = 1;
  }

  public void printList() {
    if (head == null) {
      System.out.println("Empty Linked List");
      return;
    }

    Node temp = head;
    while (temp != null) {
      System.out.println(temp.value);
      temp = temp.next;
    }
  }

  public void getHead() {
    if (head == null) {
      System.out.println("Head: null");
      return;
    }
    System.out.println("Head: " + head.value);
  }

  public void getTail() {
    if (tail == null) {
      System.out.println("Tail: null");
      return;
    }
    System.out.println("Tail: " + tail.value);
  }

  public void getLength() {
    System.out.println("Length: " + length);
  }

  public void append(int value) {
    Node newNode = new Node(value);

    if (head == null) {
      head = newNode;
      tail = newNode;
      length++;
      return;
    }

    tail.next = newNode;
    newNode.prev = tail;
    tail = newNode;
    length++;
  }

  public Node removeLast() {
    if (head == null) return null;

    Node temp = tail;
    if (length == 1) {
      head = null;
      tail = null;
      length--;
      return temp;
    }

    tail = tail.prev;
    tail.next = null;
    temp.prev = null;
    length--;
    return temp;
  }

  public void prepend(int value) {
    Node newNode = new Node(value);
    if (head == null) {
      head = newNode;
      tail = newNode;
      length++;
      return;
    }

    newNode.next = head;
    head.prev = newNode;
    head = newNode;
    length++;
  }

  public Node removeFirst() {
    if (head == null) return null;

    Node temp = head;
    if (length == 1) {
      head = null;
      tail = null;
      length--;
      return temp;
    }

    head = head.next;
    head.prev = null;
    temp.next = null;
    length--;
    return temp;
  }

  public Node get(int index) {
    if (index < 0 || index >= length) return null;

    Node temp = head;
    if (index < length / 2) {
      for (int i = 0; i < index; i++) {
        temp = temp.next;
      }
    } else {
      temp = tail;
      for (int i = length - 1; i > index; i--) {
        temp = temp.prev;
      }
    }

    return temp;
  }

  public boolean set(int index, int value) {
    Node temp = get(index);
    if (temp == null) return false;

    temp.value = value;
    return true;
  }

  public boolean insert(int index, int value) {
    if (index < 0 || index > length) return false;

    if (index == 0) {
      prepend(value);
      return true;
    }

    if (index == length) {
      append(value);
      return true;
    }

    Node newNode = new Node(value);
    Node before = get(index - 1);
    Node after = before.next;

    newNode.prev = before;
    newNode.next = after;
    before.next = newNode;
    after.prev = newNode;
    length++;
    return true;
  }

  public Node remove(int index) {
    if (index < 0 || index >= length) return null;

    if (index == 0) return removeFirst();
    if (index == length - 1) return removeLast();

    Node temp = get(index);
    Node before = temp.prev;
    Node after = temp.next;

    before.next = after;
    after.prev = before;
    temp.next = null;
    temp.prev = null;
    length--;
    return temp;
  }
}
