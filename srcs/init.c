/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvan-de- <zvan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 15:37:10 by zvan-de-          #+#    #+#             */
/*   Updated: 2023/06/07 17:14:01 by zvan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

t_data	*init_data(void)
{
	t_data	*data;

	data = (t_data *)ft_calloc((sizeof(t_data)), 1);
	if (!data)
		return (NULL);
	data->player = 0;
	data->exit = 0;
	data->x = -1;
	data->y = -1;
	return (data);
}

t_images	*init_images(void)
{
	t_images	*images;

	images = (t_images *)ft_calloc((sizeof(t_images)), 1);
	if (!images)
		return (NULL);
	images->floor = NULL;
	images->coll = NULL;
	images->exit = NULL;
	images->wall_t = NULL;
	images->wall_b = NULL;
	images->wall_l = NULL;
	images->wall_r = NULL;
	images->wall_e = NULL;
	images->wall_trc = NULL;
	images->wall_tlc = NULL;
	images->wall_lbc = NULL;
	images->wall_rbc = NULL;
	images->mac_b = NULL;
	images->mac_t = NULL;
	images->mac_l = NULL;
	images->mac_r = NULL;
	return (images);
}

t_player	*init_player(void)
{
	t_player	*player;

	player = (t_player *)ft_calloc((sizeof(t_player)), 1);
	if (!player)
		return (NULL);
	player->x = 0;
	player->y = 0;
	player->move_count = 0;
	player->img = NULL;
	return (player);
}

t_game	*game_init(int argc, char **argv)
{
	t_game	*game;

	game = (t_game *)ft_calloc((sizeof(t_game)), 1);
	if (!game)
		return (NULL);
	game->argc = argc;
	game->map_lst = NULL;
	game->map_path = ft_strjoin("maps/", argv[1]);
	game->map = NULL;
	game->mlx = NULL;
	game->width = 0;
	game->height = 0;
	game->collectables = 0;
	game->collected = 0;
	game->move_count = NULL;
	game->img = init_images();
	game->player = init_player();
	game->enemy = NULL;
	game->end = false;
	return (game);
}

void	game_free(t_game *game)
{
	game->argc = 0;
	game->map_lst = NULL;
	game->map_path = NULL;
	game->map = NULL;
	game->mlx = NULL;
	game->width = 0;
	game->height = 0;
	game->collectables = 0;
	game->move_count = NULL;
	free(game->img);
	game->img = NULL;
	free(game->player);
	game->player = NULL;
	free(game);
}
