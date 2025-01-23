/**
 * swaps 2 characters and returns a new string
 * @param {string} str
 * @param {number} l
 * @param {number} r
 * @returns {string}
 */
function swap(str, i, j) {
	const charArr = str.split('');
	const tmp = charArr[i];
	charArr[i] = charArr[j];
	charArr[j] = tmp;
	return charArr.join('');
}

/**
 * Print all permutations of a string.
 * @param {string} str - The input string.
 * @param {number} l - Starting index.
 * @param {number} r - Ending index.
 */
function printPermutations(str, l = 0, r = str.length - 1) {
	if (l === r)
		return console.log(`${str}`);
	for (let i = l; i <= r; i++) {
		str = swap(str, l, i);
		printPermutations(str, l + 1, r);
		str = swap(str, l, i);
	}
}

const args = process.argv.slice(2);
if (args.length === 0) {
	console.error("usage: provide string to permute");
	process.exit(1);
}

const input = args[0];
printPermutations(input, 0, input.length - 1)
