class Stack {
	constructor() {
		/** @type {number[]} */
		this.items = [];
	}

	/**
	 @param {number} item
	 */
	push(item) {
		this.items.push(item);
	}

	/**
	 @return {number | null}
	 */
	pop() {
		return this.items.length ? this.items.pop() : null;
	}

	/**
	 @return {number | null}
	 */
	peek() {
		return this.items.length ? this.items[this.items.length - 1] : null;
	}

	isEmpty() {
		return this.items.length === 0;
	}
}

const s = new Stack();
s.push(10);
s.push(20);
console.log(s.peek()); // 20
console.log(s.pop()); // 20
console.log(s.peek()); // 10
