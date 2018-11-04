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

# define BUFF_SIZE	42

# define _ERR_MSG	ft_putendl("error!")
# define _ERR_NOTIS(exception)			if (!(exception)) return (false)
# define _ERR_NOTIS_MSG(exception)		if (!(exception)) { _ERR_MSG; return (false); }
# define _ERR_NOTIS_O(exception, out)	if (!(exception)) return (out)

int			ft_gnl(const int fd, string *line);

bool		ft_errno_args(int *argc);
bool	ft_read_figure(string file_name, t_figure **figure);

#endif
