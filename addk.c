/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   addk.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaslenn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 14:51:31 by dmaslenn          #+#    #+#             */
/*   Updated: 2017/10/20 15:00:22 by dmaslenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			mainn(t_f *strct, int fd)
{
	if (checkforsq(strct) == 1)
	{
		strct->saver = ft_strdup(strct->txt);
		if (done(strct, fd) == 0)
			return (0);
	}
	else
	{
		if (checkemp(strct->txt) != 0 && fd == 0)
			if (workitout(strct) == 0)
				return (0);
	}
	return (1);
}

void		lol(t_f *strct)
{
	free(strct->path);
	strct->path = ft_strdup("0");
}

void		count(char **env, t_f *strct)
{
	int		c;

	c = 0;
	strct->i = 0;
	while (env[strct->i])
		strct->i++;
	strct->env = (char **)malloc(sizeof(char *) * strct->i + 1);
	strct->env[strct->i] = NULL;
	while (c < strct->i)
	{
		strct->env[c] = ft_strdup(env[c]);
		c++;
	}
	strct->i++;
	strct->path = ft_strsub(strct->env[12], 5, ft_strlen(strct->env[12]) - 5);
}
