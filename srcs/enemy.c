/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvan-de- <zvan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 16:58:39 by zvan-de-          #+#    #+#             */
/*   Updated: 2023/06/07 17:15:27 by zvan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

t_enemy	*init_enemy(t_game *game)
{
	t_enemy	*enemy;

	enemy = (t_enemy *)ft_calloc((sizeof(t_enemy)), 1);
	if (!enemy)
		return (NULL);
	enemy->x = 0;
	enemy->y = 0;
	enemy->img1 = make_image(game, "./textures/wall_rbc.png");
	enemy->img2 = make_image(game, "./textures/wall_trc.png");
	enemy->img3 = make_image(game, "./textures/wall_tlc.png");
	return (enemy);
}

void	ft_enemy(t_game *game)
{
	init_enemy(game);
	mlx_image_to_window(game->mlx, game->enemy->img1, 96, 96);
}
