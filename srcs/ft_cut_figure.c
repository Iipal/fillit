/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cut_figu.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 16:33:33 by tmaluh            #+#    #+#             */
/*   Updated: 2018/11/07 16:33:35 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

bool	ft_cut_figure(t_figure *figu)
{
	size_t	i;
	//size_t	x;
	//size_t	y;
	size_t	len;
	string	temp;

	i = -1;
	temp = ft_strnew(0);
	while (++i < figu->lines)
	{
		if (!((i + 1) % 5) || ((i + 1) == figu->lines))
		{
			len = i;
			i -= 4;
			while (++i < len)
			{
				printf("%s\n", figu->tab[i]);
			}
			printf("\n\n");
		}
	}
	return (true);
}