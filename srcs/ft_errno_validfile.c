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

bool			ft_read_figure(string file_name)
{
	string	temp;
	string	*figure;
	int		fd;
	size_t	nlines;
	size_t	delimiter;

	nlines = 0;
	fd = open(file_name, O_RDONLY);
	while (ft_gnl(fd, &temp))
		nlines++;
	close(fd);
	_ERR_NOTIS(nlines);
	figure = (string*)ft_memalloc(nlines);
	_ERR_NOTIS(figure);
	fd = open(file_name, O_RDONLY);
	nlines = -1;
	while (ft_gnl(fd, &temp))
		figure[++nlines] = temp;
	close(fd);
	return (true);
}

bool			ft_errno_args(int *argc, string *argv)
{
	(*argc)--;
	argv++;
	if (!*argc || *argc > 1)
		return (false);
	_ERR_NOTIS(ft_read_figure(argv[0]));
	return (true);
}
