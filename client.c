#include <signal.h>
#include <stdio.h>
#include <unistd.h>

void	tratar_sinal(int sig)
{
	if (sig == 30)
		printf("Recebi o signal %d\n ", sig);
	else if (sig == 31)
		printf("Hello Wold %d\n", sig);
}

int	main(void)
{
	printf("Server running (PID:%d)\n", getpid());
	signal(SIGUSR1, tratar_sinal);
	signal(SIGUSR2, tratar_sinal);
	while (1)
	{
		sleep(1);
	}
	return (0);
}
