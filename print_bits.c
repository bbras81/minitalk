#include <unistd.h>

void	print_bits(int num)
{
	int	i;

	i = 0;
	while (i++ < 7)
	{
		if (num & (1 >> i) & 1)
		{
			write(1, "1", 1);
		}
		else
		{
			write(1, "0", 1);
		}
	}
	write(1, " ", 1);
}

int	main(void)
{
	char	*str;
	int		counter;

	str = "Hello, World!";
	counter = 0;
	while (str[counter] != '\0')
	{
		print_bits((char)str[counter]);
		counter++;
	}
	return (0);
}
