/**
 * @param {number[]} arr 
 */
function findMajorityElement(arr) {
	let candidate = -1;
	let votes = 0;
	for (let i = 0; i < arr.length; i++) {
		if (votes === 0) {
			candidate = arr[i];
			votes = 1;
		} else {
			if (candidate == arr[i])
				votes++;
			else
				votes--;
		}
	}
	let count = 0;
	for (let i = 0; i < arr.length; i++)
		if (candidate == arr[i])
			count++;
	if (count > arr.length / 2)
		return candidate;
	return -1;
}

const a = [ 3, 4, 5, 3, 3, 4, 0, 2, 3, 3, 3 ];
console.log(`most frequent element: ${findMajorityElement(a)}`);
