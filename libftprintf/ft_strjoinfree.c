/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinfree.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnishimo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 10:20:38 by mnishimo          #+#    #+#             */
/*   Updated: 2019/02/18 23:35:23 by mnishimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_strjoinfree(char **s1, char **s2, int i)
{
	char	*ptr;

	if (!s1 && (i == 3 || i == 2) && (s2 != NULL && *s2 != NULL))
		ft_strdel(s2);
	if ((!s2 || !(*s2)) && (i == 3 || i == 1) && (s1 != NULL && *s1 != NULL))
		ft_strdel(s1);
	if (!s1 || !s2 || !(*s2))
		return (NULL);
	if (*s1 == NULL)
		return (*s2);
	if ((ptr = ft_strnew(ft_strlen(*s1) + ft_strlen(*s2) + 1)))
	{
		ft_strcat(ptr, *s1);
		ft_strcat(ptr, *s2);
	}
	if (i == 1 || i == 3)
		ft_strdel(s1);
	if (i == 2 || i == 3)
		ft_strdel(s2);
	return (ptr);
}
