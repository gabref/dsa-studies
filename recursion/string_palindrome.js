/**
 * @param {string} str
 * @param {number} start
 * @param {number} end
 * @return {boolean}
 */
function isPalindrome(str, start = 0, end = str.length - 1) {
	if (start >= end)
		return true;
	return str.charAt(start) == str.charAt(end)
		&& isPalindrome(str, start + 1, end - 1);
}

/**
 * @param {string} str
 */
function run(str) {
	console.log(`${str}\t${isPalindrome(str) ? "true" : "false"}`);
}

console.log("word\tisPalindrome");
run("gabriel");
run("abba");
run("bella");
run("001100");
run("");
