/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_png.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvan-de- <zvan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 15:09:47 by zvan-de-          #+#    #+#             */
/*   Updated: 2023/06/02 16:41:37 by zvan-de-         ###   ########.fr       */
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
	game->img->exit = make_image(game, "./textures/exit.png");
	game->player->img = make_image(game, "./textures/char_down.png");
	game->img->coll = make_image(game, "./textures/collectable.png");
	game->img->floor = make_image(game, "./textures/floor.png");
	game->img->wall_b = make_image(game, "./textures/wall_bottom.png");
	game->img->wall_t = make_image(game, "./textures/wall_top.png");
	game->img->wall_l = make_image(game, "./textures/wall_left.png");
	game->img->wall_r = make_image(game, "./textures/wall_right.png");
	game->img->wall_e = make_image(game, "./textures/empty.png");
	game->img->wall_lbc = make_image(game, "./textures/wall_lbc.png");
	game->img->wall_rbc = make_image(game, "./textures/wall_rbc.png");
	game->img->wall_trc = make_image(game, "./textures/wall_trc.png");
	game->img->wall_tlc = make_image(game, "./textures/wall_tlc.png");
	game->img->mac_b = make_image(game, "./textures/mac_bottom.png");
	game->img->mac_t = make_image(game, "./textures/mac_top.png");
	game->img->mac_l = make_image(game, "./textures/mac_left.png");
	game->img->mac_r = make_image(game, "./textures/mac_right.png");
	return (game);
}
