/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvan-de- <zvan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 14:03:21 by zvan-de-          #+#    #+#             */
/*   Updated: 2023/06/02 19:40:22 by zvan-de-         ###   ########.fr       */
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
	i = g->collectables - 1;
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
	if (g->collected == g->collectables)
		exit_open(g);
	if (g->map[g->player->y][g->player->x] == 'E'
		&& g->collectables == g->collected)
	{
		exit_animation(g, g->player);
	}
}

void	exit_open(t_game *g)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (g->map[++y] != NULL)
	{
		x = 0;
		while (g->map[y][++x] != '\0')
		{
			if (g->map[y][x] == 'E')
			{
				mlx_delete_image(g->mlx, g->img->exit);
				g->img->exit = make_image(g, "./textures/exit_open.png");
				mlx_image_to_window(g->mlx, g->img->exit, x * TILE, y * TILE);
			}
		}
	}
}

void	ft_player(t_game *game, t_player *p)
{
	mlx_image_to_window(game->mlx, game->player->img, p->x * TILE, p->y * TILE);
	mlx_key_hook(game->mlx, &ft_moves, game);
}
