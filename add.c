/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaslenn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 14:13:34 by dmaslenn          #+#    #+#             */
/*   Updated: 2017/10/20 14:59:40 by dmaslenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			stre(t_f *strct)
{
	if (checkifok(strct->argv[1]) == 1)
	{
		ft_putstr("No such luck:)\n");
		return (0);
	}
	return (1);
}

void		helpme(t_f *strct)
{
	t_f		*str;

	makeit(strct);
	str = (t_f *)malloc(sizeof(t_f) * 1);
	str->env = (char **)malloc(sizeof(char *) * strct->i + 1);
	ssettwo(strct, str);
	str->env[strct->ssi] = ft_strdup(strct->new);
	str->env[strct->ssi + 1] = ft_strdup(strct->env[strct->ssi]);
	strct->env = (char **)malloc(sizeof(char *) * str->i);
	ssetone(strct, str);
}

int			cthree(char *text, t_f *strct, int i)
{
	if (i == 1)
	{
		while (text[strct->countli] == ' ')
			strct->countli++;
		if (strct->countlc != 0)
			strct->countlc++;
	}
	else if (i == 2)
	{
		while (text[strct->countli] == '\t' && text[strct->countli] != '\0')
			strct->countli++;
		if (strct->countlc != 0)
			strct->countlc++;
	}
	else if (i == 3)
	{
		strct->countli++;
		strct->countlc++;
	}
	return (0);
}

int			jkk(t_f *strct, int fd, int i)
{
	free(strct->txt);
	strct->txt = (char *)malloc(sizeof(char) * strct->hc + 1);
	strct->txt[strct->hc] = '\0';
	strct->hc = strct->hp;
	strct->hp = 0;
	while (strct->saver[strct->hc] != ';')
	{
		if (strct->saver[strct->hc] == '\0')
			break ;
		strct->txt[strct->hp] = strct->saver[strct->hc];
		strct->hp++;
		strct->hc++;
	}
	if (checkemp(strct->txt) != 0 && fd == 0)
		if (workitout(strct) == 0)
			return (0);
	strct->hc = 0;
	strct->hp = i + 1;
	return (1);
}

int			jk(t_f *strct, int fd)
{
	int		i;

	i = 0;
	strct->hc = 0;
	while (strct->saver[i] != '\0')
	{
		if (i == 0)
			strct->hp = 0;
		if (strct->saver[i] == ';')
		{
			if (jkk(strct, fd, i) == 0)
				return (0);
		}
		else
			strct->hc++;
		i++;
	}
	return (1);
}
