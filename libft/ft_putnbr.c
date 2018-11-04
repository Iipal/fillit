/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/27 10:24:50 by tmaluh            #+#    #+#             */
/*   Updated: 2018/10/28 17:08:39 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	ft_putnbr(int n)
{
	int		sign;

	sign = 0;
	if (n == -2147483648)
		ft_putstr("-2147483648");
	else if (n == 2147483647)
		ft_putstr("2147483647");
	else
	{
		if (n < 0)
		{
			ft_putchar('-');
			n = -n;
		}
		if (n >= 10)
		{
			ft_putnbr(n / 10);
			ft_putchar(n % 10 + '0');
		}
		if (n < 10)
			ft_putchar(n % 10 + '0');
	}
}