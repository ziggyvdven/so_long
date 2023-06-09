/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvan-de- <zvan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 16:58:39 by zvan-de-          #+#    #+#             */
/*   Updated: 2023/06/09 16:14:57 by zvan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include <time.h>

t_enemy	*init_enemy(t_game *game)
{
	t_enemy	*enemy;

	enemy = (t_enemy *)ft_calloc((sizeof(t_enemy)), 1);
	if (!enemy)
		return (NULL);
	enemy->x = 0;
	enemy->y = 0;
	enemy->img[0] = make_image(game, "./textures/cori_down1.png");
	enemy->img[1] = make_image(game, "./textures/cori_down2.png");
	enemy->img[2] = make_image(game, "./textures/cori_down3.png");
	enemy->img[3] = NULL;
	return (enemy);
}

uint32_t	random_num(u_int32_t i)
{
	time_t	t;

	srand((unsigned) time(&t));
	return (rand() % i);
}

int	find_random_empty_spot(t_game *g, int i)
{
	g->enemy->x = random_num(g->width - 1);
	g->enemy->y = random_num(g->height - 1);
	while (g->map[g->enemy->y][g->enemy->x] != '0')
	{
		while (g->map[g->enemy->y++] != NULL)
		{
			g->enemy->x = 0;
			while (g->map[g->enemy->y][g->enemy->x++] != '\0')
			{
				if (g->map[g->enemy->y][g->enemy->x] == '0')
					return (1);
				if (g->enemy->y == g->height - 1)
				{
					g->enemy->y = 0;
					i++;
				}
				if (i == 2)
					return (0);
			}
		}
	}
	return (1);
}

int	ft_enemy(t_game *game)
{
	int		i;

	i = 0;
	ft_printf("imgs: %d\n", game->imgs);
	game->enemy = init_enemy(game);
	if (find_random_empty_spot(game, 0))
	{
		while (game->enemy->img[i])
			mlx_image_to_window(game->mlx, game->enemy->img[i++],
				game->enemy->x * 96, game->enemy->y * 96);
		return (1);
	}
	return (0);
}
