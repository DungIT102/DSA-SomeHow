public class Queue {

  private Node first;
  private Node last;
  private int length;

  public Queue() {
    first = null;
    last = null;
    length = 0;
  }

  public Queue(int value) {
    Node newNode = new Node(value);
    first = newNode;
    last = newNode;
    length = 1;
  }

  public void printQueue() {
    if (first == null) {
      System.out.println("Empty Queue");
      return;
    }

    Node temp = first;
    while (temp != null) {
      System.out.println(temp.value);
      temp = temp.next;
    }
  }

  public void getFirst() {
    if (first == null) {
      System.out.println("First: null");
      return;
    }
    System.out.println("First: " + first.value);
  }

  public void getLast() {
    if (last == null) {
      System.out.println("Last: null");
      return;
    }
    System.out.println("Last: " + last.value);
  }

  public void getLength() {
    System.out.println("length: " + length);
  }

  public void enqueue(int value) {
    Node newNode = new Node(value);

    if (first == null) {
      first = newNode;
      last = newNode;
      length++;
      return;
    }

    last.next = newNode;
    last = newNode;
    length++;
  }

  public Node dequeue() {
    if (first == null) return null;

    Node temp = first;
    if (length == 1) {
      first = null;
      last = null;
    } else {
      first = first.next;
      temp.next = null;
    }

    length--;
    return temp;
  }

  public Node get(int index) {
    if (index < 0 || index >= length) return null;

    Node temp = first;
    for (int i = 0; i < index; i++) {
      temp = temp.next;
    }

    return temp;
  }
}
