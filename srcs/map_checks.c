/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvan-de- <zvan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 15:51:48 by zvan-de-          #+#    #+#             */
/*   Updated: 2023/05/19 16:31:35 by zvan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	map_rec(t_game *game)
{
	t_node		*ptr;
	uint32_t	i;
	uint32_t	y;

	ptr = game->map_lst;
	y = 0;
	while (y < game->height)
	{
		i = 0;
		while (ptr->str[i] != '\n' && ptr->str[i] != '\0')
			i++;
		if (i != game->width)
			return (0);
		ptr = ptr->next;
		y++;
	}
	return (1);
}

int	map_close(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (game->map[y][x] != '\0')
	{
		if (game->map[0][x] != '1' || game->map[game->height - 1][x] != '1')
			return (0);
		x++;
	}
	while (game->map[y] != NULL)
	{
		if (game->map[y][0] != '1' || game->map[y][game->width - 1] != '1')
			return (0);
		y++;
	}
	return (1);
}

char	*map_entries(t_game *game, char *str)
{
	int		x;
	int		y;

	y = 0;
	while (game->map[y] != NULL)
	{
		x = 0;
		while (game->map[y][x] != '\0')
		{
			if (strchr(str, game->map[y][x]) == NULL)
				return ("Error\nINVALID MAP (UNRECOGNIZED ENTRY)");
			if (game->map[y][x] == 'C')
				game->collectables++;
			x++;
		}
		y++;
	}
	if (game->collectables == 0)
		return ("Error\nINVALID MAP (COLLECTABLES)");
	return (0);
}

char	*map_elements(t_game *game)
{
	int		player;
	int		exit;
	int		x;
	int		y;

	y = -1;
	x = -1;
	player = 0;
	exit = 0;
	while (game->map[++y] != NULL)
	{
		x = 0;
		while (game->map[y][++x] != '\0')
		{
			if (game->map[y][x] == 'P')
				player++;
			if (game->map[y][x] == 'E')
				exit++;
		}
	}
	if (player != 1)
		return ("Error\nINVALID MAP (PLAYERS)");
	if (exit != 1)
		return ("Error\nINVALID MAP (EXITS)");
	return (0);
}

