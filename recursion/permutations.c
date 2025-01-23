#include <stdio.h>
#include <string.h>

void	print_permutations(char *str, int l, int r)
{
	int		i;
	char	tmp;

	if (l == r)
	{
		printf("%s\n", str);
		return ;
	}
	i = l;
	while (i <= r)
	{
		tmp = str[l];
		str[l] = str[i];
		str[i] = tmp;
		print_permutations(str, l + 1, r);
		str[i] = str[l];
		str[l] = tmp;
		i++;
	}
}

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		printf("Usage: ./<program_name> <string to be permuted>\n");
		return (1);
	}
	printf("\n");
	print_permutations(av[1], 0, strlen(av[1]) - 1);
	printf("\n");
}
