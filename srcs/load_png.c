/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_png.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvandeven <zvandeven@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 15:09:47 by zvan-de-          #+#    #+#             */
/*   Updated: 2023/05/26 16:02:00 by zvandeven        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

mlx_image_t	*make_image(t_game *game, char *texture_path)
{
	mlx_image_t		*img;
	mlx_texture_t	*texture;

	texture = mlx_load_png(texture_path);
	img = mlx_texture_to_image(game->mlx, texture);
	mlx_delete_texture(texture);
	return (img);
}

t_game	*load_png(t_game *game)
{
	game->img->floor = make_image(game, "./textures/floor.png");
	game->img->wall_b = make_image(game, "./textures/mac_bottom.png");
	game->img->wall_t = make_image(game, "./textures/mac_top.png");
	game->img->wall_l = make_image(game, "./textures/mac_left.png");
	game->img->wall_r = make_image(game, "./textures/mac_right.png");
	game->img->wall_e = make_image(game, "./textures/empty.png");
	game->img->coll = make_image(game, "./textures/42_Logo.png");
	game->img->exit = make_image(game, "./textures/exit.png");
	game->player->img = make_image(game, "./textures/char.png");
	return (game);
}
