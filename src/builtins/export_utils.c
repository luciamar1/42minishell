/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucia-ma <lucia-ma@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 21:21:06 by lucia-ma          #+#    #+#             */
/*   Updated: 2023/09/09 21:11:46 by lucia-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"
#include "structs.h"
#include "env.h"

void	ft_errors_export(char *content)
{
	write(2, "minishell: ", 11);
	write(2, "export: ", 8);
	write(2, "`", 1);
	write(2, content, ft_strlen(content));
	write(2, "'", 1);
	write(2, ": ", 2);
	write(2, "not a valid identifier\n", 23);
}

void	print_export(t_env *envi)
{
	if (envi->content)
	{
		write(1, "declare -x ", 11);
		if (envi->content->value)
			printf("%s=\"%s\"\n", envi->content->key, envi->content->value);
		else
			printf("%s\n", envi->content->key);
	}
}