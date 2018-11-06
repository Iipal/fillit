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

bool		ft_errno_args(int *argc)
{
	(*argc)--;
	if (!*argc || *argc > 1)
		return (false);
	return (true);
}

void		ft_show(t_figure *figure)
{
	size_t	i;

	i = -1;
	ft_putnbr(figure->lines);
	ft_putchar('\n');
	while (++i < figure->lines)
		ft_putendl(figure->tab[i]);
}

int			main(int argc, string *argv)
{
	t_figure	*figure;

	argv++;
	_ERR_NOTIS_MSG(figure = (t_figure*)malloc(sizeof(t_figure)),
						"failure with struct allocation.");
	if (ft_errno_args(&argc) && *argv)
	{
		_ERR_NOTIS_MSG(ft_read_figure(*argv, &figure),
						"failure with file reading.");
		_ERR_NOTIS_MSG(ft_valid_figure(figure),
						"failure figure validating.");
		ft_free_figure(&figure);
	}
	else
		_ERR_MSG("where is file name ?");
	free(figure);
}
