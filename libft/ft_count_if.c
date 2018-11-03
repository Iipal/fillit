/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 10:33:21 by tmaluh            #+#    #+#             */
/*   Updated: 2018/10/29 10:45:48 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int		ft_count_if(char const *str, char const ch)
{
	int		counter;
	int		i;

	i = -1;
	counter = 0;
	if (!str || !ch)
		return (0);
	while (str[++i] != '\0')
		if (str[i] == ch)
			counter++;
	return (counter);
}
