#include <stdio.h>
#include <unistd.h>

void print_bits(int num)
{
    int i;

    i = 8;
    while (i-- > 0)
    {
        if (num & (1 << i))
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

int main()
{
    char *str = "Hello, World!";
    int counter;

    counter = 0;
    while (str[counter] != '\0')
    {
        print_bits((char) str[counter]);
        counter++;
    }
    return 0;
}