/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvan-de- <zvan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 12:20:10 by zvan-de-          #+#    #+#             */
/*   Updated: 2023/05/21 16:09:46 by zvan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

t_game	*fill_map(t_game *game)
{
	game = load_png(game);
	fill_background(game, game->img);
	game = fill_elements(game, game->img);
	return (game);
}

void	fill_background(t_game *game, t_images *img)
{
	int				x;
	int				y;

	y = -1;
	while (game->map[++y] != NULL)
	{
		x = -1;
		while (game->map[y][++x] != '\0')
		{
			if (game->map[y][x] == '1')
				mlx_image_to_window(game->mlx, img->wall, x * TILE, y * TILE);
			else if (game->map[y][x] == '0' || game->map[y][x] == 'P'
			|| game->map[y][x] == 'E' || game->map[y][x] == 'C')
				mlx_image_to_window(game->mlx, img->floor, x * TILE, y * TILE);
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
