#include "cub3d.h"

static int	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

void	add_fps(t_mlx *mlx, t_settings *settings)
{
	int		current_time;
	double	fps;
	char	*fpstr;

	if (!settings->timepoint)
	{
		settings->timepoint = get_time();
		return ;
	}
	current_time = get_time();
	fps = 1000.0 / (current_time - settings->timepoint);
	fpstr = ft_itoa(fps);
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 20, 20, WHITE, fpstr);
	free(fpstr);
	settings->timepoint = current_time;
}
