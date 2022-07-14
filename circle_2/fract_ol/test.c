#include "miniLibX/mlx.h"
#include <stdlib.h>
#include <stdio.h>

void	*mlx_ptr;
void	*win_ptr;

int	key_check(int key,void *p)
{
	(void)p;
  printf("Key in Win : %d\n",key);
  if (key==53) //esc를 누르면 종료
    exit(0);
  return (1);
}

int main()
{
	
	
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 500, 500, "mlx_test");
	mlx_key_hook(win_ptr, key_check, win_ptr);
	mlx_loop(mlx_ptr);
}