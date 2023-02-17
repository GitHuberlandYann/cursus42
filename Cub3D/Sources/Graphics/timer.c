#include "cub3d.h"

static int	ft_nblen(int nb)
{
	int	res;

	res = 0;
	while (nb > 9)
	{
		nb /= 10;
		++res;
	}
	return (res);
}

static void ft_catitoa(char str[15], int nb, int index)
{
	if (nb > 9)
		ft_catitoa(str, nb / 10, index - 1);
	str[index] = nb % 10 + '0';
}

static int	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

void	add_fps(t_mlx *mlx, t_settings *settings)
{
	int		current_time;
	int		fps_size;

	if (!settings->timepoint)
	{
		settings->timepoint = get_time();
		return ;
	}
	current_time = get_time();
	mlx->fps = 1000.0 / (current_time - settings->timepoint);
	fps_size = ft_nblen(mlx->fps);
	ft_catitoa(mlx->fpstr, mlx->fps, 6 + fps_size);
	mlx->fpstr[7 + fps_size] = '\0';
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 20, 20, WHITE, mlx->fpstr);
	settings->timepoint = current_time;
}
