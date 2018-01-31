/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaslenn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/04 13:01:46 by dmaslenn          #+#    #+#             */
/*   Updated: 2017/10/20 14:13:07 by dmaslenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_f			*ssettwo(t_f *strct, t_f *str)
{
	str->i = strct->i + 1;
	str->env[strct->i] = NULL;
	while (strct->ssi < strct->i - 2)
	{
		str->env[strct->ssi] = ft_strdup(strct->env[strct->ssi]);
		free(strct->env[strct->ssi]);
		strct->ssi++;
	}
	free(strct->env[strct->ssi]);
	free(strct->env);
	return (0);
}

t_f			*ssetone(t_f *strct, t_f *str)
{
	strct->env[str->i - 1] = NULL;
	strct->i++;
	strct->ssi = 0;
	while (strct->ssi < str->i - 1)
	{
		strct->env[strct->ssi] = ft_strdup(str->env[strct->ssi]);
		free(str->env[strct->ssi]);
		strct->ssi++;
	}
	free(str);
	free(str->env);
	free(strct->new);
	return (strct);
}

t_f			*ssetenv(t_f *strct)
{
	int		l;

	l = 0;
	if (separator(strct->txt) != 3)
		return (0);
	if (ft_strcmp(strct->argv[1], "PATH") == 0)
	{
		free(strct->path);
		strct->path = ft_strdup(strct->argv[2]);
	}
	strct->mi = 6;
	strct->mc = 0;
	strct->ssi = separator(strct->text);
	strct->sswn = (strct->ssi - 1) / 2;
	strct->ssi = 0;
	while (l < strct->sswn)
	{
		if (findenv(strct, 6) != 1000)
			setold(findenv(strct, 6), strct);
		else
			helpme(strct);
		l++;
	}
	return (strct);
}

t_f			*setone(t_f *strct, t_f *str)
{
	while (strct->oi < strct->i - 1)
	{
		str->env[strct->oi] = ft_strdup(strct->env[strct->oi]);
		free(strct->env[strct->oi]);
		strct->oi++;
	}
	free(strct->env);
	strct->env = (char **)malloc(sizeof(char *) * str->i);
	strct->env[str->i - 1] = NULL;
	strct->oi = 0;
	while (strct->oi < str->i - 1)
	{
		strct->env[strct->oi] = ft_strdup(str->env[strct->oi]);
		free(str->env[strct->oi]);
		strct->oi++;
	}
	free(str->env);
	free(str);
	return (strct);
}

t_f			*setold(int h, t_f *strct)
{
	t_f		*str;

	if (ft_strcmp(strct->argv[1], "PATH") == 0)
	{
		free(strct->path);
		strct->path = ft_strdup(strct->argv[2]);
	}
	strct->oi = 0;
	makeit(strct);
	str = (t_f *)malloc(sizeof(t_f) * 1);
	str->env = (char **)malloc(sizeof(char *) * strct->i);
	str->i = strct->i;
	str->env[strct->i - 1] = NULL;
	while (strct->oi != h)
	{
		str->env[strct->oi] = ft_strdup(strct->env[strct->oi]);
		free(strct->env[strct->oi]);
		strct->oi++;
	}
	free(strct->env[strct->oi]);
	str->env[strct->oi] = ft_strdup(strct->new);
	free(strct->new);
	strct->oi++;
	setone(strct, str);
	return (strct);
}
