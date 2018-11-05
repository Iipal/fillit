/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errno.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/03 11:59:37 by tmaluh            #+#    #+#             */
/*   Updated: 2018/11/03 11:59:39 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

bool	ft_read_figure(string file_name, t_figure **figure)
{
	string		temp;
	int			fd;
	size_t		nlines;

	nlines = 0;
	fd = open(file_name, O_RDONLY);
	while (ft_gnl(fd, &temp) > 0)
	{
		nlines++;
		ft_strdel(&temp);
	}
	close(fd);
	_ERR_NOTIS(nlines);
	(*figure)->lines = nlines;
	(*figure)->tab = (string*)malloc(sizeof(string) * (*figure)->lines);
	_ERR_NOTIS((*figure)->tab);
	fd = open(file_name, O_RDONLY);
	nlines = -1;
	while (ft_gnl(fd, &temp) > 0 && ++nlines < (*figure)->lines)
	{
		_ERR_NOTIS(ft_strlen(temp) ==
					((nlines + 1) % 5 ? 4 : 0));
		(*figure)->tab[nlines] = ft_strdup(temp);
		ft_strdel(&temp);
	}
	close(fd);
	return (true);
}
