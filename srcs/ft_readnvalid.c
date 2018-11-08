/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readnvalid.c                                    :+:      :+:    :+:   */
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
		nlines++;
	close(fd);
	_ERR_NOTIS(nlines);
	_ERR_NOTIS(!(nlines > 130 || nlines < 4));
	(*figure)->lines = nlines;
	(*figure)->tab = (string*)malloc(sizeof(string) * (*figure)->lines);
	_ERR_NOTIS((*figure)->tab);
	fd = open(file_name, O_RDONLY);
	nlines = -1;
	while (ft_gnl(fd, &temp) > 0)
	{
		_ERR_NOTIS(ft_strlen(temp) == ((++nlines + 1) % 5 ? 4 : 0));
		(*figure)->tab[nlines] = ft_strdup(temp);
		ft_strdel(&temp);
	}
	close(fd);
	return (true);
}

bool	ft_valid_each_figure(t_figure *figure, int i)
{
	int		i_1;
	int		hashes;
	int		n;
	int		j;

	n = 0;
	hashes = 0;
	i_1 = i + 4;
	while (i < i_1)
	{
		j = 0;
		while (j < 4)
		{
			if (figure->tab[i][j] == '#')
			{
				hashes++;
				ft_addch((t_add){.i = i, .j = j, .n = &n, .figu = figure});
			}
			++j;
		}
		++i;
	}
	if ((n == 6 || n == 8) && hashes == 4)
		return (true);
	return (false);
}

bool	ft_valid_figure(t_figure *figure)
{
	size_t	i;

	i = 0;
	while (i < figure->lines)
	{
		_ERR_NOTIS(ft_valid_each_figure(figure, i));
		i += 5;
	}
	return (true);
}
