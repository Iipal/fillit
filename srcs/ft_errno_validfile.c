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

bool	ft_read_figure(string file_name)
{
	string	temp;
	int		fd;
	size_t	nlines;

	nlines = 0;
	g_figure = (t_figure*)ft_memalloc(sizeof(t_figure));
	fd = open(file_name, O_RDONLY);
	while (ft_gnl(fd, &temp))
		nlines++;
	close(fd);
	_ERR_NOTIS(nlines);
	g_figure->lines = nlines;
	g_figure->tab = (string*)ft_memalloc(g_figure->lines);
	_ERR_NOTIS(g_figure->tab);
	fd = open(file_name, O_RDONLY);
	nlines = -1;
	while (ft_gnl(fd, &temp) > 0 && ++nlines < g_figure->lines)
		g_figure->tab[nlines] = temp;
	close(fd);
	return (true);
}

bool	ft_errno_args(int *argc, string *argv)
{
	(*argc)--;
	argv++;
	if (!*argc || *argc > 1)
		return (false);
	_ERR_NOTIS(ft_read_figure(argv[0]));
	return (true);
}
