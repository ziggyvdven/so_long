/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvan-de- <zvan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 13:40:58 by zvan-de-          #+#    #+#             */
/*   Updated: 2023/05/12 16:38:33 by zvan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef SO_LONG_H
# define SO_LONG_H

# include	"../libs/libft/includes/libft.h"
# include	"../libs/MLX42/include/MLX42/MLX42.h"
# include	<stdio.h>
# include	<stdlib.h>
# include	<stdbool.h>
# include	<limits.h>
# include 	<fcntl.h>
# define 	WIDTH 1500
# define 	HEIGHT 1500

typedef struct s_game	t_game;

typedef struct s_game
{
	mlx_t		*mlx;
	int			argc;
	char		*map;
	uint32_t	move_count;
	uint32_t	width;
	uint32_t	height;
}				t_game;


/*CHECKS*********************************/
void			putstr_exit(char *str, int fd);

/*KEYHOOKS*******************************/
void			ft_keyhooks(mlx_t *mlx, void *param);
void			ft_keyhook(mlx_key_data_t keydata, void *param);
void			ft_scrollhook(double xdelta, double ydelta, void *param);

/*init**********************************/
t_game			*map_pars(t_game *game);
t_game			*game_init(int argc, char **argv);

/*OPERATIONS******************************/

#endif