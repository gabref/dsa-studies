class Node {
	/**
	 * @param {number} data
	 */
	constructor(data) {
		this.data = data;
		/** @type {Node | null} */
		this.next = null;
	}
}

class Stack {
	constructor() {
		/** @type {Node | null} */
		this.head = null;
	}

	/**
	 * @param {number} data
	 */
	push(data) {
		const node = new Node(data);
		node.next = this.head;
		this.head = node;
	}

	/**
	 * @returns {number}
	 */
	pop() {
		if (this.head == null)
			return ;
		const value = this.head.data;
		this.head = this.head.next;
		return value
	}

	print() {
		for (let curr = this.head; curr != null; curr = curr.next)
			process.stdout.write(`${curr.data} -> `);
		console.log("NULL");
	}
}

const s = new Stack();
s.print();
s.push(1);
s.push(2);
s.push(3);
s.print();
s.pop();
s.print();
s.pop();
s.print();
s.pop();
s.print();
s.pop();
s.print();
s.pop();
s.print();
