#include <stdio.h>

int count_digits(int num) {
	if (num == 0)
		return 0;
	return 1 + count_digits(num / 10);
}

void run(int num) {
	printf("digits: %d\t%d\n", num, count_digits(num));
}

int main() {
	run(0);
	run(10);
	run(432);
	run(40948309);
	run(4390);
	return (0);
}
