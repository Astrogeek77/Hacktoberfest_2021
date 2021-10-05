class Node {
  constructor(element) {
    this.element = element;
    this.next = null;
  }
}

class LinkedList {
  constructor() {
    this.length = 0;
    this.head = null;
  }
  append(element) {
    let newNode = new Node(element);
    if (!this.head) {
      this.head = newNode;
    } else {
      let current = this.head;
      while (current.next) {
        current = current.next;
      }
      current.next = newNode;
    }
    this.length++;
  }
  insert(position, element) {
    let newNode = new Node(element);
    // if position is out of bound, return false
    if (position < 0 || position > this.length) {
      return false;
    } else {
      let current = this.head;
      let previous;
      let index = 0;
      if (position === 0) {
        newNode.next = current;
        this.head = newNode;
      } else {
        while (index < position) {
          previous = current;
          current = current.next;
          index++;
        }
        previous.next = newNode;
        newNode.next = current;
      }
      this.length++;
      return true;
    }
  }
  find(element) {
    return this.traverse((nodeElement) => nodeElement === element, (node) => node);
  }
  traverse(conditionFunc, callback) {
    if (!this.head) {
      return callback(null);
    }
    let current = this.head;
    while (current && !conditionFunc(current.element)) {
      current = current.next;
    }
    return callback(current);
  }
  removeAt(position) {
    if (position < 0 || position >= this.length) {
      return null;
    } else {
      let current = this.head;
      let previous;
      let index = 0;
      if (position === 0) {
        this.head = current.next;
      } else {
        while (index < position) {
          previous = current;
          current = current.next;
          index++;
        }
        previous.next = current.next;
      }
      this.length--;
      return current.element;
    }
  }
  remove(element) {
    if (!this.head) {
      return false;
    } else {
      let current = this.head.next;
      let previous = this.head;
      if (this.head.element === element) {
        this.head = previous.next;
      } else {
        while (current) {
          if (current.element === element) {
            previous.next = current.next;
            return true;
          }
          previous = previous.next;
          current = current.next;
        }
      }
      this.length--;
      return true;
    }
  }
  indexOf(element, conditionFunc) {
    if (!conditionFunc) {
      conditionFunc = (nodeElement) => element === nodeElement;
    }
    if (!this.head) {
      return -1;
    } else {
      let current = this.head;
      let index = 0;
      while (current) {
        if (!conditionFunc(current.element)) {
          current = current.next;
          index++;
        } else {
          return index;
        }
      }
      return -1;
    }
  }
  isEmpty() {
    return !this.head;
  }
  size() {
    return this.length;
  }
  toArray() {
    var current = this.head;
    var resultArray = [];
    while (current) {
      resultArray.push(current.element);
      current = current.next;
    }
    return resultArray;
  }
  print() {
    var current = this.head;
    var resultString = '';
    if (current) {
      resultString += current.element;
      while (current.next) {
        current = current.next;
        resultString += ` -> ${current.element}`;
      }
    } else {
      resultString = 'Empty List';
    }
    console.log('Linked List: ', resultString);
    console.log('Linked List Length: ', this.length);
  }
}

export default LinkedList;
