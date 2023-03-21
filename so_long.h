/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlofrano <vlofrano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 16:09:57 by ffrau             #+#    #+#             */
/*   Updated: 2023/03/16 17:24:48 by vlofrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# define IMG_W 50
# define IMG_H 50
# define ESC 53
# define SU 126
# define GIU 125
# define DX 124
# define SX 123
# define W 13
# define A 0
# define S 1
# define D 2
# define UP -1
# define DOWN 1
# define RIGHT 1
# define LEFT -1
# include "../ft_printf/ft_printf.h"
# include "../libft/libft.h"
# include <fcntl.h>
# include <mlx.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

/* ***** struct to store the different images ***** */

typedef struct s_img
{
	char	*player_up;
	char	*player_left;
	char	*player_right;
	char	*player_down;
	char	*boss;
	char	*boss2;
	char	*boss3;
	char	*boss4;
	char	*background;
	int		animation;
}			t_img;

/* ***** struct to create the map and keep track of the contents ***** */

typedef struct s_map
{
	char	**map;
	void	*object;
	int		x;
	int		y;
	int		diamonds;
}			t_map;

/* ***** struct to hand all of my programms data between functions ***** */

typedef struct s_data
{
	void	*mlx;
	void	*win;
	int		size_x;
	int		size_y;
	int		p_x;
	int		p_y;
	int		b_x;
	int		b_y;
	int		counter;
	int		collected;
	t_map	*map;
	t_img	*img;
}			t_data;

char		*get_next_line(int fd);
void		window_size(t_data *data, char **argv);
void		parse_map(char **argv, t_data *data);
void		ft_init(t_data *data, t_map *map);
void		put_background(t_data *data);
void		ft_put_object(t_data *data, char *relative_path);
void		ft_create_map(t_data *data);
void		ft_put_player(t_data *data);
int			my_key_hook(int keycode, t_data *data);
void		move(t_data *data, char pos, int dir);
void		win(t_data *data);
void		check_contents(t_data *data);
int			ft_exit(t_data *data);
void		check_border(t_data *data);
int			animation_boss(t_data *data);
int			countobj(char *s, char obj);
void		ft_put_boss(t_data *data);
void		lose(void);
void		ft_collect(t_data *data);
void		ft_map_error(char *error_msg);

#endif