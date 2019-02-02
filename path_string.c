/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_string.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnishimo <mnishimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 17:54:05 by mnishimo          #+#    #+#             */
/*   Updated: 2019/02/01 18:43:30 by mnishimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	*add_path(char *path, char *name)
{
	char	*ret;
	size_t	len;

	if (path == NULL || name == NULL)
		return (NULL);
	len = ft_strlen(path);
	if ((ret = (char *)malloc(len + ft_strlen(name) + 2)) == NULL)
		return (NULL);
	ft_strcpy(ret, path);
	ret[len] = '/';
	ret[len + 1] = '\0';
	ft_strcat(ret, name);
	return (ret);
}