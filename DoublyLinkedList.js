class Note {
  constructor(value) {
    this.value = value;
    this.next = null;
    this.prev = null;
  }
}

class DoublyLinkedList {
  constructor(value) {
    if (!value) {
      this.head = null;
      this.tail = null;
      this.length = 0;
      return;
    }

    const newNode = new Note(value);
    this.head = newNode;
    this.tail = newNode;
    this.length = 1;
  }

  push(value) {
    const newNode = new Note(value);

    if (!this.head) {
      this.head = newNode;
      this.tail = newNode;
      this.length++;
      return;
    }

    this.tail.next = newNode;
    newNode.prev = this.tail;
    this.tail = newNode;
    this.length++;
  }

  pop() {
    if (!this.head) return undefined;

    let temp = this.tail;
    if (this.length === 1) {
      this.head = null;
      this.tail = null;
      this.length--;
      return temp;
    }

    this.tail = temp.prev;
    this.tail.next = null;
    temp.prev = null;
    this.length--;
    return temp;
  }

  unShift(value) {
    const newNode = new Note(value);

    if (!this.head) {
      this.head = newNode;
      this.tail = newNode;
      this.length++;
      return;
    }

    newNode.next = this.head;
    this.head.prev = newNode;
    this.head = newNode;
    this.length++;
  }

  shift() {
    if (!this.head) return undefined;

    let temp = this.head;
    if (this.length === 1) {
      this.head = null;
      this.tail = null;
      this.length--;
      return temp;
    }

    this.head = this.head.next;
    this.head.prev = null;
    temp.next = null;
    this.length--;
    return temp;
  }

  get(index) {
    if (index < 0 || index >= this.length) return undefined;

    let temp = this.head;
    if (index < this.length / 2) {
      for (let i = 0; i < index; i++) {
        temp = temp.next;
      }
    } else {
      temp = this.tail;
      for (let i = this.length - 1; i > index; i--) {
        temp = temp.prev;
      }
    }

    return temp;
  }

  set(index, value) {
    let temp = this.get(index);
    if (!temp) return false;

    temp.value = value;
    return true;
  }

  insert(index, value) {
    if (index < 0 || index > this.length) return false;
    if (index === 0) return this.unShift(value);
    if (index === this.length) return this.push(value);

    const newNode = new Note(value);
    const before = this.get(index - 1);
    const after = before.next;

    before.next = newNode;
    newNode.prev = before;
    newNode.next = after;
    after.prev = newNode;
    this.length++;
    return true;
  }

  remove(index) {
    if (index < 0 || index >= this.length) return undefined;
    if (index === 0) return this.shift();
    if (index === this.length - 1) return this.pop();

    const temp = this.get(index);
    const before = temp.prev;
    const after = temp.next;

    before.next = after;
    after.prev = before;
    temp.next = null;
    temp.prev = null;

    this.length--;
    return temp;
  }
}

let myDLL = new DoublyLinkedList(2);
myDLL.push(3);
myDLL.pop();
myDLL.pop();
myDLL.unShift(1);
myDLL.unShift(99);
myDLL.unShift(88);

console.log(myDLL);
