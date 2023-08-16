/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucia-ma < lucia-ma@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 21:27:41 by lucia-ma          #+#    #+#             */
/*   Updated: 2023/08/16 21:00:32 by lucia-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

# include "minishell.h"

typedef struct s_env_var
{
	char            *key;
	char            *value; 
}t_env_var;

typedef struct s_env
{
	t_env_var		*content;
	struct s_env    *next;
}t_env;



void	ft_print_env(t_env *envi);
t_env	*ft_create_env_list(char **env);
void	ft_print_array_bi(char **array);
void    ft_env(t_env *envi);
int		ft_echo(char ** argv);
char    *get_pwd(char **env);
int     *ft_pwd(char **env);
int     ft_cd(int argc, char **argv, char **env);
void	free_env_var(t_env_var *env_var);





#endif