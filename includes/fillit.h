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

typedef struct	s_figure
{
	string	*tab;
	size_t	lines;
}				t_figure;

typedef struct	s_additional
{
	t_figure	*figu;
	int			i;
	int			j;
	int			*n;

}				t_add;

# define BUFF_SIZE	42

# define _ERR_MSG	ft_putendl("error!")
# define _ERR_NOTIS(ex)	if (!(ex)) return (false)
# define _ERR_NOTIS_MSG(ex)	if (!(ex)) { _ERR_MSG; return (false); }
# define _ERR_NOTIS_O(ex, out)	if (!(ex)) return (out)

int				ft_gnl(const int fd, string *line);

bool			ft_errno_args(int *argc);
bool			ft_read_figure(string file_name, t_figure **figure);
bool			ft_free_figure(t_figure **figure);
bool			ft_valid_figure(t_figure *figure);

void			ft_addch(t_add add);
void			ft_addcheck_first(int i, int j,
							int *neighbors, t_figure *figure);
void			ft_addcheck_second(int i, int j,
							int *neighbors, t_figure *figure);
void			ft_addcheck_third(int i, int j,
							int *neighbors, t_figure *figure);

#endif
