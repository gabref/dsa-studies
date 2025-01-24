/**
 * @param {number[]} arr 
 */
function reverse(arr) {
	let l = -1;
	let r = arr.length;
	while (++l <= --r) {
		const tmp = arr[l];
		arr[l] = arr[r];
		arr[r] =  tmp;
	}
}

const arr = [1, 2, 3, 4, 5];
console.log(arr);
reverse(arr);
console.log(arr);
