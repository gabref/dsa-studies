/**
 * @param {number} n
 * @returns {number}
 */
function sum_of_numbers_iterative(n) {
	let sum = 0;
	for (let i = 0; i <= n; i++) {
		sum += i;
	}
	return sum;
}

/**
 * @param {number} n
 * @returns {number}
 */
function sum_of_numbers_recursive(n) {
	if (n == 0)
		return 0;
	return n + sum_of_numbers_recursive(n - 1);
}

function run(n) {
	console.log(`${n} - sum = ${sum_of_numbers_iterative(n)}`);
	console.log(`${n} - sum = ${sum_of_numbers_recursive(n)}`);
	console.log();
}

function main() {
	console.log();
	run(3);
	run(10);
	run(100);
	run(1000);
}

main();
