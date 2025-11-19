class Note {
  constructor(value) {
    this.value = value;
    this.next = null;
  }
}

class Stack {
  constructor(value) {
    if (!value) {
      this.top = null;
      this.height = 0;
      return;
    }

    const newNode = new Note(value);
    this.top = newNode;
    this.height = 1;
  }

  printStack() {
    if (this.top === null) {
      console.log('Empty Stack');
      return;
    }

    let temp = this.top;
    while (temp !== null) {
      console.log(temp.value);
      temp = temp.next;
    }
  }

  getTop() {
    if (this.top === null) {
      console.log('Top: null');
      return;
    }
    console.log('Top: ' + this.top.value);
  }

  getHeight() {
    console.log('Height: ' + this.height);
  }

  push(value) {
    const newNode = new Note(value);

    newNode.next = this.top;
    this.top = newNode;
    this.height++;
  }

  pop() {
    if (!this.top) return undefined;

    let temp = this.top;
    this.top = this.top.next;
    temp.next = null;
    this.height--;
    return temp;
  }

  get(index) {
    if (index < 0 || index >= this.height) return undefined;

    let temp = this.top;
    for (let i = 0; i < index; i++) {
      temp = temp.next;
    }
    return temp;
  }
}

class Queue {
  constructor(value) {
    if (!value) {
      this.first = null;
      this.last = null;
      this.length = 0;
      return;
    }

    const newNode = new Note(value);
    this.first = newNode;
    this.last = newNode;
    this.length = 1;
  }

  printQueue() {
    if (this.first === null) {
      console.log('Empty Queue');
      return;
    }

    let temp = this.first;
    while (temp !== null) {
      console.log(temp.value);
      temp = temp.next;
    }
  }

  getFirst() {
    if (this.first === null) {
      console.log('First: null');
      return;
    }
    console.log('First: ' + this.first.value);
  }

  getLast() {
    if (this.last === null) {
      console.log('Last: null');
      return;
    }
    console.log('Last: ' + this.last.value);
  }

  getLength() {
    console.log('Length: ' + this.length);
  }

  enqueue(value) {
    const newNode = new Note(value);

    if (!this.first) {
      this.first = newNode;
      this.last = newNode;
      this.length++;
      return;
    }

    this.last.next = newNode;
    this.last = newNode;
    this.length++;
  }

  dequeue() {
    if (!this.first) return undefined;

    let temp = this.first;
    if (this.length === 1) {
      this.first = null;
      this.last = null;
    } else {
      this.first = this.first.next;
      temp.next = null;
    }

    this.length--;
    return temp;
  }

  get(index) {
    if (index < 0 || index >= this.length) return undefined;

    let temp = this.first;
    for (let i = 0; i < index; i++) {
      temp = temp.next;
    }
    return temp;
  }
}

console.log('Stack:');

let myStack = new Stack(1);
myStack.push(2);
myStack.push(3);
myStack.push(4);
myStack.getTop();
myStack.getHeight();
myStack.printStack();

console.log('Queue:');

let myQueue = new Queue(1);
myQueue.enqueue(2);
myQueue.enqueue(3);
myQueue.enqueue(4);
myQueue.dequeue();
myQueue.dequeue();
myQueue.dequeue();
myQueue.dequeue();
myQueue.getFirst();
myQueue.getLast();
myQueue.getLength();
myQueue.printQueue();
