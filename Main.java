public class Main {

  public static void main(String[] args) {
    LinkedList linkedList = new LinkedList(4);

    System.out.println("Appended: ");
    linkedList.append(5);
    linkedList.getHead();
    linkedList.getTail();
    linkedList.getLength();

    linkedList.printList();
    System.out.println();

    System.out.println("Prepended: ");
    linkedList.prepend(3);
    linkedList.getHead();
    linkedList.getTail();
    linkedList.getLength();

    linkedList.printList();
    System.out.println();
    // System.out.println("Removed Last: ");
    // System.out.println(linkedList.removeLast());
    // System.out.println(linkedList.removeLast());
    // System.out.println(linkedList.removeLast());

    // System.out.println("Removed First: ");
    // System.out.println(linkedList.removeFirst().value);
    // System.out.println(linkedList.removeFirst().value);
    // System.out.println(linkedList.removeFirst().value);

    // System.out.println("Get: ");
    // System.out.println(linkedList.get(0).value);
    // System.out.println(linkedList.get(1).value);
    // System.out.println(linkedList.get(2).value);

    System.out.println("Reversed: ");
    linkedList.reverse();
    linkedList.printList();
  }
}
