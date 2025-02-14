function createEnum(values) {
	const enumObject = {};
	for (const val of values) {
			enumObject[val] = val;
	}
	return Object.freeze(enumObject);
}

const Type = createEnum(['NONE', 'ROUND', 'SQUARE', 'CURLY']);

class Stack {
	constructor() {
		this.items = [];
	}

	/**
	 * @param {string} p_type
	 */
	push(p_type) {
		this.items.push(p_type);
	}

	pop() {
		return this.items.pop();
	}

	isEmpty() {
		return this.items.length === 0;
	}
}

/**
 * @param {string} str
 */
function par_to_type(c) {
	switch (c) {
		case '{':
		case '}':
			return Type.CURLY
		case '[':
		case ']':
			return Type.SQUARE
		case '(':
		case ')':
			return Type.ROUND
		default: return Type.NONE
	}
}

/**
 * @param {string} str
 */
function check_parenthesis(str) {
	const strArr = str.split('');
	const stack = new Stack();
	for (let i = 0; i < strArr.length; i++) {
		if (strArr[i] === '{' || strArr[i] === '[' || strArr[i] === '(')
			stack.push(strArr[i]);
		else if (strArr[i] === '}' || strArr[i] === ']' || strArr[i] === ')')
			if (par_to_type(strArr[i]) !== par_to_type(stack.pop()))
				return false;
	}
	if (stack.isEmpty())
		return true
	return false;
}

let a;
a = '{ { [ ( [ ] () ) ] } }';
console.log(`${a} -> ${check_parenthesis(a)}`);
a = '{ { [ ( ( [ ] () ) ] } }';
console.log(`${a} -> ${check_parenthesis(a)}`);
a = '';
console.log(`${a} -> ${check_parenthesis(a)}`);
a = '()';
console.log(`${a} -> ${check_parenthesis(a)}`);
a = ')';
console.log(`${a} -> ${check_parenthesis(a)}`);
