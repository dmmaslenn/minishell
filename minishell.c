/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaslenn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/08 13:17:36 by dmaslenn          #+#    #+#             */
/*   Updated: 2017/10/20 14:55:25 by dmaslenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			workitout(t_f *strct)
{
	int		i;

	i = 0;
	validatestrr(strct);
	if (checkifecho(strct->text) == 1)
	{
		validateecho(strct->txt, strct);
	}
	else
	{
		separate(strct, strct->text);
		if (checkcommand(strct) == 0)
			return (0);
		while (i < strct->argvi)
		{
			free(strct->argv[i]);
			i++;
		}
		free(strct->argv);
		free(strct->com);
	}
	free(strct->text);
	return (1);
}

int			checkforsq(t_f *strct)
{
	int		i;

	i = 0;
	while (strct->txt[i] != '\0')
	{
		if (strct->txt[i] == ';')
			return (1);
		i++;
	}
	return (0);
}

int			done(t_f *strct, int fd)
{
	int		p;

	if (jk(strct, fd) == 0)
		return (0);
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
	{
		if (workitout(strct) == 0)
			return (0);
	}
	free(strct->saver);
	return (1);
}

int			main(int argc, char **argv, char **env)
{
	t_f		*strct;
	int		fd;

	strct = (t_f *)malloc(sizeof(t_f) * 1);
	strct->path = NULL;
	count(env, strct);
	strct->ad = 0;
	strct->quo = 0;
	strct->duo = 0;
	strct->text = NULL;
	strct->com = NULL;
	ft_putstr("$> ");
	while (42)
	{
		strct->txt = ft_strnew(1024);
		read(fd, strct->txt, 1024);
		if (mainn(strct, fd) == 0)
			return (0);
		free(strct->txt);
		ft_putstr("$> ");
	}
	return (0);
}

int			doit(t_f *strct)
{
	pid_t	parent;
	pid_t	kinder;
	int		status;

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
		execve(strct->com, strct->argv, strct->env);
		_exit(EXIT_FAILURE);
	}
	kill(kinder, SIGKILL);
	return (status);
}
