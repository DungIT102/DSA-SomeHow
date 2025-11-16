class Note {
  constructor(value) {
    this.value = value;
    this.next = null;
  }
}

class LinkedList {
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
    this.tail = newNode;
    this.length++;
  }

  pop() {
    if (!this.head) return undefined;

    let temp = this.head;
    if (this.length === 1) {
      this.head = null;
      this.tail = null;
      this.length--;
      return temp;
    }

    let prev = temp;
    while (temp.next) {
      prev = temp;
      temp = temp.next;
    }

    this.tail = prev;
    this.tail.next = null;
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
    temp.next = null;
    this.length--;
    return temp;
  }

  get(index) {
    if (index < 0 || index >= this.length) return undefined;

    let temp = this.head;
    for (let i = 0; i < index; i++) {
      temp = temp.next;
    }
    return temp;
  }

  set(index, value) {
    let temp = this.get(index);
    if (temp) {
      temp.value = value;
      return true;
    }

    return false;
  }

  insert(index, value) {
    if (index < 0 || index > this.length) return false;
    if (index === 0) return this.unShift(value);
    if (index === this.length) return this.push(value);

    const newNode = new Note(value);
    let temp = this.get(index - 1);
    newNode.next = temp.next;
    temp.next = newNode;
    this.length++;
    return true;
  }

  remove(index) {
    if (index < 0 || index >= this.length) return undefined;
    if (index === 0) return this.shift();
    if (index === this.length - 1) return this.pop();

    let prev = this.get(index - 1);
    let temp = prev.next;
    prev.next = temp.next;
    temp.next = null;
    this.length--;
    return temp;
  }

  reverse() {
    let temp = this.head;
    this.head = this.tail;
    this.tail = temp;

    let next = temp.next;
    let prev = null;
    for (let i = 0; i < this.length; i++) {
      next = temp.next;
      temp.next = prev;
      prev = temp;
      temp = next;
    }
  }
}

let myLinkedList = new LinkedList(2);
myLinkedList.push(5);
myLinkedList.push(16);
console.log(myLinkedList);

myLinkedList.unShift(1);
console.log(myLinkedList);

myLinkedList.set(2, 99);
console.log(myLinkedList.get(2));

myLinkedList.insert(1, 55);
console.log(myLinkedList);

console.log(myLinkedList.remove(2));
console.log(myLinkedList);

myLinkedList.reverse();
console.log(myLinkedList);

// console.log(myLinkedList.shift());
// console.log(myLinkedList.shift());
// console.log(myLinkedList.shift());
// console.log(myLinkedList.shift());
// console.log(myLinkedList.shift());
// console.log(myLinkedList);

// console.log(myLinkedList.pop());
// console.log(myLinkedList.pop());
// console.log(myLinkedList.pop());
// console.log(myLinkedList.pop());
// console.log(myLinkedList);
