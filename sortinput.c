/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortinput.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaslenn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/05 17:03:18 by dmaslenn          #+#    #+#             */
/*   Updated: 2017/10/20 14:27:59 by dmaslenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			makeruner(t_f *strct)
{
	int i;
	int c;

	i = 0;
	c = 0;
	strct->runer = (char *)malloc(sizeof(char) * (ft_strlen(strct->com)	\
											+ ft_strlen(strct->folfolder) + 1));
	while (c < ft_strlen(strct->folfolder))
	{
		strct->runer[i] = strct->folfolder[c];
		i++;
		c++;
	}
	strct->runer[i] = '/';
	i++;
	c = 0;
	while (c < ft_strlen(strct->com))
	{
		strct->runer[i] = strct->com[c];
		i++;
		c++;
	}
	strct->runer[i] = '\0';
	return (0);
}

int			findcommand(t_f *strct)
{
	pid_t	parent;
	pid_t	kinder;
	int		status;

	makeruner(strct);
	parent = getpid();
	kinder = fork();
	if (kinder == -1)
	{
	}
	else if (kinder > 0)
	{
		waitpid(kinder, &status, 0);
	}
	else
	{
		execve(strct->runer, strct->argv, strct->env);
		_exit(EXIT_FAILURE);
	}
	strct->kk++;
	free(strct->runer);
	free(strct->folfolder);
	kill(kinder, SIGKILL);
	return (status);
}

int			folderone(t_f *strct)
{
	while (strct->path[strct->foli] != ':' && strct->path[strct->foli] != '\0')
	{
		strct->foli++;
		strct->folc++;
	}
	strct->folfolder = (char *)malloc(sizeof(char) * strct->folc + 1);
	strct->folfolder[strct->folc] = '\0';
	strct->foli = strct->folk;
	strct->folc = 0;
	while (strct->path[strct->foli] != ':' && strct->path[strct->foli] != '\0')
	{
		strct->folfolder[strct->folc] = strct->path[strct->foli];
		strct->folc++;
		strct->foli++;
	}
	return (0);
}

int			foldercheck(t_f *strct)
{
	strct->foli = 0;
	strct->folc = 0;
	strct->kk = 0;
	while (strct->path[strct->foli] != '\0')
	{
		strct->folk = strct->foli;
		folderone(strct);
		if (findcommand(strct) == 0)
			return (1);
		strct->folc = 0;
		strct->foli++;
	}
	return (0);
}

int			helpa(t_f *strct)
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
		if (strct->qtxt[strct->aac] == '"')
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
