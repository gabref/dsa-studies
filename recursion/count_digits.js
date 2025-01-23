/**
 * @param {number} num
 * @returns {number}
 */
function countDigits(num) {
	if (num == 0)
		return 0;
	return 1 + countDigits(Math.floor(num / 10));
}

function run(num) {
	console.log(`digits: ${num}\t${countDigits(num)}`);
}

run(0);
run(10);
run(483);
run(49302490);
run(8934);
