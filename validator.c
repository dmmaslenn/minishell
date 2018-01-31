/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaslenn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/12 16:29:57 by dmaslenn          #+#    #+#             */
/*   Updated: 2017/10/20 14:18:19 by dmaslenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			helpd(t_f *strct)
{
	while (strct->aac < ft_strlen(strct->echo))
	{
		strct->text[strct->aai] = strct->echo[strct->aac];
		strct->aai++;
		strct->aac++;
	}
	strct->text[strct->aai] = '\n';
	strct->aai++;
	strct->aac = 0;
	while (strct->aac < ft_strlen(strct->qtxt) - 1)
	{
		if (strct->qtxt[strct->aac] == '\'')
			strct->aac++;
		else
		{
			strct->text[strct->aai] = strct->qtxt[strct->aac];
			strct->aai++;
			strct->aac++;
		}
	}
	strct->text[strct->aai] = '\0';
	return (0);
}

char		*aaddtexttq(t_f *strct)
{
	strct->aac = 0;
	strct->aai = 0;
	strct->aah = (ft_strlen(strct->text) + ft_strlen(strct->qtxt) + 1);
	strct->echo = ft_strdup(strct->text);
	free(strct->text);
	strct->text = (char *)malloc(sizeof(char) * strct->aah);
	helpd(strct);
	free(strct->echo);
	free(strct->qtxt);
	return (0);
}

char		*qquo(t_f *strct)
{
	int		fd;

	ft_putstr("quote>");
	while (42)
	{
		fd = 0;
		strct->qtxt = ft_strnew(1024);
		read(fd, strct->qtxt, 1024);
		if (fd == 0)
		{
			if (checkforq(strct->qtxt) == 1)
				return (aaddtexttq(strct));
			else
				aaddtexttq(strct);
		}
		else
			return (0);
		ft_putstr("quote>");
	}
	return (0);
}

char		*quotstr(t_f *strct)
{
	int		c;

	if (strct->duo == 11)
		dduo(strct);
	else if (strct->quo == 12)
		qquo(strct);
	c = 0;
	if (strct->duo == 21)
		dduo(strct);
	else if (strct->quo == 22)
		qquo(strct);
	else
		return (0);
	return (0);
}

char		*validatestrr(t_f *strct)
{
	strct->freei = 0;
	freespaces(strct);
	quotstr(strct);
	strct->quo = 0;
	strct->duo = 0;
	return (0);
}
