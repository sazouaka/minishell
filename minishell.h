/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sazouaka <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 16:49:32 by sazouaka          #+#    #+#             */
/*   Updated: 2019/10/10 16:50:10 by sazouaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include "libft/libft.h"
# include <stdio.h>
# include <fcntl.h>

# define BUFF_SIZE 32
# define SIZE 100

typedef struct		s_lst
{
	char			*name;
	char			*content;
	struct s_lst	*next;
}					t_lst;
int					get_next_line(const int fd, char **line);
char				**ft_split(char *buff);
t_lst				*ft_env(char **env);
char				**ft_path(t_lst *head);
void				ft_exec(char **paths, char **flag);
// void				ft_printlist(t_lst *list);

#endif
