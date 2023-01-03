/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_token_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 09:37:12 by minseok2          #+#    #+#             */
/*   Updated: 2023/01/03 21:54:05 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	error_handle(t_data *data)
{
	if (data->syntax_err_flag == SINGLE_QUOTE)
		printf("Syntax Error: single quote");
	else if (data->syntax_err_flag == SINGLE_DQUOTE)
		printf("Syntax Error: single dquote");
	list_clear(&data->token_list, del_s_token);
}

void	make_token_list(t_data *data)
{
	const t_state_fp	state_fp[TOTAL_STATE - 1] = {
		init, branch, making_word, making_pipe,
		making_less, making_dless, making_great, making_dgreat,
		quote_branch, quote_making_word, quote_close,
		dquote_branch, dquote_making_word, dquote_close,
		expand, dquote_expand, clear
	};
	t_state				state;
	t_list				buf_list;
	int					index;

	state = INIT;
	while (state != FINISH)
		state_fp[state](&state, data, &buf_list, &index);
	if (data->syntax_err_flag != NONE)
		error_handle(data);
}
