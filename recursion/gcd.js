/**
 * @param {number} a
 * @param {number} b
 * @returns {number}
 */
function gcd(a, b) {
	if (a == 0)
		return b;
	return gcd(b % a, a);
}

/**
 * @param {number} a
 * @param {number} b
 */
function run(a, b) {
	console.log(`gdc(${a}, ${b}) = ${gcd(a, b)}`);
}

run(15, 10);
run(10, 15);
run(4324, 40324);
run(63, 9);
run(18, 36);
