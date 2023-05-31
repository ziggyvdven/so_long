/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvan-de- <zvan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 18:20:04 by zvan-de-          #+#    #+#             */
/*   Updated: 2023/05/31 18:25:52 by zvan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

char	**map_copy(t_game *game, char **copy)
{
	uint32_t	i;

	i = -1;
	copy = (char **)ft_calloc(sizeof(char *), game->height + 1);
	if (!copy)
		exit_failure(game, "FAILED TO MALLOC MAP COPY");
	while (++i < game->height)
		copy[i] = ft_strdup(game->map[i]);
	copy[i] = NULL;
	return (copy);
}

t_map	*check_spot(t_game *game, t_map *copy, int x, int y)
{
	if (game->map[y][x] == 'E')
		copy->exit++;
	if (game->map[y][x] == 'C')
		copy->collectables++;
	return (copy);
}

void	flood(t_game *game, t_map *copy, uint32_t x, uint32_t y)
{
	if (x < 0 || y < 0 || x >= game->width || y >= game->height)
		return ;
	if (copy->map[y][x] == '1')
		return ;
	copy = check_spot(game, copy, x, y);
	copy->map[y][x] = '1';
	flood(game, copy, x - 1, y);
	flood(game, copy, x + 1, y);
	flood(game, copy, x, y - 1);
	flood(game, copy, x, y + 1);
}

int	flood_fill(t_game *game)
{
	t_map	copy;

	copy.collectables = 0;
	copy.exit = 0;
	copy.map = map_copy(game, copy.map);
	flood(game, &copy, game->player->x, game->player->y);
	ft_free_ar(copy.map);
	copy.map = NULL;
	if (copy.exit != 1 || copy.collectables != game->collectables)
		return (1);
	return (0);
}
