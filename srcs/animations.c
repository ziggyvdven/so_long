/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvan-de- <zvan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 16:41:33 by zvan-de-          #+#    #+#             */
/*   Updated: 2023/06/15 11:33:48 by zvan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_set_depth(t_game *g, int i)
{
	mlx_set_instance_depth(&g->enemy->img[0]->instances[0], 0);
	mlx_set_instance_depth(&g->enemy->img[1]->instances[0], 0);
	mlx_set_instance_depth(&g->enemy->img[2]->instances[0], 0);
	mlx_set_instance_depth(&g->enemy->img[i]->instances[0], g->imgs - 10);
}

void	move_enemy(t_game *g, t_player *p, t_enemy *e)
{
	if (p->x > e->x)
		ft_move_enemy_right(g, e);
	else if (p->x < e->x)
		ft_move_enemy_left(g, e);
	if (p->y < e->y)
		ft_move_enemy_up(g, e);
	else if (p->y > e->y)
		ft_move_enemy_down(g, e);
	if (p->x == e->x && p->y == e->y)
		g->end = 2;
}

void	ft_check_end(t_game *g)
{
	if (g->end == 1)
	{
		mlx_delete_image(g->mlx, g->player->img);
		g->player->img = make_image(g, "./textures/char_down.png");
		mlx_image_to_window(g->mlx, g->player->img, g->player->x * TILE,
			g->player->y * TILE);
		mlx_image_to_window(g->mlx, make_image(g, "./textures/win.png"),
			((g->width / 2) * TILE) - 144, (g->height / 2 * TILE - 48));
	}
	if (g->end == 2)
	{
		mlx_image_to_window(g->mlx, make_image(g, "./textures/TIG!.png"),
			(g->width / 2) * TILE - 96, g->height / 2 * TILE - 48);
	}
}

void	ft_animations(void *param)
{
	t_game			*g;
	static int		i = -1;
	static int		s = 0;

	g = param;
	ft_check_end(g);
	if (i++ == 0)
		ft_set_depth(g, 0);
	if (i == 10)
		ft_set_depth(g, 1);
	if (i == 20)
		ft_set_depth(g, 2);
	if (i == 30)
	{
		i = -1;
		s++;
		if (s > 3 && g->end == 0)
			move_enemy(g, g->player, g->enemy);
	}
}
