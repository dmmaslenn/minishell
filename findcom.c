/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   findcom.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaslenn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/04 16:13:37 by dmaslenn          #+#    #+#             */
/*   Updated: 2017/09/20 14:48:04 by dmaslenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char		*cutpath(char *text)
{
	char	*path;
	int		i;
	int		c;

	i = 0;
	while (text[i] != ' ' && text[i] != '\0')
		i++;
	while (text[i] != '/')
		i--;
	path = (char *)malloc(sizeof(char) * i);
	path[i - 1] = '\0';
	c = i;
	i = 0;
	while (i < c)
	{
		path[i] = text[i];
		ft_putchar(path[i]);
		i++;
	}
	return (path);
}

int			stone(t_f *strct, char *text, int i)
{
	if (i == 1)
	{
		strct->si = 5;
		strct->sp = 0;
		strct->spath = ft_strdup(cutpath(text));
	}
	else if (i == 2)
	{
		while (strct->spath[strct->sp] == strct->env[12][strct->si]	\
			&& strct->env[12][strct->si] != '\0')
		{
			strct->sp++;
			strct->si++;
		}
	}
	return (0);
}

int			starter(t_f *strct, char *text)
{
	stone(strct, text, 1);
	while (strct->env[12][strct->si] != '\0')
	{
		if (strct->spath[strct->sp] == strct->env[12][strct->si])
		{
			stone(strct, text, 2);
			if (strct->spath[strct->sp] == '\0' && \
				strct->env[12][strct->si] == ':')
				return (strct->si);
			else if (strct->spath[strct->sp] == '\0' && \
					strct->env[12][strct->si] == '\0')
				return (strct->si);
			else
			{
				strct->sp = 0;
				if (strct->env[12][strct->si] == '\0')
					return (0);
			}
		}
		strct->si++;
	}
	return (0);
}
