/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvan-de- <zvan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 13:40:58 by zvan-de-          #+#    #+#             */
/*   Updated: 2023/06/15 17:16:41 by zvan-de-         ###   ########.fr       */
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
# include	<fcntl.h>
# define WIDTH 1600
# define HEIGHT 1600
# define TILE 96

typedef struct s_game		t_game;
typedef struct s_images		t_images;
typedef struct s_player		t_player;
typedef struct s_enemy		t_enemy;

typedef struct s_game
{
	mlx_t		*mlx;
	int			argc;
	char		*map_path;
	char		**map;
	int			collectables;
	int			collected;
	int			imgs;
	int			end;
	mlx_image_t	*move_count;
	t_node		*map_lst;
	t_images	*img;
	uint32_t	width;
	uint32_t	height;
	t_player	*player;
	t_enemy		*enemy;
}				t_game;

typedef struct s_map
{
	int			x;
	int			y;
	int			collectables;
	int			exit;
	char		**map;
}				t_map;

typedef struct s_player
{
	uint32_t	x;
	uint32_t	y;
	int			move_count;
	mlx_image_t	*img;
}				t_player;

typedef struct s_enemy
{
	uint32_t	x;
	uint32_t	y;
	mlx_image_t	*img[4];
}				t_enemy;

typedef struct s_images
{
	mlx_image_t		*floor;
	mlx_image_t		*wall_t;
	mlx_image_t		*wall_b;
	mlx_image_t		*wall_l;
	mlx_image_t		*wall_r;
	mlx_image_t		*wall_e;
	mlx_image_t		*wall_lbc;
	mlx_image_t		*wall_rbc;
	mlx_image_t		*wall_trc;
	mlx_image_t		*wall_tlc;
	mlx_image_t		*mac_b;
	mlx_image_t		*mac_t;
	mlx_image_t		*mac_l;
	mlx_image_t		*mac_r;
	mlx_image_t		*coll;
	mlx_image_t		*exit;
}				t_images;

typedef struct s_data
{
	int		player;
	int		exit;
	int		x;
	int		y;
}				t_data;

/*CHECKS*********************************/
void			map_valid(t_game *game);
int				map_rec(t_game *game);
int				map_close(t_game *game);
char			*map_entries(t_game *game, char *str);
char			*map_elements(t_game *game);
int				flood_fill(t_game *game);
void			ft_game_end(void *param);

/*PLAYER*******************************/
void			ft_player(t_game *game, t_player *p);
void			ft_moves(mlx_key_data_t keydata, void *param);
void			ft_close(void *param);
void			check_pos(void *param);
void			exit_open(t_game *g);

/*INIT**********************************/
t_game			*map_init(t_game *game);
t_game			*game_init(int argc, char **argv);
t_player		*init_player(void);
t_images		*init_images(void);
t_data			*init_data(void);
t_enemy			*init_enemy(t_game *game);

/*MAP**********************************/
t_game			*map_pars(t_game *game);
t_game			*make_map(t_game *game);
t_game			*fill_map(t_game *game);
void			fill_backgr(t_game *g, t_images *img, uint32_t x, uint32_t y);
void			fill_floor(t_game *g, t_images *img, uint32_t x, uint32_t y);
void			fill_walls(t_game *g, t_images *img, uint32_t x, uint32_t y);
t_game			*fill_elements(t_game *game, t_images *img, int x, int y);

/*IMAGES******************************/
mlx_image_t		*make_image(t_game *game, char *texture_path);
t_game			*load_png(t_game *game);
void			ft_move_count(void *param);

/*MOVES*******************************/
void			move_up(t_game *g, t_player *p);
void			move_down(t_game *g, t_player *p);
void			move_left(t_game *g, t_player *p);
void			move_right(t_game *g, t_player *p);

/*ERRORS******************************/
void			exit_failure(t_game *game, char *error_message);
void			exit_succes(t_game *game);
void			game_free(t_game *game);

/*ENEMY******************************/
int				find_random_empty_spot(t_game *g, int i);
uint32_t		random_num(u_int32_t i);
int				ft_enemy(t_game *game);
void			move_enemy(t_game *g, t_player *p, t_enemy *e);
void			ft_move_enemy_down(t_game *g, t_enemy *e);
void			ft_move_enemy_up(t_game *g, t_enemy *e);
void			ft_move_enemy_left(t_game *g, t_enemy *e);
void			ft_move_enemy_right(t_game *g, t_enemy *e);
void			ft_animations(void *param);

#endif