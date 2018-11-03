/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/27 10:33:26 by tmaluh            #+#    #+#             */
/*   Updated: 2018/10/28 17:02:24 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static inline int	ft_slen(int *in, int n)
{
	int		out;

	out = 1;
	if (n < 0)
		*in = 1;
	while (n /= 10)
		out++;
	return (out);
}

char				*ft_itoa(int n)
{
	int		len;
	int		sign;
	char	*out;

	if (!n)
	{
		out = ft_strnew(1);
		out[0] = '0';
		return (out);
	}
	sign = 0;
	len = ft_slen(&sign, n);
	if ((out = ft_strnew(len + sign)) == NULL)
		return (NULL);
	if (sign)
		out[0] = '-';
	while (len--)
	{
		out[len + sign] = (sign ? -(n % 10) : n % 10) + '0';
		n /= 10;
	}
	return (out);
}
