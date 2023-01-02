/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 18:44:41 by jincpark          #+#    #+#             */
/*   Updated: 2023/01/02 21:06:59 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTIL_H
# define UTIL_H

void	del_s_token(void **content);
void	del_s_cmd(void **content);
void	del_s_redir(void **content);
void	del_s_proc_data(void **content);

t_list	*sub_token_lst(t_data *data, t_node *first, t_node *last);

#endif
