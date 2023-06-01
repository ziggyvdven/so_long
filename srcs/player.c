/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvan-de- <zvan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 14:03:21 by zvan-de-          #+#    #+#             */
/*   Updated: 2023/06/01 14:50:03 by zvan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_moves(mlx_key_data_t keydata, void *param)
{
	t_game	*g;

	g = param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		exit_succes(g);
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
		exit_succes(g);
}

void	ft_move(mlx_key_data_t keydata, t_game *game)
{
	if (keydata.key == MLX_KEY_UP || keydata.key == MLX_KEY_W)
	{
		game->player->char_down->instances[0].y -= TILE;
		game->player->y--;
		mlx_delete_image(game->mlx, game->player->char_down);
		mlx_image_to_window(game->mlx, game->player->char_up, game->player->x * TILE, game->player->y * TILE);
	}
	else if (keydata.key == MLX_KEY_DOWN || keydata.key == MLX_KEY_S)
	{
		game->player->char_down->instances[0].y += TILE;
		game->player->y++;
	}
	else if (keydata.key == MLX_KEY_LEFT || keydata.key == MLX_KEY_A)
	{
		game->player->char_down->instances[0].x -= TILE;
		game->player->x--;
	}
	else if (keydata.key == MLX_KEY_RIGHT || keydata.key == MLX_KEY_D)
	{
		game->player->char_down->instances[0].x += TILE;
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
	mlx_loop_hook(game->mlx, &check_pos, game);
	mlx_image_to_window(game->mlx, game->player->char_down, x, y);
	mlx_key_hook(game->mlx, &ft_moves, game);
}
