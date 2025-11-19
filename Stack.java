public class Stack {

  private Node top;
  private int height;

  public Stack() {
    top = null;
    height = 0;
  }

  public Stack(int value) {
    Node newNode = new Node(value);
    top = newNode;
    height = 1;
  }

  public void printStack() {
    if (top == null) {
      System.out.println("Empty Stacks");
      return;
    }

    Node temp = top;
    while (temp != null) {
      System.out.println(temp.value);
      temp = temp.next;
    }
  }

  public void getTop() {
    if (top == null) {
      System.out.println("Top: null");
      return;
    }
    System.out.println("Top: " + top.value);
  }

  public void getHeight() {
    System.out.println("Height: " + height);
  }

  public void push(int value) {
    Node newNode = new Node(value);

    newNode.next = top;
    top = newNode;
    height++;
  }

  public Node pop() {
    if (top == null) return null;

    Node temp = top;
    top = top.next;
    temp.next = null;
    height--;
    return temp;
  }

  public Node get(int index) {
    if (index < 0 || index >= height) return null;

    Node temp = top;
    for (int i = 0; i < index; i++) {
      temp = temp.next;
    }

    return temp;
  }
}
