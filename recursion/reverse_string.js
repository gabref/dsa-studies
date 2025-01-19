/**
 * reverse a string
 * @param {string} str
 * @returns {string}
 */
function reverseString(str) {
	if (str.length == 1)
		return str;
	return str.charAt(str.length - 1)
		.concat(reverseString(str.slice(0, str.length - 1)));
}

function main() {
	const str = "bellaa";
	console.log(`Original string: ${str}`); 
	console.log(`reversed string: ${reverseString(str)}`); 
}

main()
