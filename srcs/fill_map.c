/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvandeven <zvandeven@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 12:20:10 by zvan-de-          #+#    #+#             */
/*   Updated: 2023/05/26 18:22:27 by zvandeven        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

t_game	*fill_map(t_game *game)
{
	game = load_png(game);
	fill_background(game, game->img, 0, -1);
	game = fill_elements(game, game->img);
	return (game);
}

void	fill_background(t_game *g, t_images *img, uint32_t	x, uint32_t	y)
{
	while (g->map[++y] != NULL)
	{
		x = -1;
		while (g->map[y][++x] != '\0')
		{
			if (g->map[y][x] == '1'
				&& y != g->height - 1 && g->map[y + 1][x] != '1')
				mlx_image_to_window(g->mlx, img->wall_t, x * TILE, y * TILE);
			else if (g->map[y][x] == '1' && y != 0 && g->map[y - 1][x] != '1')
				mlx_image_to_window(g->mlx, img->wall_b, x * TILE, y * TILE);
			else if (g->map[y][x] == '1'
				&& x != g->width - 1 && g->map[y][x + 1] != '1')
				mlx_image_to_window(g->mlx, img->wall_l, x * TILE, y * TILE);
			else if (g->map[y][x] == '1' && x != 0 && g->map[y][x - 1] != '1')
				mlx_image_to_window(g->mlx, img->wall_r, x * TILE, y * TILE);
			else if (g->map[y][x] == '1')
				mlx_image_to_window(g->mlx, img->wall_e, x * TILE, y * TILE);
			else if (g->map[y][x] == '0' || g->map[y][x] == 'P'
			|| g->map[y][x] == 'E' || g->map[y][x] == 'C')
				mlx_image_to_window(g->mlx, img->floor, x * TILE, y * TILE);
		}
	}
}

t_game	*fill_elements(t_game *game, t_images *img)
{
	int				x;
	int				y;

	y = -1;
	while (game->map[++y] != NULL)
	{
		x = -1;
		while (game->map[y][++x] != '\0')
		{
			if (game->map[y][x] == '1' || game->map[y][x] == '0')
				continue ;
			else if (game->map[y][x] == 'P')
			{
				game->player->x = x;
				game->player->y = y;
			}
			else if (game->map[y][x] == 'E')
				mlx_image_to_window(game->mlx, img->exit, x * TILE, y * TILE);
			else if (game->map[y][x] == 'C')
				mlx_image_to_window(game->mlx, img->coll, x * TILE, y * TILE);
		}
	}
	return (game);
}
