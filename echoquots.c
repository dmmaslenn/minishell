/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echoquots.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaslenn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/12 16:32:22 by dmaslenn          #+#    #+#             */
/*   Updated: 2017/09/20 14:36:05 by dmaslenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char		*addtexttd(t_f *strct, char *txt)
{
	int	i;
	int	c;

	c = 0;
	i = summarize(strct, 1, txt);
	strct->text = (char *)malloc(sizeof(char) * (ft_strlen(txt)	\
												+ ft_strlen(strct->echo)));
	ft_strcat(strct->text, strct->echo);
	ft_strcat(strct->text, "\n");
	while (txt[c] != '\0')
	{
		if (txt[c] == '"')
			c++;
		else
		{
			strct->text[i] = txt[c];
			i++;
			c++;
		}
	}
	strct->text[i - 1] = '\0';
	summarize(strct, 2, txt);
	return (0);
}

char		*duo(t_f *strct)
{
	int		fd;
	char	*txt;

	ft_putstr("dquote>");
	while (42)
	{
		fd = 0;
		txt = ft_strnew(1024);
		read(fd, txt, 1024);
		if (fd == 0)
		{
			if (ft_strcmp(txt, "\"") == 0)
				return (0);
			else if (checkford(txt) == 1)
				return (addtexttd(strct, txt));
			else
				addtxtt(strct, txt);
		}
		else
			return (0);
		ft_putstr("dquote>");
	}
	return (0);
}

char		*addtexttq(t_f *strct, char *txt)
{
	int		i;
	int		c;

	c = 0;
	i = summarize(strct, 1, txt);
	strct->text = (char *)malloc(sizeof(char) * (ft_strlen(txt)\
												+ ft_strlen(strct->echo)));
	ft_strcat(strct->text, strct->echo);
	ft_strcat(strct->text, "\n");
	while (txt[c] != '\0')
	{
		if (txt[c] == '\'')
			c++;
		else
		{
			strct->text[i] = txt[c];
			i++;
			c++;
		}
	}
	strct->text[i - 1] = '\0';
	summarize(strct, 2, txt);
	return (0);
}

char		*quo(t_f *strct)
{
	int		fd;
	char	*txt;

	ft_putstr("quote>");
	while (42)
	{
		fd = 0;
		txt = ft_strnew(1024);
		read(fd, txt, 1024);
		if (fd == 0)
		{
			if (ft_strcmp(txt, "'") == 0)
				return (0);
			else if (checkforq(txt) == 1)
				return (addtexttq(strct, txt));
			else
				addtxtt(strct, txt);
		}
		else
			return (0);
		ft_putstr("quote>");
	}
	return (0);
}

char		*quotit(t_f *strct)
{
	int		c;

	if (strct->duo == 11)
	{
		duo(strct);
		ft_putstr(strct->text);
	}
	else if (strct->quo == 12)
	{
		quo(strct);
		ft_putstr(strct->text);
	}
	c = 0;
	if (strct->duo == 21)
	{
		duo(strct);
		ft_putstr(strct->text);
	}
	else if (strct->quo == 22)
	{
		quo(strct);
		ft_putstr(strct->text);
	}
	return (0);
}
