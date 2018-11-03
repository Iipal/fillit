/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 17:41:32 by tmaluh            #+#    #+#             */
/*   Updated: 2018/10/28 17:11:05 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	size_t		n;

	if (*to_find == '\0')
		return ((char*)str);
	n = ft_strlen(to_find);
	while (*str && len-- >= n)
	{
		if (*str && *to_find &&
			!ft_memcmp(str, to_find, n))
			return ((char*)str);
		str++;
	}
	return (NULL);
}
