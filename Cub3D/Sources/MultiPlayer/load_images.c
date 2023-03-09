/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 15:59:42 by yhuberla          #+#    #+#             */
/*   Updated: 2023/03/03 15:59:42 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	load_more_running(t_mlx *mlx, t_img *(player_run[8][4]),
	t_img *(gun_shoot[4]))
{
	player_run[5][0] = ft_create_xpmimg(mlx, "maps/xpm/human/run50.xpm", 0);
	player_run[5][1] = ft_create_xpmimg(mlx, "maps/xpm/human/run51.xpm", 1);
	player_run[5][2] = ft_create_xpmimg(mlx, "maps/xpm/human/run52.xpm", 2);
	player_run[5][3] = ft_create_xpmimg(mlx, "maps/xpm/human/run53.xpm", 3);
	player_run[6][0] = ft_create_xpmimg(mlx, "maps/xpm/human/run60.xpm", 0);
	player_run[6][1] = ft_create_xpmimg(mlx, "maps/xpm/human/run61.xpm", 1);
	player_run[6][2] = ft_create_xpmimg(mlx, "maps/xpm/human/run62.xpm", 2);
	player_run[6][3] = ft_create_xpmimg(mlx, "maps/xpm/human/run63.xpm", 3);
	player_run[7][0] = ft_create_xpmimg(mlx, "maps/xpm/human/run70.xpm", 0);
	player_run[7][1] = ft_create_xpmimg(mlx, "maps/xpm/human/run71.xpm", 1);
	player_run[7][2] = ft_create_xpmimg(mlx, "maps/xpm/human/run72.xpm", 2);
	player_run[7][3] = ft_create_xpmimg(mlx, "maps/xpm/human/run73.xpm", 3);
	mlx->gun_idle = ft_create_gunimg(mlx, "maps/xpm/weapons/mgidle.xpm", 0, 1);
	gun_shoot[0] = ft_create_gunimg(mlx, "maps/xpm/weapons/shoot0.xpm", 0, 1);
	gun_shoot[1] = ft_create_gunimg(mlx, "maps/xpm/weapons/shoot13.xpm", 1, 1);
	gun_shoot[2] = ft_create_gunimg(mlx, "maps/xpm/weapons/shoot2.xpm", 2, 1);
	gun_shoot[3] = ft_create_gunimg(mlx, "maps/xpm/weapons/shoot13.xpm", 3, 1);
	mlx->avatar[0] = ft_create_gunimg(mlx, "maps/xpm/human/hud0.xpm", 0, 2);
	mlx->avatar[1] = ft_create_gunimg(mlx, "maps/xpm/human/hud1.xpm", 1, 2);
	mlx->avatar[2] = ft_create_gunimg(mlx, "maps/xpm/human/hud2.xpm", 2, 2);
	mlx->avatar[3] = ft_create_gunimg(mlx, "maps/xpm/human/hud3.xpm", 3, 2);
	mlx->avatar[4] = ft_create_gunimg(mlx, "maps/xpm/human/hud4.xpm", 4, 2);
}

static void	load_running_player(t_mlx *mlx, t_img *(player_run[8][4]))
{
	player_run[0][0] = ft_create_xpmimg(mlx, "maps/xpm/human/run00.xpm", 0);
	player_run[0][1] = ft_create_xpmimg(mlx, "maps/xpm/human/run01.xpm", 1);
	player_run[0][2] = ft_create_xpmimg(mlx, "maps/xpm/human/run02.xpm", 2);
	player_run[0][3] = ft_create_xpmimg(mlx, "maps/xpm/human/run03.xpm", 3);
	player_run[1][0] = ft_create_xpmimg(mlx, "maps/xpm/human/run10.xpm", 0);
	player_run[1][1] = ft_create_xpmimg(mlx, "maps/xpm/human/run11.xpm", 1);
	player_run[1][2] = ft_create_xpmimg(mlx, "maps/xpm/human/run12.xpm", 2);
	player_run[1][3] = ft_create_xpmimg(mlx, "maps/xpm/human/run13.xpm", 3);
	player_run[2][0] = ft_create_xpmimg(mlx, "maps/xpm/human/run20.xpm", 0);
	player_run[2][1] = ft_create_xpmimg(mlx, "maps/xpm/human/run21.xpm", 1);
	player_run[2][2] = ft_create_xpmimg(mlx, "maps/xpm/human/run22.xpm", 2);
	player_run[2][3] = ft_create_xpmimg(mlx, "maps/xpm/human/run23.xpm", 3);
	player_run[3][0] = ft_create_xpmimg(mlx, "maps/xpm/human/run30.xpm", 0);
	player_run[3][1] = ft_create_xpmimg(mlx, "maps/xpm/human/run31.xpm", 1);
	player_run[3][2] = ft_create_xpmimg(mlx, "maps/xpm/human/run32.xpm", 2);
	player_run[3][3] = ft_create_xpmimg(mlx, "maps/xpm/human/run33.xpm", 3);
	player_run[4][0] = ft_create_xpmimg(mlx, "maps/xpm/human/run40.xpm", 0);
	player_run[4][1] = ft_create_xpmimg(mlx, "maps/xpm/human/run41.xpm", 1);
	player_run[4][2] = ft_create_xpmimg(mlx, "maps/xpm/human/run42.xpm", 2);
	player_run[4][3] = ft_create_xpmimg(mlx, "maps/xpm/human/run43.xpm", 3);
	load_more_running(mlx, player_run, mlx->gun_shoot);
}

void	load_player_imgs(t_mlx *m)
{
	m->player_death[0] = ft_create_xpmimg(m, "maps/xpm/human/death0.xpm", 0);
	m->player_death[1] = ft_create_xpmimg(m, "maps/xpm/human/death1.xpm", 1);
	m->player_death[2] = ft_create_xpmimg(m, "maps/xpm/human/death2.xpm", 2);
	m->player_death[3] = ft_create_xpmimg(m, "maps/xpm/human/death3.xpm", 3);
	m->player_death[4] = ft_create_xpmimg(m, "maps/xpm/human/death4.xpm", 4);
	m->player_idle[0] = ft_create_xpmimg(m, "maps/xpm/human/idle0.xpm", 0);
	m->player_idle[1] = ft_create_xpmimg(m, "maps/xpm/human/idle1.xpm", 1);
	m->player_idle[2] = ft_create_xpmimg(m, "maps/xpm/human/idle2.xpm", 2);
	m->player_idle[3] = ft_create_xpmimg(m, "maps/xpm/human/idle3.xpm", 3);
	m->player_idle[4] = ft_create_xpmimg(m, "maps/xpm/human/idle4.xpm", 4);
	m->player_idle[5] = ft_create_xpmimg(m, "maps/xpm/human/idle5.xpm", 5);
	m->player_idle[6] = ft_create_xpmimg(m, "maps/xpm/human/idle6.xpm", 6);
	m->player_idle[7] = ft_create_xpmimg(m, "maps/xpm/human/idle7.xpm", 7);
	m->player_shoot[0] = ft_create_xpmimg(m, "maps/xpm/human/shoot0.xpm", 0);
	m->player_shoot[1] = ft_create_xpmimg(m, "maps/xpm/human/shoot13.xpm", 1);
	m->player_shoot[2] = ft_create_xpmimg(m, "maps/xpm/human/shoot2.xpm", 2);
	m->player_shoot[3] = ft_create_xpmimg(m, "maps/xpm/human/shoot13.xpm", 3);
	load_running_player(m, m->player_run);
}
