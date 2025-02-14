/**
 * @param {number[]} arr
 * @param {number} k
 */
function rotate(arr, k) {
	const size = arr.length;
	while (k--) {
		const last = arr[size - 1];
		for (let i = size - 1; i > 0; i--)
			arr[i] = arr[i - 1];
		arr[0] = last;
	}
}

const arr = [1, 2, 3, 4, 5];
console.log('arr', arr);
rotate(arr, 2);
console.log('arr', arr);
rotate(arr, 3);
console.log('arr', arr);
