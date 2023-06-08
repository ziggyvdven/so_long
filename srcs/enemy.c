/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvan-de- <zvan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 16:58:39 by zvan-de-          #+#    #+#             */
/*   Updated: 2023/06/08 11:44:31 by zvan-de-         ###   ########.fr       */
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
	enemy->img[0] = make_image(game, "./textures/zombie1.png");
	enemy->img[1] = make_image(game, "./textures/zombie2.png");
	enemy->img[2] = make_image(game, "./textures/zombie3.png");
	enemy->img[3] = NULL;
	return (enemy);
}

void	ft_enemy(t_game *game)
{
	int		i;

	i = 0;
	game->enemy = init_enemy(game);
	while (game->enemy->img[i])
		mlx_image_to_window(game->mlx, game->enemy->img[i++], 96, 96);
}
