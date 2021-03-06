/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hepiment < hepiment@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 15:56:16 by hepiment          #+#    #+#             */
/*   Updated: 2022/06/18 16:43:28 by hepiment         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *find, size_t len)
{
	size_t	count_size;

	count_size = ft_strlen(find);
	if (count_size == 0)
		return ((char *)str);
	while (*str != 0 && count_size <= len)
	{
		if (ft_strncmp(str, find, count_size) == 0)
			return ((char *)str);
		len--;
		str++;
	}
	return (0);
}
