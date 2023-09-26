/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executer_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-arpe <mde-arpe@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 23:18:16 by mde-arpe          #+#    #+#             */
/*   Updated: 2023/09/26 17:07:19 by mde-arpe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_command	*fork_free_command_l(t_command_l **command_l, int which)
{
	int			counter;
	t_command	*fork_command;
	t_command_l	*head;

	counter = 0;
	head = *command_l;
	while (*command_l)
	{
		if (counter == which)
		{
			fork_command = (*command_l)->cmd;
			(*command_l)->cmd = NULL;
		}
		(*command_l) = (*command_l)->next;
		counter ++;
	}
	ft_lstclear_cmd_l(&head);
	return (fork_command);
}

static void	clear_child(t_env **env, t_command_l *cmd, char *arg1, char **arg2)
{
	if (env)
		ft_lstclear((t_list **) env, (void (*)(void *)) free_env_var);
	if (cmd)
		ft_lstclear_cmd_l(&cmd);
	if (arg1)
		free(arg1);
	if (arg2)
		free_arr_2((void **) arg2);
	clear_history();
}

void	childs_tasks(t_env **env, t_command_l *cmd)
{
	char	*path;
	char	**argv;
	char	**envi;
	int		status;

	if (handle_redirs(cmd->cmd->redirs))
		(clear_child(env, cmd, NULL, NULL), exit(1));
	status = 1;
	path = find_path(*env, cmd->cmd->args->content, &status);
	if (!path)
		(clear_child(env, cmd, NULL, NULL), exit(status));
	argv = string_l_to_array(cmd->cmd->args);
	if (!argv)
		(clear_child(env, cmd, path, NULL), perror("minishell"), exit(1));
	envi = env_to_array(*env);
	if (!envi)
		(clear_child(env, cmd, path, argv), perror("minishell"), exit(1));
	clear_child(env, cmd, NULL, NULL);
	sig_setter(SIG_DFL);
	execve(path, argv, envi);
	free_arr_2((void **) envi);
	clear_child(NULL, NULL, path, argv);
	perror("minishell");
	exit(127);
}

int	single_cmd(t_command_l *cmd, t_env **env)
{
	int	pid;
	int	stat;

	if (!cmd->cmd->args)
		return (0);
	pid = fork();
	if (pid < 0)
		return (perror("minishell"), 1);
	sig_setter(sig_handler_wait);
	if (pid == 0)
		childs_tasks(env, cmd);
	if (pid > 0)
	{
		wait(&stat);
		sig_setter(sig_handler_interactive);
	}
	if (WIFSIGNALED(stat))
		return (WTERMSIG(stat) | 0x80);
	return (WEXITSTATUS(stat));
}
