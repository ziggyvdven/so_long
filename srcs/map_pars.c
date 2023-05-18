/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_pars.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvan-de- <zvan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 15:28:16 by zvan-de-          #+#    #+#             */
/*   Updated: 2023/05/18 13:23:18 by zvan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

t_game	*map_init(t_game *game)
{
	int		fd;
	char	*line;

	fd = open(game->map, O_RDONLY);
	if (fd == -1)
		putstr_exit("failed to open map\n", 1);
	game->map_lst = ft_lstnew(get_next_line(fd));
	ft_printf("%s", game->map_lst->str);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		ft_printf("%s", line);
		ft_lstadd_back(&game->map_lst, ft_lstnew(line));
		free(line);
	}
	ft_printf("\n");
	if (close(fd) == -1)
		ft_putstr_fd("failed to close map\n", 1);
	return (game);
}

t_game	*map_pars(t_game *game)
{
	if (game->argc != 2)
		return (NULL);
	if (!(ft_strnstr(game->map, ".ber", strlen(game->map))))
		putstr_exit("Invalid map not .ber", 1);
	map_init(game);
	ft_printlst(game->map_lst);
	return (game);
}
