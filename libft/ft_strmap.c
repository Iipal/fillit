/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 17:41:28 by tmaluh            #+#    #+#             */
/*   Updated: 2018/10/28 17:14:54 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char			*src;
	char			*out;
	unsigned int	len;
	unsigned int	i;

	i = -1;
	if (!s)
		return (NULL);
	src = (char*)s;
	len = ft_strlen(s);
	if ((out = ft_strnew(len)) == NULL)
		return (NULL);
	while (s[++i])
		out[i] = f(src[i]);
	return (out);
}
