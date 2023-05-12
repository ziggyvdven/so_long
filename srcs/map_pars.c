/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_pars.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvan-de- <zvan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 15:28:16 by zvan-de-          #+#    #+#             */
/*   Updated: 2023/05/12 16:41:45 by zvan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

t_game	*map_size(t_game *game)
{
	int		fd;
	int		y;
	int		x;
	char	*line;

	x = 0;
	y = 0;
	fd = open(game->map, O_RDONLY);
	if (fd == -1)
		putstr_exit("failed to open map\n", 1);
	line = get_next_line(fd);
	x = ft_strlen(line);
	while (get_next_line(fd))
		y++;
	if (close(fd) == -1)
		ft_putstr_fd("failed to close map\n", 1);
	game->height = (y + 1);
	game->width = x;
	return (game);
}

t_game	*map_pars(t_game *game)
{
	if (game->argc != 2)
		return (NULL);
	map_size(game);
	if (!(ft_strnstr(game->map, ".ber", strlen(game->map))))
		putstr_exit("Invalid map not .ber", 1);
	return (game);
}
