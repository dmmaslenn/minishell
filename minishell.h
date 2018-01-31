/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaslenn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/09 13:09:47 by dmaslenn          #+#    #+#             */
/*   Updated: 2017/10/20 14:58:07 by dmaslenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __MINISHELL_H
# define __MINISHELL_H
# include "libft/libft.h"
# include <sys/types.h>
# include <signal.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct	s_f
{
	int			hp;
	int			hc;
	int			hj;
	int			kk;
	int			sswn;
	int			omi;
	int			omc;
	char		*saver;
	char		*qtxt;
	char		*txt;
	int			aai;
	int			aac;
	int			aah;
	int			sepi;
	int			sepc;
	char		**unk;
	int			unh;
	int			uni;
	int			unc;
	char		*runer;
	int			foli;
	int			folk;
	int			folc;
	char		*folfolder;
	char		*spath;
	int			si;
	int			sp;
	int			oi;
	int			ssi;
	int			mi;
	int			mc;
	char		fa;
	int			fw;
	int			fh;
	int			fk;
	int			freei;
	int			freec;
	int			countli;
	int			countlc;
	int			pi;
	int			pc;
	int			pa;
	int			pb;
	char		**env;
	int			i;
	int			n;
	int			ad;
	char		*path;
	char		*com;
	char		*arg;
	char		**argv;
	int			argvi;
	char		*fullcom;
	char		*echo;
	char		*text;
	char		*new;
	char		*p;
	int			quo;
	int			duo;
}				t_f;

void			count(char **env, t_f *strct);
void			lol(t_f *strct);
void			helpme(t_f *strct);
int				jk(t_f *strct, int fd);
int				workitout(t_f *strct);
int				mainn(t_f *strct, int fd);
int				done(t_f *strct, int fd);
int				checkforsq(t_f *strct);
t_f				*ssettwo(t_f *strct, t_f *str);
t_f				*ssetone(t_f *strct, t_f *str);
int				stre(t_f *strct);
int				checkifok(char *str);
int				cthree(char *text, t_f *strct, int i);
int				checkquo(char *good, int i);
int				checkend(char *txt);
int				checkforend(char *text, int i, t_f *strct);
int				dolecho(t_f *strct);
char			*aaddtexttd(t_f *strct);
char			*dduo(t_f *strct);
int				helpa(t_f *strct);
char			*addtxtt(t_f *strct, char *txt);
int				summarize(t_f *strct, int i, char *txt);
char			*makeit(t_f *strct);
int				checkquo(char *good, int i);
int				countl(char *text, t_f *strct);
char			*makep(t_f *strct);
int				additt(char *path);
int				printpath(char *path);
int				checkemp(char *text);
int				checkford(char *text);
char			*validatestrr(t_f *strct);
int				checkforq(char *text);
char			*quotit(t_f *strct);
char			*freespaces(t_f *strct);
int				validateecho(char *text, t_f *strct);
int				checkifecho(char *text);
int				unssetenv(t_f *strct);
t_f				*separate(t_f *strct, char *text);
char			*validatestr(char *text);
int				doit(t_f *strct);
int				foldercheck(t_f *strct);
int				checkcommand(t_f *strct);
char			**doarg(char *text, t_f *strct);
int				dodo(char *text, t_f *strct);
int				lsit(char **argv);
char			*writeline(char *new, int k);
char			**makeargv(char **fin, char *new, int i);
int				separator(char *good);
char			**changeargv(char *new, t_f *strct);
char			*pathmaker(t_f *strct);
char			*linemaker(char *new, int c);
int				pathshow(char *new);
int				changepath(char *new, t_f *strct);
char			*cut(char *text);
int				echoit(char *text, t_f *strct);
char			**makearg(char **fin, char *new, int i);
char			**changearg(char *new, t_f *strct);
int				checkifcol(char *new);
char			*command(char*new);
int				docommand(char *new);
int				mknv(t_f *strct);
t_f				*ssetenv(t_f *strct);
t_f				*sortout(t_f *strct, char *text);
int				findenv(t_f *strct, int i);
t_f				*setold(int h, t_f *strct);
int				starter(t_f *strct, char *text);
int				letstakestring(t_f *strct, char *text);

#endif
