public class Main {

  public static void main(String[] args) {
    DoublyLinkedList myDLL = new DoublyLinkedList(1);

    myDLL.append(2);
    myDLL.append(3);
    myDLL.prepend(99);
    myDLL.set(3, 88);
    myDLL.insert(0, 77);
    myDLL.insert(5, 66);
    myDLL.insert(2, 44);
    myDLL.remove(0);
    myDLL.remove(3);
    myDLL.remove(6);

    myDLL.getHead();
    myDLL.getTail();
    myDLL.getLength();
    myDLL.printList();

    System.out.println("Get 0: " + myDLL.get(0).value);
    System.out.println("Get 3: " + myDLL.get(3).value);
  }
}
