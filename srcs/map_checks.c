/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvandeven <zvandeven@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 15:51:48 by zvan-de-          #+#    #+#             */
/*   Updated: 2023/05/26 15:14:48 by zvandeven        ###   ########.fr       */
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
	t_data	*d;

	d = init_data();
	while (game->map[d->y + 1][++d->x] != '\0')
	{
		if (game->map[0][d->x] != '1'
			|| game->map[game->height - 1][d->x] != '1')
			return (0);
	}
	while (game->map[++d->y] != NULL)
	{
		if (game->map[d->y][0] != '1'
			|| game->map[d->y][game->width - 1] != '1')
			return (0);
	}
	return (1);
}

char	*map_entries(t_game *game, char *str)
{
	t_data	*data;

	data = init_data();
	while (game->map[++data->y] != NULL)
	{
		data->x = 0;
		while (game->map[data->y][++data->x] != '\0')
		{
			if (strchr(str, game->map[data->y][data->x]) == NULL)
				return ("Error\nINVALID MAP (UNRECOGNIZED ENTRY)");
			if (game->map[data->y][data->x] == 'C')
				game->collectables++;
		}
	}
	free (data);
	if (game->collectables == 0)
		return ("Error\nINVALID MAP (COLLECTABLES)");
	return (0);
}

char	*map_elements(t_game *game)
{
	t_data	*data;

	data = init_data();
	while (game->map[++data->y] != NULL)
	{
		data->x = 0;
		while (game->map[data->y][++data->x] != '\0')
		{
			if (game->map[data->y][data->x] == 'P')
			{
				game->player->x = data->x;
				game->player->y = data->y;
				data->player++;
			}
			if (game->map[data->y][data->x] == 'E')
				data->exit++;
		}
	}
	if (data->player != 1)
		return ("Error\nINVALID MAP (PLAYERS)");
	if (data->exit != 1)
		return ("Error\nINVALID MAP (EXITS)");
	free (data);
	return (0);
}
