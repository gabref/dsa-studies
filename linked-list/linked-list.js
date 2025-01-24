// print, create, insert_start, insert_end, reverse, reverse_recursive

class Node {
	/**
	 * @param {number} data
	 */
	constructor(data) {
		/** @type {number} **/
		this.data = data;
		/** @type {Node | null} **/
		this.next = null;
	}
}

class LinkedList {
	constructor() {
		/** @type {Node | null} **/
		this.head = null;
	}

	/**
	 * @param {number} data 
  	 */
	append_start(data) {
		const new_node = new Node(data);
		new_node.next = this.head;
		this.head = new_node;
	}

	/**
	 * @param {number} data 
  	 */
	append_end(data) {
		let current = this.head;
		if (this.head === null) {
			this.head = new Node(data);
			return ;
		}
		while (current.next != null)
			current = current.next;
		current.next = new Node(data);
	}

	reverse() {
		let prev = null; 
		let curr = this.head; 
		let next;
		while (curr != null) {
			next = curr.next;
			curr.next = prev;
			prev = curr;
			curr = next;
		}
		this.head = prev;
	}

	reverse_recursive() {
		this.head = this.#reverse_r(this.head);
	}

	/**
	 * @param {Node | null} head
	 * @returns {Node | null}
	 */
	#reverse_r(head) {
		if (head === null || head.next === null)
			return head;
		let new_head = this.#reverse_r(head.next);
		head.next.next = head;
		head.next = null;
		return new_head;
	}

	print() {
		for (let curr = this.head; curr != null; curr = curr.next)
			process.stdout.write(`${curr.data} -> `);
		process.stdout.write(`NULL\n`);
	}
}

const ll = new LinkedList();
ll.append_start(2);
ll.append_start(1);
ll.append_start(0);
ll.append_end(3);
ll.append_end(4);
ll.append_end(5);
ll.print();
ll.reverse();
ll.print();
ll.reverse_recursive();
ll.print();
