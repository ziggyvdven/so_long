/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvan-de- <zvan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 15:51:48 by zvan-de-          #+#    #+#             */
/*   Updated: 2023/05/31 18:13:09 by zvan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	map_rec(t_game *game)
{
	t_node		*ptr;
	uint32_t	i;
	uint32_t	y;

	ptr = game->map_lst;
	y = -1;
	while (++y < game->height)
	{
		i = 0;
		while (ptr->str[i] != '\n' && ptr->str[i] != '\0')
			i++;
		if (i != game->width)
			return (0);
		if (ptr->next != NULL)
			ptr = ptr->next;
	}
	if (strnstr(ptr->str, "\n", strlen(ptr->str)))
		return (0);
	return (1);
}

int	map_close(t_game *game)
{
	int	x;
	int	y;

	x = -1;
	y = 0;
	while (game->map[y][++x] != '\0')
	{
		if (game->map[0][x] != '1'
			|| game->map[game->height - 1][x] != '1')
			return (0);
	}
	y = -1;
	while (game->map[++y] != NULL)
	{
		if (game->map[y][0] != '1'
			|| game->map[y][game->width - 1] != '1')
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
			{
				free(data);
				return ("Error\nINVALID MAP (UNRECOGNIZED ENTRY)");
			}
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
	if (data->player != 1 || data->exit != 1)
	{
		free(data);
		return ("Error\nINVALID MAP (PLAYERS/EXITS)");
	}
	free(data);
	return (0);
}
