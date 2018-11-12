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

static bool	ft_valid_newline(string fn)
{
	int		fd;
	char	buff[10001];
	int		ret;

	fd = open(fn, O_RDONLY);
	while ((ret = read(fd, buff, 10000)) > 0)
		buff[ret] = '\0';
	close(fd);
	if (buff[ft_strlen(buff) - 1] != '\n')
		return (false);
	return (true);
}

static int	ft_lines_counter(string fn)
{
	string	temp;
	int		fd;
	int		lines;

	lines = 0;
	fd = open(fn, O_RDONLY);
	while ((ft_gnl(fd, &temp) > 0) && (++lines > 0))
		ft_strdel(&temp);
	close(fd);
	return (lines);
}

bool		ft_read_file(string file_name, t_file **file)
{
	string		temp;
	int			fd;
	int			nlines;

	_ERR_NOTIS(ft_valid_newline(file_name));
	_ERR_NOTIS(nlines = ft_lines_counter(file_name));
	_ERR_NOTIS(nlines % 5 == 4);
	_ERR_NOTIS(!(nlines > 130 || nlines < 4));
	(*file)->lines = nlines;
	(*file)->tab = (string*)malloc(sizeof(string) * (*file)->lines + 1);
	_ERR_NOTIS((*file)->tab);
	nlines = -1;
	fd = open(file_name, O_RDONLY);
	while (ft_gnl(fd, &temp) > 0)
	{
		_ERR_NOTIS(ft_strlen(temp) == ((++nlines + 1) % 5 ? 4 : 0));
		(*file)->tab[nlines] = ft_strdup(temp);
		ft_strdel(&temp);
	}
	close(fd);
	return (true);
}

bool		ft_valid_each_figure(t_file *file, int i)
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
			if (file->tab[i][j] == '#')
			{
				hashes++;
				ft_addch((t_add){.i = i, .j = j, .n = &n, .file = file});
			}
			++j;
		}
		++i;
	}
	if ((n == 6 || n == 8) && hashes == 4)
		return (true);
	return (false);
}

bool		ft_valid_file(t_file *file)
{
	int		i;

	i = 0;
	while (i < file->lines)
	{
		_ERR_NOTIS(ft_valid_each_figure(file, i));
		i += 5;
	}
	return (true);
}
