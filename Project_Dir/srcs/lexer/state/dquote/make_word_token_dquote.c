/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_word_token_dquote.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 22:12:38 by minseok2          #+#    #+#             */
/*   Updated: 2023/01/12 17:35:39 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../includes/lexer.h"

void	make_word_token_dquote(t_state *state, t_asset *asset)
{
	const char	input = asset->line[asset->index];
	t_token		*token;

	if (input == '\0' || ft_isspace(input) || ft_strchr("|<>", input))
	{
		token = (t_token *)ft_calloc(1, sizeof(t_token));
		token->type = T_WORD;
		token->value = join_buf(&asset->buf_list);
		list_clear(&asset->buf_list, free);
		list_init(&asset->buf_list);
		list_append(asset->token_list, new_node(token));
	}
	*state = BRANCH;
}
