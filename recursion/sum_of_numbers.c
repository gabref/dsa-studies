#include <stdio.h>

int	sum_of_numbers_iterative(int n)
{
	int	sum;
	int	i;

	sum = 0;
	i = 0;
	while (i < n)
		sum += i++ + 1;
	return (sum);
}

int	sum_of_numbers_recursive(int n)
{
	if (n == 0)
		return (0);
	return (n + sum_of_numbers_recursive(n - 1));
}

int	main(void)
{
	int	n;

	n = 10;
	printf("%d\tsum = %d\n", n, sum_of_numbers_iterative(n));
	printf("%d\tsum = %d\n", n, sum_of_numbers_recursive(n));

	n = 100;
	printf("%d\tsum = %d\n", n, sum_of_numbers_iterative(n));
	printf("%d\tsum = %d\n", n, sum_of_numbers_recursive(n));

	n = 1000;
	printf("%d\tsum = %d\n", n, sum_of_numbers_iterative(n));
	printf("%d\tsum = %d\n", n, sum_of_numbers_recursive(n));
	return (0);
}
