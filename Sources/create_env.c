/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wstygg <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/07 12:52:19 by wstygg            #+#    #+#             */
/*   Updated: 2020/06/02 14:54:00 by wstygg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "conf.h"

static void			*splitr(char **split, void *ret)
{
	ft_free_split(split);
	return (ret);
}

static char			*read_content(char *content, int i)
{
	char			*ret;
	char			**split;

	split = ft_strsplit(content);
	if (split[0][strlen(split[0]) - 1] != ':')
	{
		ft_error("Error at [%d] line: %s\n\':\' symbol have to be in the end "
		"of %s!\n", i + 1, content, split[0]);
		return (splitr(split, NULL));
	}
	split[0][strlen(split[0]) - 1] = '\0';
	if (!split[1])
	{
		ft_error("Error at [%d] line: %s\nNo content after \"%s\"!\n", i + 1,
				content, split[0]);
		return (splitr(split, NULL));
	}
	if (ft_split_size(split) > 2)
	{
		ft_error("Error at [%d] line: %s\nThere have to be only one content "
		"after \"%s\"!\n", i + 1, content, split[0]);
		return (splitr(split, NULL));
	}
	ret = ft_strjoin(ft_strjoin(split[0], " = ", 0), split[1], 1);
	return (splitr(split, ret));
}

static int			count_content(char **conf, int i)
{
	int				ret;

	ret = 0;
	while (tab_count(conf[i++]) == 2)
		ret++;
	return (ret);
}

void				create_env(t_task *task, char **conf, int *i)
{
	char			*content;
	char			**split;
	char			**env;
	register int	k;

	split = ft_strsplit(conf[*i]);
	if (ft_split_size(split) != 1 && ft_error("Error at [%d] line: %s\nContent"
					" for env should have 2 tab depth!\n", *i + 1, conf[*i]))
		return (ft_free_split(split));
	k = -1;
	(*i)++;
	env = ft_malloc(sizeof(char*) * (count_content(conf, *i) + 1));
	while (!str_is_empty(conf[*i]) && tab_count(conf[*i]) == 2)
	{
		if ((content = read_content(conf[*i], *i)))
			env[++k] = content;
		(*i)++;
	}
	if (!env[0] && ft_error("Env content not provided!\n"))
		free(env);
	else
		task->env = env;
	(*i)--;
	ft_free_split(split);
}
