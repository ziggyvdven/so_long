/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvan-de- <zvan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 14:03:21 by zvan-de-          #+#    #+#             */
/*   Updated: 2023/05/21 18:07:59 by zvan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_moves(mlx_key_data_t keydata, void *param)
{
	t_game	*g;

	g = param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		exit(0);
	if ((mlx_is_key_down(g->mlx, MLX_KEY_UP)
			|| mlx_is_key_down(g->mlx, MLX_KEY_W)) && ft_movable(keydata, g))
		ft_move(keydata, g);
	else if ((mlx_is_key_down(g->mlx, MLX_KEY_DOWN)
			|| mlx_is_key_down(g->mlx, MLX_KEY_S)) && ft_movable(keydata, g))
		ft_move(keydata, g);
	else if ((mlx_is_key_down(g->mlx, MLX_KEY_LEFT)
			|| mlx_is_key_down(g->mlx, MLX_KEY_A)) && ft_movable(keydata, g))
		ft_move(keydata, g);
	else if ((mlx_is_key_down(g->mlx, MLX_KEY_RIGHT)
			|| mlx_is_key_down(g->mlx, MLX_KEY_D)) && ft_movable(keydata, g))
		ft_move(keydata, g);
}

void	ft_move(mlx_key_data_t keydata, t_game *game)
{
	if (keydata.key == MLX_KEY_UP || keydata.key == MLX_KEY_W)
	{
		game->player->img->instances[0].y -= TILE;
		game->player->y--;
	}
	else if (keydata.key == MLX_KEY_DOWN || keydata.key == MLX_KEY_S)
	{
		game->player->img->instances[0].y += TILE;
		game->player->y++;
	}
	else if (keydata.key == MLX_KEY_LEFT || keydata.key == MLX_KEY_A)
	{
		game->player->img->instances[0].x -= TILE;
		game->player->x--;
	}
	else if (keydata.key == MLX_KEY_RIGHT || keydata.key == MLX_KEY_D)
	{
		game->player->img->instances[0].x += TILE;
		game->player->x++;
	}
	game->player->move_count++;
	ft_printf("Move count: %d\n", game->player->move_count);
	return ;
}

int	ft_movable(mlx_key_data_t keydata, t_game *game)
{
	if (keydata.key == MLX_KEY_UP || keydata.key == MLX_KEY_W)
		if (game->map[game->player->y - 1][game->player->x] == '1')
			return (0);
	if (keydata.key == MLX_KEY_DOWN || keydata.key == MLX_KEY_S)
		if (game->map[game->player->y + 1][game->player->x] == '1')
			return (0);
	if (keydata.key == MLX_KEY_LEFT || keydata.key == MLX_KEY_A)
		if (game->map[game->player->y][game->player->x - 1] == '1')
			return (0);
	if (keydata.key == MLX_KEY_RIGHT || keydata.key == MLX_KEY_D)
		if (game->map[game->player->y][game->player->x + 1] == '1')
			return (0);
	return (1);
}

void	ft_player(t_game *game)
{
	int	x;
	int	y;

	x = game->player->x * TILE;
	y = game->player->y * TILE;
	mlx_image_to_window(game->mlx, game->player->img, x, y);
	mlx_key_hook(game->mlx, &ft_moves, game);
}
