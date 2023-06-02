/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvan-de- <zvan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 12:20:10 by zvan-de-          #+#    #+#             */
/*   Updated: 2023/06/02 19:03:23 by zvan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

t_game	*fill_map(t_game *game)
{
	game = load_png(game);
	fill_floor(game, game->img, 0, -1);
	fill_walls(game, game->img, 0, 0);
	fill_backgr(game, game->img, 0, 0);
	game = fill_elements(game, game->img);
	return (game);
}

void	fill_floor(t_game *g, t_images *img, uint32_t x, uint32_t y)
{
	while (g->map[++y] != NULL)
	{
		x = -1;
		while (g->map[y][++x] != '\0')
		{
			if (g->map[y][x] == '0' || g->map[y][x] == 'P'
			|| g->map[y][x] == 'E' || g->map[y][x] == 'C'
			|| g->map[y][x] == '1')
				mlx_image_to_window(g->mlx, img->floor, x * TILE, y * TILE);
		}
	}
}

void	fill_walls(t_game *g, t_images *img, uint32_t x, uint32_t y)
{
	mlx_image_to_window(g->mlx, img->wall_tlc, 0, 0);
	mlx_image_to_window(g->mlx, img->wall_trc, (g->width - 1) * TILE, 0);
	mlx_image_to_window(g->mlx, img->wall_lbc, 0, (g->height - 1) * TILE);
	mlx_image_to_window(g->mlx, img->wall_rbc,
		(g->width - 1) * TILE, (g->height - 1) * TILE);
	while (g->map[y][++x + 1] != '\0')
	{
		mlx_image_to_window(g->mlx, img->wall_t, x * TILE, y * TILE);
		mlx_image_to_window(g->mlx, img->wall_b,
			x * TILE, (y + g->height - 1) * TILE);
	}
	x = 0;
	y = 0;
	while (g->map[y++ + 2] != NULL)
	{
		mlx_image_to_window(g->mlx, img->wall_l, 0, y * TILE);
		mlx_image_to_window(g->mlx, img->wall_r,
			(g->width - 1) * TILE, y  * TILE);
	}
}

void	fill_backgr(t_game *g, t_images *img, uint32_t x, uint32_t y)
{
	while (g->map[++y + 1] != NULL)
	{
		x = 0;
		while (g->map[y][++x + 1] != '\0')
		{
			if (g->map[y][x] == '1'
				&& y != g->height - 1 && g->map[y + 1][x] != '1')
				mlx_image_to_window(g->mlx, img->mac_b, x * TILE, y * TILE);
			else if (g->map[y][x] == '1' && y != 0 && g->map[y - 1][x] != '1')
				mlx_image_to_window(g->mlx, img->mac_t, x * TILE, y * TILE);
			else if (g->map[y][x] == '1'
				&& x != g->width - 1 && g->map[y][x + 1] != '1')
				mlx_image_to_window(g->mlx, img->mac_r, x * TILE, y * TILE);
			else if (g->map[y][x] == '1' && x != 0 && g->map[y][x - 1] != '1')
				mlx_image_to_window(g->mlx, img->mac_l, x * TILE, y * TILE);
			else if (g->map[y][x] == '1')
				mlx_image_to_window(g->mlx, img->wall_e, x * TILE, y * TILE);
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
