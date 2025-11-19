class Node:
    def __init__(self, value):
        self.value = value
        self.next = None


class Stack:
    def __init__(self, value=None):
        if value is None:
            self.top = None
            self.height = 0
            return

        new_node = Node(value)
        self.top = new_node
        self.height = 1

    def print_stack(self):
        if self.top is None:
            print("Empty Stack")
            return

        temp = self.top
        while temp is not None:
            print(temp.value)
            temp = temp.next

    def get_top(self):
        if self.top is None:
            print("Top: null")
            return

        print("Top: ", self.top.value)

    def get_height(self):
        print("Height: ", self.height)

    def push(self, value):
        new_node = Node(value)

        new_node.next = self.top
        self.top = new_node
        self.height += 1

    def pop(self):
        if self.top is None:
            return None

        temp = self.top
        self.top = self.top.next
        temp.next = None
        self.height -= 1
        return temp

    def get(self, index):
        if index < 0 or index >= self.height:
            return None

        temp = self.head
        for _ in range(index):
            temp = temp.next

        return temp


class Queue:
    def __init__(self, value=None):
        if value is None:
            self.first = None
            self.last = None
            self.length = 0
            return

        new_node = Node(value)
        self.first = new_node
        self.last = new_node
        self.length = 1

    def print_queue(self):
        if self.first is None:
            print("Empty Queue")
            return

        temp = self.first
        while temp is not None:
            print(temp.value)
            temp = temp.next

    def get_first(self):
        if self.first is None:
            print("First: null")
            return

        print("First: ", self.first.value)

    def get_last(self):
        if self.last is None:
            print("Last: null")
            return

        print("Last: ", self.last.value)

    def get_length(self):
        print("Length: ", self.length)

    def enqueue(self, value):
        new_node = Node(value)

        if self.first is None:
            self.first = new_node
            self.last = new_node
            self.length += 1
            return

        self.last.next = new_node
        self.last = new_node
        self.length += 1

    def dequeue(self):
        if self.first is None:
            return None

        temp = self.first
        if self.length == 1:
            self.first = None
            self.last = None
            self.length -= 1
            return temp

        self.first = self.first.next
        temp.next = None
        self.length -= 1
        return temp

    def get(self, index):
        if index < 0 or index >= self.length:
            return None

        temp = self.first
        for _ in range(index):
            temp = temp.next

        return temp


my_queue = Queue()
my_queue.enqueue(1)
my_queue.enqueue(2)
my_queue.enqueue(3)
my_queue.enqueue(4)

my_queue.dequeue()
my_queue.dequeue()
my_queue.dequeue()


my_queue.get_first()
my_queue.get_last()
my_queue.get_length()
my_queue.print_queue()
