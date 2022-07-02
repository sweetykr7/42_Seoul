#include <stdio.h>
#include <unistd.h>

void	ft_putstr_fd(char const *s, int fd)
{
	if (fd < 0)
		return ;
	if (!s)
		return ;
	while (*s)
	{
		write(fd, s, 1);
		s++;
	}
}


int main(int ac, char **av)
{
	int test;
	int i;

	test = 0;
	i = 0;
	while (i < ac)
	{
		printf("check[%d] : ",i);	
		ft_putstr_fd(av[i],0);
		printf("\n");	
		i++;
	}
	return (0);
}