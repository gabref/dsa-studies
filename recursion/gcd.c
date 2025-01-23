#include <stdio.h>

int gcd(int a, int b) {
  if (a == 0)
    return (b);
  return (gcd(b % a, a));
}

void run(int a, int b) {
	printf("gcd(%d, %d) = %d\n", a, b, gcd(a, b));
}

int main() {
	run(15, 10);
	run(10, 15);
	run(4324, 40324);
	run(63, 9);
	run(18, 36);
	return 0;
}
