#include <unistd.h>

void	print_bits(char *message)
{
	int	i;

	int letter;

	letter = 0;
	while (message[letter])
	{
		i = -1;
		while (++i < 8)
		{
			if (((unsigned char)(message[letter] >> (7 - i)) & 1) == 0)	
				write(1, "0", 1);
			else if (((unsigned char)(message[letter] >> (7 - i)) & 1) == 1)	
				write(1, "1", 1);
		}
		 letter ++;
		write(1, " ", 1);
	}
}

int	main(void)
{
	char	*str;

	str = "Hello, World!";
	print_bits(str);
	return (0);
}
