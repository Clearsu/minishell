/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 10:29:06 by minseok2          #+#    #+#             */
/*   Updated: 2022/12/28 16:12:46 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
#include "../../includes/lexer1.h"

int	 main(int argc, char **argv, char **envp)
{
	t_data	data;
	char	*line;

	envp_init(&data, envp);
	while (1)
	{
		line = readline("minishell>");
		tokenize(&data.token_lst, &data.envp_lst, line);
		print_token_lst(&data.token_lst);
		lst_clear(&data.token_lst, del_token);
	}
	return (0);
}