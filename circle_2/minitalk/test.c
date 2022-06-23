#include <unistd.h>
#include <stdio.h>


int main(int ac, char **av)
{
	ac = 0;
	int i;
	write(1, av[1], 3);
	write(1, "\n", 1);
	i = 0;
	while(av[1][i])
	{
		printf("av %d : %d\n",i, av[1][i]);
		i++;
	}
}