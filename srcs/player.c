/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvan-de- <zvan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 14:03:21 by zvan-de-          #+#    #+#             */
/*   Updated: 2023/06/01 18:39:14 by zvan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_moves(mlx_key_data_t keydata, void *param)
{
	t_game	*g;

	g = param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		exit_succes(g);
	if (mlx_is_key_down(g->mlx, 265) || mlx_is_key_down(g->mlx, 87))
		move_up(g, g->player);
	else if (mlx_is_key_down(g->mlx, 264) || mlx_is_key_down(g->mlx, 83))
		move_down(g, g->player);
	else if (mlx_is_key_down(g->mlx, 263) || mlx_is_key_down(g->mlx, 65))
		move_left(g, g->player);
	else if (mlx_is_key_down(g->mlx, 262) || mlx_is_key_down(g->mlx, 68))
		move_right(g, g->player);
	ft_printf("Move count: %d\n", g->player->move_count);
	return ;
}

void	check_pos(void *param)
{
	t_game	*g;
	int		i;

	g = param;
	i = g->collectables;
	while (i > -1)
	{
		if (g->player->x * TILE == g->img->coll->instances[i].x
			&& g->player->y * TILE == g->img->coll->instances[i].y
			&& g->map[g->player->y][g->player->x] == 'C')
		{
			mlx_set_instance_depth(&g->img->coll->instances[i], -1);
			g->map[g->player->y][g->player->x] = '0';
			g->collected++;
		}
	i--;
	}	
	if (g->map[g->player->y][g->player->x] == 'E'
		&& g->collectables == g->collected)
		exit_animation(g, g->player);
}

void	ft_player(t_game *game, t_player *p)
{
	mlx_image_to_window(game->mlx, game->player->img, p->x * TILE, p->y * TILE);
	mlx_key_hook(game->mlx, &ft_moves, game);
}
