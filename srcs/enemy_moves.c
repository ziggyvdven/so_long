/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvan-de- <zvan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 15:57:36 by zvan-de-          #+#    #+#             */
/*   Updated: 2023/06/15 11:37:21 by zvan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static char	*g_down[3] = {
	"./textures/cori_down1.png",
	"./textures/cori_down2.png",
	"./textures/cori_down3.png"
};

static char	*g_up[3] = {
	"./textures/cori_up1.png",
	"./textures/cori_up2.png",
	"./textures/cori_up3.png"
};

static char	*g_left[3] = {
	"./textures/cori_left1.png",
	"./textures/cori_left2.png",
	"./textures/cori_left3.png"
};

static char	*g_right[3] = {
	"./textures/cori_right1.png",
	"./textures/cori_right2.png",
	"./textures/cori_right3.png"
};

void	ft_move_enemy_down(t_game *g, t_enemy *e)
{	
	int	i;

	i = -1;
	if (g->map[e->y + 1][e->x] != '1')
	{
		while (e->img[++i])
			e->img[i]->instances[0].y += TILE;
		e->y++;
	}
	i = 0;
	while (g->enemy->img[i])
	{
		mlx_delete_image(g->mlx, e->img[i]);
		e->img[i] = make_image(g, g_down[i]);
		mlx_image_to_window(g->mlx, e->img[i++], e->x * TILE, e->y * TILE);
	}
}

void	ft_move_enemy_up(t_game *g, t_enemy *e)
{	
	int	i;

	i = -1;
	if (g->map[e->y - 1][e->x] != '1')
	{
		while (e->img[++i])
			e->img[i]->instances[0].y += TILE;
		e->y--;
	}
	i = 0;
	while (g->enemy->img[i])
	{
		mlx_delete_image(g->mlx, e->img[i]);
		e->img[i] = make_image(g, g_up[i]);
		mlx_image_to_window(g->mlx, e->img[i++], e->x * TILE, e->y * TILE);
	}
}

void	ft_move_enemy_left(t_game *g, t_enemy *e)
{	
	int	i;

	i = -1;
	if (g->map[e->y][e->x - 1] != '1')
	{
		while (e->img[++i])
			e->img[i]->instances[0].y += TILE;
		e->x--;
	}
	i = 0;
	while (g->enemy->img[i])
	{
		mlx_delete_image(g->mlx, e->img[i]);
		e->img[i] = make_image(g, g_left[i]);
		mlx_image_to_window(g->mlx, e->img[i++], e->x * TILE, e->y * TILE);
	}
}

void	ft_move_enemy_right(t_game *g, t_enemy *e)
{	
	int	i;

	i = -1;
	if (g->map[e->y][e->x + 1] != '1')
	{
		while (e->img[++i])
			e->img[i]->instances[0].y += TILE;
		e->x++;
	}
	i = 0;
	while (g->enemy->img[i])
	{
		mlx_delete_image(g->mlx, e->img[i]);
		e->img[i] = make_image(g, g_right[i]);
		mlx_image_to_window(g->mlx, e->img[i++], e->x * TILE, e->y * TILE);
	}
}
