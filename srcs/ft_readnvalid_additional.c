/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readnvalid_additional.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 15:04:54 by tmaluh            #+#    #+#             */
/*   Updated: 2018/11/06 15:04:55 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

void	ft_addch(t_add add)
{
	if (add.j == 0)
		ft_addcheck_first(add.i, add.j, add.n, add.file);
	else if (add.j == 4)
		ft_addcheck_second(add.i, add.j, add.n, add.file);
	else
		ft_addcheck_third(add.i, add.j, add.n, add.file);
}

void	ft_addcheck_first(int i, int j, int *neighbors, t_file *file)
{
	if (i % 5 == 0)
	{
		(file->tab[i][j + 1] == '#') ? ++(*neighbors) : 0;
		(file->tab[i + 1][j] == '#') ? ++(*neighbors) : 0;
	}
	else if (i % 5 == 3)
	{
		(file->tab[i][j + 1] == '#') ? ++(*neighbors) : 0;
		(file->tab[i - 1][j] == '#') ? ++(*neighbors) : 0;
	}
	else
	{
		(file->tab[i][j + 1] == '#') ? ++(*neighbors) : 0;
		(file->tab[i - 1][j] == '#') ? ++(*neighbors) : 0;
		(file->tab[i + 1][j] == '#') ? ++(*neighbors) : 0;
	}
}

void	ft_addcheck_second(int i, int j, int *neighbors, t_file *file)
{
	if (i % 5 == 0)
	{
		(file->tab[i][j - 1] == '#') ? ++(*neighbors) : 0;
		(file->tab[i + 1][j] == '#') ? ++(*neighbors) : 0;
	}
	else if (i % 5 == 3)
	{
		(file->tab[i][j - 1] == '#') ? ++(*neighbors) : 0;
		(file->tab[i - 1][j] == '#') ? ++(*neighbors) : 0;
	}
	else
	{
		(file->tab[i][j - 1] == '#') ? ++(*neighbors) : 0;
		(file->tab[i - 1][j] == '#') ? ++(*neighbors) : 0;
		(file->tab[i + 1][j] == '#') ? ++(*neighbors) : 0;
	}
}

void	ft_addcheck_third(int i, int j, int *neighbors, t_file *file)
{
	if (i % 5 == 0)
	{
		(file->tab[i][j + 1] == '#') ? ++(*neighbors) : 0;
		(file->tab[i][j - 1] == '#') ? ++(*neighbors) : 0;
		(file->tab[i + 1][j] == '#') ? ++(*neighbors) : 0;
	}
	else if (i % 5 == 3)
	{
		(file->tab[i][j + 1] == '#') ? ++(*neighbors) : 0;
		(file->tab[i][j - 1] == '#') ? ++(*neighbors) : 0;
		(file->tab[i - 1][j] == '#') ? ++(*neighbors) : 0;
	}
	else
	{
		(file->tab[i][j + 1] == '#') ? ++(*neighbors) : 0;
		(file->tab[i][j - 1] == '#') ? ++(*neighbors) : 0;
		(file->tab[i - 1][j] == '#') ? ++(*neighbors) : 0;
		(file->tab[i + 1][j] == '#') ? ++(*neighbors) : 0;
	}
}
