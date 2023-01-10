/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_heredoc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 17:19:30 by jincpark          #+#    #+#             */
/*   Updated: 2023/01/10 21:51:43 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parser.h"

void	parse_io_here(t_data *data, t_proc_data *proc_data, t_list *token_list)
{
	t_redir	*redir;
	char	*filename;
	char	*limiter;

	if (is_return_case(data, token_list, E_NONE))
		return ;
	filename = make_temp_file(data);
	limiter = get_limiter(token_list);
	if (get_heredoc_input(filename, limiter) == EXIT_FAILURE)
	{
		clear_and_free_token_list(token_list);
		data->syntax_err_flag = E_SIG_INT;
		return ;
	}
	redir = (t_redir *)ft_calloc(1, sizeof(t_redir));
	redir->type = T_DLESS;
	redir->filename = filename;
	list_append(&proc_data->redir_list, new_node(redir));
	clear_and_free_token_list(token_list);
}
