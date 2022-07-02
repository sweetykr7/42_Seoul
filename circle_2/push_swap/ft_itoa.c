
#include "push_swap.h"

char	*get_zero(void)
{
	char	*res;

	res = (char *)malloc(sizeof(char) * 2);
	if (!res)
		return (NULL);
	res[0] = '0';
	res[1] = '\0';
	return (res);
}

int	get_length(int n, int sign)
{
	int	count;

	count = 0;
	while (n != 0)
	{
		n = n / 10;
		count++;
	}
	if (sign == -1)
		count++;
	return (count);
}

char	*ft_itoa(int n)
{
	int		sign;
	int		i;
	int		size;
	char	*res;

	sign = 1;
	if (n == 0)
		return (get_zero());
	if (n < 0)
		sign = -1;
	size = get_length(n, sign);
	res = (char *)malloc(sizeof(char) * (size + 1));
	if (!res)
		return (NULL);
	i = 0;
	if (sign == -1)
		res[i] = '-';
	while (n != 0)
	{
		res[size - i - 1] = ((n % 10) * sign) + '0';
		n = n / 10;
		i++;
	}
	res[size] = '\0';
	return (res);
}
