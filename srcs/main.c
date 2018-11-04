/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/03 11:07:54 by tmaluh            #+#    #+#             */
/*   Updated: 2018/11/03 13:25:04 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

bool		free_figure(t_figure **figure)
{
	size_t	i;

	i = -1;
	_ERR_NOTIS(*figure);
	while (++i < (*figure)->lines)
		free((*figure)->tab[i]);
	free(*figure);
	*figure = NULL;
}

bool		ft_errno_args(int *argc)
{
	(*argc)--;
	if (!*argc || *argc > 1)
		return (false);
	return (true);
}

int		main(int argc, string *argv)
{
	t_figure	*figure;

	argv++;
	_ERR_NOTIS_MSG(figure = (t_figure*)malloc(sizeof(t_figure)))
	if (ft_errno_args(&argc) && *argv)
	{
		_ERR_NOTIS_MSG(ft_read_figure(*argv, &figure));
	}
	else
		_ERR_MSG;
	free_figure(&figure);
}
