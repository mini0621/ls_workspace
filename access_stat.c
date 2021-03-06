/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   access_stat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnishimo <mnishimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 14:38:20 by mnishimo          #+#    #+#             */
/*   Updated: 2019/02/23 03:08:41 by mnishimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

time_t		get_time(t_list *cur, t_lsflags *flags)
{
	if (flags->u == 'u')
		return (((t_file *)(cur->content))->stat.st_atime);
	return (((t_file *)(cur->content))->stat.st_mtime);
}

char		get_type(mode_t mode)
{
	mode = (mode & S_IFMT);
	if (mode == S_IFDIR)
		return ('d');
	if (mode == S_IFLNK)
		return ('l');
	if (mode == S_IFBLK)
		return ('b');
	if (mode == S_IFCHR)
		return ('c');
	if (mode == S_IFIFO)
		return ('p');
	else
		return ('-');
}

char		get_xattr(mode_t mode, char c)
{
	mode = (mode & 0xfff);
	if ((c == 'u' && !(mode & S_IXUSR) && (mode & S_ISUID))
		|| (c == 'g' && !(mode & S_IXGRP) && (mode & S_ISGID)))
		return ('S');
	if ((c == 'u' && (mode & S_IXUSR) && (mode & S_ISUID))
		|| (c == 'g' && (mode & S_IXGRP) && (mode & S_ISGID)))
		return ('s');
	if (c == 'o' && !(mode & S_IXOTH) && mode & S_ISVTX)
		return ('T');
	if (c == 'o' && (mode & S_IXOTH) && (mode & S_ISVTX))
		return ('t');
	if ((c == 'u' && ((mode & S_IXUSR))) || (c == 'g' && (mode & S_IXGRP))
		|| (c == 'o' && (mode & S_IXOTH)))
		return ('x');
	return ('-');
}

char		get_acl_attr(char *path)
{
	acl_t	acl;

	if (listxattr(path, NULL, 0, XATTR_NOFOLLOW) > 0)
		return ('@');
	else if ((acl = acl_get_link_np(path, ACL_TYPE_EXTENDED)) != NULL)
	{
		acl_free((void *)acl);
		return ('+');
	}
	return (' ');
}
