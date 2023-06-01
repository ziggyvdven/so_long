/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvan-de- <zvan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 15:24:24 by zvan-de-          #+#    #+#             */
/*   Updated: 2023/06/01 16:06:34 by zvan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	move_up(t_game *g, t_player *p)
{
	if (g->map[p->y - 1][p->x] != '1')
	{
		p->img->instances[0].y += TILE;
		p->y--;
		g->player->move_count++;
	}
	mlx_delete_image(g->mlx, p->img);
	p->img = make_image(g, "./textures/char_up.png");
	mlx_image_to_window(g->mlx, p->img, p->x * TILE, p->y * TILE);
	check_pos(g);
}

void	move_down(t_game *g, t_player *p)
{
	if (g->map[p->y + 1][p->x] != '1')
	{
		p->img->instances[0].y += TILE;
		p->y++;
		g->player->move_count++;
	}
	mlx_delete_image(g->mlx, p->img);
	p->img = make_image(g, "./textures/char_down.png");
	mlx_image_to_window(g->mlx, p->img, p->x * TILE, p->y * TILE);
	check_pos(g);
}

void	move_left(t_game *g, t_player *p)
{
	if (g->map[p->y][p->x - 1] != '1')
	{
		p->img->instances[0].y += TILE;
		p->x--;
		g->player->move_count++;
	}
	mlx_delete_image(g->mlx, p->img);
	p->img = make_image(g, "./textures/char_left.png");
	mlx_image_to_window(g->mlx, p->img, p->x * TILE, p->y * TILE);
	check_pos(g);
}

void	move_right(t_game *g, t_player *p)
{
	if (g->map[p->y][p->x + 1] != '1')
	{
		p->img->instances[0].y += TILE;
		p->x++;
		g->player->move_count++;
	}
	mlx_delete_image(g->mlx, p->img);
	p->img = make_image(g, "./textures/char_right.png");
	mlx_image_to_window(g->mlx, p->img, p->x * TILE, p->y * TILE);
	check_pos(g);
}

void	exit_animation(t_game *g, t_player *p)
{
	(void) p;
	sleep(1);
	// mlx_set_instance_depth(&g->img->exit->instances[0], -1);
	// mlx_delete_image(g->mlx, p->img);
	// p->img = make_image(g, "./textures/char_right.png");
	// mlx_image_to_window(g->mlx, p->img, p->x * TILE, p->y * TILE);
	// sleep(1);
	// mlx_delete_image(g->mlx, p->img);
	// p->img = make_image(g, "./textures/char_up.png");
	// mlx_image_to_window(g->mlx, p->img, p->x * TILE, p->y * TILE);
	// sleep(1);
	// mlx_delete_image(g->mlx, p->img);
	// p->img = make_image(g, "./textures/char_left.png");
	// mlx_image_to_window(g->mlx, p->img, p->x * TILE, p->y * TILE);
	// sleep(1);
	// mlx_delete_image(g->mlx, p->img);
	// p->img = make_image(g, "./textures/char_down.png");
	// mlx_image_to_window(g->mlx, p->img, p->x * TILE, p->y * TILE);
	// sleep(1);
	exit_succes(g);
}
