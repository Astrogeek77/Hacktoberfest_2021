function queue() {
  const items = [];

  return {
    enqueue,
    dequeue,
    front,
    isEmpty,
    size,
    print
  };

  function enqueue(element) {
    items.push(element);
  }

  function dequeue() {
    return items.shift();
  }

  function front() {
    return items[0];
  }

  function isEmpty() {
    return items.length === 0;
  }

  function size() {
    return items.length;
  }

  function print() {
    console.log(items.toString());
  }
}


const q = queue();

q.enqueue(3);
q.enqueue(2);
q.enqueue(6);

console.log(q.front());
q.print();

console.log(q.dequeue());
q.print();
