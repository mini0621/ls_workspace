/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   storing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnishimo <mnishimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 22:08:26 by mnishimo          #+#    #+#             */
/*   Updated: 2019/02/26 23:15:43 by mnishimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int				store_dp(char *path, DIR *dirp, t_list **files,
		t_lsflags *flags)
{
	struct dirent	*dp;
	t_list			*last;
	int				len;
	char			*tpath;
	blkcnt_t		blkcnt;

	len = 0;
	blkcnt = 0;
	*files = NULL;
	while ((dp = skip_hid_files(dirp, flags->a)) != NULL
		&& (tpath = add_path(path, dp->d_name)) != NULL)
	{
		if (!(get_newfile(files, &last, tpath, dp->d_name)))
			return (0);
		if (flags->n1 != '1' && flags->l != 'l')
			get_fmt_name(dp->d_name, flags->fmt);
		if (flags->l == 'l')
			blkcnt += fmt_cmp(flags->fmt, &(((t_file *)(last->content))->stat));
		ft_strdel(&tpath);
		len++;
	}
	flags->fmt->len = len;
	flags->fmt->blkcnt = blkcnt;
	flags->fmt->row = flags->fmt->len;
	return (0);
}

t_list			*get_newfile(t_list **files, t_list **last,
		char *path, char *d_name)
{
	t_list	*new;
	t_file	file;

	if (lstat(path, &(file.stat)) || !(file.d_name = ft_strdup(d_name)))
	{
		print_error(NULL, d_name, 'n');
		return (NULL);
	}
	if (!(new = ft_lstnew(&file, sizeof(file))))
	{
		free(file.d_name);
		print_error(NULL, d_name, 'n');
	}
	if (*files == NULL)
		*files = new;
	else
		(*last)->next = new;
	*last = new;
	return (new);
}

struct dirent	*skip_hid_files(DIR *dirp, char a)
{
	struct dirent	*ret;

	if (a == 'a')
		return (readdir(dirp));
	while ((ret = readdir(dirp)) != NULL)
	{
		if (ret->d_name[0] != '.')
			return (ret);
	}
	return (NULL);
}
