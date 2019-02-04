/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formatting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnishimo <mnishimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/02 19:01:40 by mnishimo          #+#    #+#             */
/*   Updated: 2019/02/04 00:21:40 by mnishimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	get_fmt_name(t_list	*files, t_lsflags *flags, t_fmt *fmt)
{
	struct winsize	w;

	ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
	fmt->row = 1 + fmt->len / (w.ws_col / fmt->name);
	ft_printf("check %i\n", fmt->row);
}

void	get_fmt(t_list	*files, t_lsflags *flags, t_fmt *fmt)
{

}
