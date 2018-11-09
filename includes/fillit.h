/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/03 11:09:00 by tmaluh            #+#    #+#             */
/*   Updated: 2018/11/03 11:09:02 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "../libft/includes/libft.h"
# include <fcntl.h>

enum	e_bool
{
	false = 0,
	true
};

# define _BOOL		typedef enum e_bool		bool
# define _STR		typedef char*			string

_BOOL;
_STR;

typedef struct	s_point
{
	int		x;
	int		y;
}				t_point;

typedef struct	s_figure
{
	t_point		min;
	t_point		max;
	string		*tab;
	int			width;
	int			height;
	char		symb;
}				t_figure;

typedef struct	s_figurelist
{
	t_figure			*curr_fig;
	struct s_figurelist	*next;
}				t_figurelist;

typedef struct	s_file
{
	string	*tab;
	size_t	lines;
}				t_file;

typedef struct	s_additional
{
	t_file		*file;
	int			i;
	int			j;
	int			*n;
}				t_add;

typedef struct	s_map
{
	string		*tab;
	int			size;
}				t_map;

# define BUFF_SIZE	42

# define _ERR_MSG(msg)	ft_putendl(msg)
# define _ERR_NOTIS(ex)	if (!(ex)) return (false)
# define _ERR_NOTIS_MSG(ex, m) if (!(ex)) { _ERR_MSG(m); return (false); }
# define _ERR_NOTIS_O(ex, out)	if (!(ex)) return (out)

t_figurelist	*ft_cut_figure(t_file *file);
t_map			*ft_create_map(int size);

int				ft_gnl(const int fd, string *line);
int				ft_mapsize(t_figurelist *flist);

bool			ft_errno_args(int *argc);
bool			ft_read_file(string file_name, t_file **file);
bool			ft_valid_file(t_file *file);
bool			ft_solve(t_figurelist *fl);

void			ft_addch(t_add add);
void			ft_addcheck_first(int i, int j,
							int *neighbors, t_file *file);
void			ft_addcheck_second(int i, int j,
							int *neighbors, t_file *file);
void			ft_addcheck_third(int i, int j,
							int *neighbors, t_file *file);
void			ft_display_map(t_map *map);
void			ft_free_map(t_map **map);

#endif
