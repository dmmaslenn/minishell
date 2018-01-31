/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaslenn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/09 13:25:17 by dmaslenn          #+#    #+#             */
/*   Updated: 2017/10/20 14:31:55 by dmaslenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			changepath(char *new, t_f *strct)
{
	char	cwd[1024];

	chdir(new);
	getcwd(cwd, sizeof(cwd));
	free(strct->env[20]);
	strct->env[20] = ft_strnew(ft_strlen("OLD") + ft_strlen(strct->env[6]) + 1);
	ft_strcat(strct->env[20], "OLD");
	ft_strcat(strct->env[20], strct->env[6]);
	free(strct->env[6]);
	strct->env[6] = ft_strnew(ft_strlen("PWD=") + ft_strlen(cwd) + 1);
	ft_strcat(strct->env[6], "PWD=");
	ft_strcat(strct->env[6], cwd);
	return (0);
}

int			checkforq(char *text)
{
	int		i;

	i = 0;
	while (text[i] != '\0')
	{
		if (text[i] == '\'')
			return (1);
		i++;
	}
	return (0);
}

int			checkford(char *text)
{
	int		i;

	i = 0;
	while (text[i] != '\0')
	{
		if (text[i] == '"')
			return (1);
		i++;
	}
	return (0);
}

int			summarize(t_f *strct, int i, char *txt)
{
	if (i == 1)
	{
		strct->echo = ft_strdup(strct->text);
		ft_bzero(strct->text, ft_strlen(strct->text));
	}
	else if (i == 2)
	{
		ft_bzero(strct->echo, ft_strlen(strct->echo));
		ft_bzero(txt, ft_strlen(txt));
	}
	return (ft_strlen(strct->text) + 1);
}

char		*addtxtt(t_f *strct, char *txt)
{
	int		c;
	int		i;

	c = 0;
	i = -1;
	summarize(strct, 1, txt);
	strct->text = (char *)malloc(sizeof(char) * (ft_strlen(txt) \
											+ ft_strlen(strct->echo) + 1));
	while (strct->echo[c] != '\0')
	{
		strct->text[i++] = strct->echo[c];
		c++;
	}
	strct->text[i] = '\n';
	i++;
	c = 0;
	while (c < ft_strlen(txt) - 1)
	{
		strct->text[i] = txt[c];
		i++;
		c++;
	}
	strct->text[i] = '\0';
	summarize(strct, 2, txt);
	return (0);
}
