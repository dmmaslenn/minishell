/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unssetenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaslenn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/09 18:18:18 by dmaslenn          #+#    #+#             */
/*   Updated: 2017/10/20 14:19:31 by dmaslenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		checkift(char *str)
{
	if (ft_strcmp(str, "OLDPWD") == 0)
		return (1);
	else if (ft_strcmp(str, "_") == 0)
		return (1);
	else
		return (0);
}

int		checkifone(char *str)
{
	if (ft_strcmp(str, "TERM_PROGRAM") == 0)
		return (1);
	else if (ft_strcmp(str, "TERM") == 0)
		return (1);
	else if (ft_strcmp(str, "HOME") == 0)
		return (1);
	else if (ft_strcmp(str, "TMPDIR") == 0)
		return (1);
	else if (ft_strcmp(str, "USER") == 0)
		return (1);
	else if (ft_strcmp(str, "XPC_SERVICE_NAME") == 0)
		return (1);
	else if (ft_strcmp(str, "LOGNAME") == 0)
		return (1);
	else if (ft_strcmp(str, "ITERM_SESSION_ID") == 0)
		return (1);
	else if (ft_strcmp(str, "__CF_USER_TEXT_ENCODING") == 0)
		return (1);
	else if (ft_strcmp(str, "SHLVL") == 0)
		return (1);
	else
		return (checkift(str));
}

int		checkifok(char *str)
{
	if (ft_strcmp(str, "TERM_SESSION_ID") == 0)
		return (1);
	else if (ft_strcmp(str, "SSH_AUTH_SOCK") == 0)
		return (1);
	else if (ft_strcmp(str, "Apple_PubSub_Socket_Render") == 0)
		return (1);
	else if (ft_strcmp(str, "COLORFGBG") == 0)
		return (1);
	else if (ft_strcmp(str, "ITERM_PROFILE") == 0)
		return (1);
	else if (ft_strcmp(str, "XPC_FLAGS") == 0)
		return (1);
	else if (ft_strcmp(str, "LANG") == 0)
		return (1);
	else if (ft_strcmp(str, "PWD") == 0)
		return (1);
	else if (ft_strcmp(str, "SHELL") == 0)
		return (1);
	else if (ft_strcmp(str, "TERM_PROGRAM_VERSION") == 0)
		return (1);
	else if (ft_strcmp(str, "PATH") == 0)
		return (1);
	else
		return (checkifone(str));
}

int		unsetone(t_f *strct)
{
	strct->uni = 0;
	while (strct->uni != strct->unh)
	{
		strct->unk[strct->uni] = ft_strdup(strct->env[strct->uni]);
		free(strct->env[strct->uni]);
		strct->uni++;
	}
	free(strct->env[strct->uni]);
	strct->unc = strct->uni;
	strct->uni++;
	while (strct->uni < strct->i - 1)
	{
		strct->unk[strct->unc] = ft_strdup(strct->env[strct->uni]);
		free(strct->env[strct->uni]);
		strct->unc++;
		strct->uni++;
	}
	strct->i--;
	free(strct->env);
	return (0);
}

int		unssetenv(t_f *strct)
{
	if (separator(strct->txt) != 2)
		return (0);
	if (ft_strcmp(strct->text, "unsetenv PATH") == 0)
		lol(strct);
	strct->unh = findenv(strct, 8);
	if (strct->unh == 1000)
		return (0);
	else
	{
		strct->unk = (char **)malloc(sizeof(char *) * strct->i - 1);
		strct->unk[strct->i - 2] = NULL;
		unsetone(strct);
		strct->env = (char **)malloc(sizeof(char *) * strct->i);
		strct->env[strct->i - 1] = NULL;
		strct->uni = 0;
		while (strct->uni < strct->i - 1)
		{
			strct->env[strct->uni] = ft_strdup(strct->unk[strct->uni]);
			free(strct->unk[strct->uni]);
			strct->uni++;
		}
		free(strct->unk);
	}
	return (0);
}
