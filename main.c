/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-arpe <mde-arpe@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 18:53:06 by mde-arpe          #+#    #+#             */
/*   Updated: 2023/07/29 23:15:29 by mde-arpe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "minishell.h"

int main() {
	char	*raw;
	t_token_l *tok_list;
	
	while (1) {
		raw = readline("$> ");
		tok_list = lexer(raw);
	}
}
