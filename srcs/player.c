/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvan-de- <zvan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 14:03:21 by zvan-de-          #+#    #+#             */
/*   Updated: 2023/06/07 16:39:39 by zvan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"


void	ft_moves(mlx_key_data_t keydata, void *param)
{
	t_game	*g;

	g = param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		exit_succes(g);
	if (g->end == true)
		ft_game_end(g);
	if (g->end == false)
	{
		if (mlx_is_key_down(g->mlx, 265) || mlx_is_key_down(g->mlx, 87))
			move_up(g, g->player);
		else if (mlx_is_key_down(g->mlx, 264) || mlx_is_key_down(g->mlx, 83))
			move_down(g, g->player);
		else if (mlx_is_key_down(g->mlx, 263) || mlx_is_key_down(g->mlx, 65))
			move_left(g, g->player);
		else if (mlx_is_key_down(g->mlx, 262) || mlx_is_key_down(g->mlx, 68))
			move_right(g, g->player);
	}
	return ;
}

void	check_pos(void *param)
{
	t_game	*g;
	int		i;

	g = param;
	i = g->collectables - 1;
	ft_move_count(g);
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
		g->end = true;
}

void	ft_move_count(void *param)
{
	t_game	*g;
	char	*str;

	g = param;
	mlx_delete_image(g->mlx, g->move_count);
	str = ft_itoa(g->player->move_count);
	g->move_count = mlx_put_string(g->mlx, str, 163, (g->height - 0.5) * TILE);
	free (str);
}

void	ft_game_end(void *param)
{
	t_game		*g;
	t_player	*p;
	int			i;

	g = param;
	p = g->player;
	i = 100;
	if (g->end == true)
	{
		mlx_delete_image(g->mlx, p->img);
		p->img = make_image(g, "./textures/char_up.png");
		mlx_image_to_window(g->mlx, p->img, p->x * TILE, p->y * TILE);
	}
}


void	ft_player(t_game *g, t_player *p)
{
	mlx_put_string(g->mlx, "Moves:", 1 * TILE, (g->height - 0.5) * TILE);
	g->move_count = mlx_put_string(g->mlx, "0", 163, (g->height - 0.5) * TILE);
	mlx_image_to_window(g->mlx, g->player->img, p->x * TILE, p->y * TILE);
	mlx_key_hook(g->mlx, &ft_moves, g);
}
