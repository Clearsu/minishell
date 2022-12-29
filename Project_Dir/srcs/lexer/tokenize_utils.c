/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 15:43:28 by minseok2          #+#    #+#             */
/*   Updated: 2022/12/29 19:07:54 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
#include "../../includes/lexer1.h"

void	del_token(void *content)
{
	t_token	*token;

	token = content;
	ft_free(token->value);
}

void	create_token(t_list *token_lst, t_list *buffer_lst, t_type type)
{
	t_token	*token;

	token = (t_token *)ft_calloc(1, sizeof(t_token));

	lst_append(token_lst, new_node(&token));
}

void	expand(char **line)
{

}
