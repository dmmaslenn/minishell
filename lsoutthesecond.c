/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lsoutthesecond.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaslenn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/09 13:21:26 by dmaslenn          #+#    #+#             */
/*   Updated: 2017/09/26 16:05:02 by dmaslenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			pathone(t_f *strct)
{
	if (strct->text[3] == '~' && strct->text[4] != '\0')
	{
		strct->pb = 21;
		strct->pa = 5;
	}
	strct->pi = strct->pa;
	strct->pc = strct->pb;
	while (strct->text[strct->pi] != '\0')
	{
		strct->pi++;
		strct->pc++;
	}
	strct->p = (char *)malloc(sizeof(char) * strct->pc);
	strct->pi = strct->pa;
	strct->pc = strct->pb;
	if (strct->pc == 21)
		additt(strct->p);
	while (strct->text[strct->pi] != '\0')
	{
		strct->p[strct->pc] = strct->text[strct->pi];
		strct->pc++;
		strct->pi++;
	}
	strct->p[strct->pc] = '\0';
	return (0);
}

char		*pathmaker(t_f *strct)
{
	strct->pi = 3;
	strct->pc = 0;
	strct->pa = 3;
	strct->pb = 0;
	if ((ft_strcmp("cd ~", strct->text) == 0) || \
		(ft_strcmp("cd", strct->text) == 0))
		strct->p = ft_strdup("/nfs/2016/d/dmaslenn");
	else if (ft_strcmp("cd -", strct->text) == 0)
	{
		makep(strct);
		printpath(strct->p);
	}
	else
		pathone(strct);
	changepath(strct->p, strct);
	free(strct->p);
	return (0);
}

char		*aaddtexttd(t_f *strct)
{
	strct->aac = 0;
	strct->aai = 0;
	strct->aah = (ft_strlen(strct->text) + ft_strlen(strct->qtxt) + 1);
	strct->echo = ft_strdup(strct->text);
	free(strct->text);
	strct->text = (char *)malloc(sizeof(char) * strct->aah);
	helpa(strct);
	free(strct->qtxt);
	free(strct->echo);
	return (0);
}

char		*dduo(t_f *strct)
{
	int		fd;

	ft_putstr("dquote>");
	while (42)
	{
		fd = 0;
		strct->qtxt = ft_strnew(1024);
		read(fd, strct->qtxt, 1024);
		if (fd == 0)
		{
			if (checkford(strct->qtxt) == 1)
				return (aaddtexttd(strct));
			else
				aaddtexttd(strct);
		}
		else
			return (0);
		ft_putstr("dquote>");
	}
	return (0);
}
