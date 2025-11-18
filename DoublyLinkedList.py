class Node:
    def __init__(self, value):
        self.value = value
        self.next = None
        self.prev = None


class DoublyLinkedList:
    def __init__(self, value=None):
        if value is None:
            self.head = None
            self.tail = None
            self.length = 0
            return

        new_node = Node(value)
        self.head = new_node
        self.tail = new_node
        self.length = 1

    def print_list(self):
        if self.head is None:
            print("Empty Linked List")
            return

        temp = self.head
        while temp is not None:
            print(temp.value)
            temp = temp.next

    def append(self, value):
        new_node = Node(value)
        if self.head is None:
            self.head = new_node
            self.tail = new_node
            self.length += 1
            return True

        self.tail.next = new_node
        new_node.prev = self.tail
        self.tail = new_node
        self.length += 1
        return True

    def pop(self):
        if self.head is None:
            return None

        temp = self.tail
        if self.length == 1:
            self.head = None
            self.tail = None
            self.length -= 1
            return temp

        self.tail = temp.prev
        self.tail.next = None
        temp.prev = None
        self.length -= 1
        return temp

    def prepend(self, value):
        new_node = Node(value)
        if self.head is None:
            self.head = new_node
            self.tail = new_node
            self.length += 1
            return True

        new_node.next = self.head
        self.head.prev = new_node
        self.head = new_node
        self.length += 1
        return True

    def pop_first(self):
        if self.head is None:
            return None

        temp = self.head
        if self.length == 1:
            self.head = None
            self.tail = None
            self.length -= 1
            return temp

        self.head = temp.next
        self.head.prev = None
        temp.next = None
        self.length -= 1
        return temp

    def get(self, index):
        if index < 0 or index >= self.length:
            return None

        if index < self.length / 2:
            temp = self.head
            for _ in range(index):
                temp = temp.next
            return temp

        temp = self.tail
        for _ in range(self.length - 1, index, -1):
            temp = temp.prev
        return temp

    def set_value(self, index, value):
        temp = self.get(index)
        if temp is None:
            return False

        temp.value = value
        return True

    def insert(self, index, value):
        if index < 0 or index > self.length:
            return False

        if index == 0:
            return self.prepend(value)

        if index == self.length:
            return self.append(value)

        new_node = Node(value)
        before = self.get(index - 1)
        after = before.next

        before.next = new_node
        new_node.prev = before
        new_node.next = after
        after.prev = new_node

        self.length += 1
        return True

    def remove(self, index):
        if index < 0 or index >= self.length:
            return None

        if index == 0:
            return self.pop_first()

        if index == self.length - 1:
            return self.pop()

        temp = self.get(index)
        before = temp.prev
        after = temp.next

        before.next = after
        after.prev = before
        temp.next = None
        temp.prev = None

        self.length -= 1
        return temp


myDLL = DoublyLinkedList(4)
myDLL.append(5)
myDLL.append(6)
myDLL.append(7)
myDLL.append(8)
myDLL.append(9)
myDLL.set_value(3, 100)

myDLL.remove(0)
myDLL.remove(0)
myDLL.remove(0)
myDLL.remove(0)

myDLL.print_list()
