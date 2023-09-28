/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrichard <lrichard@student.42lyon.f>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 19:18:56 by lrichard          #+#    #+#             */
/*   Updated: 2021/10/08 22:51:08 by lrichard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include <libft.h>

void	del(void *content);
int		get_args(int *inputs, int ac, char **av);
void	apply_mask(int *inputs, int *inputs_masked);
int		make_list(t_list **a, int *inputs);
void	push_swap(t_list **a, t_list **b, t_list **instructions, int len);
void	push(t_list **from, t_list **to, t_list **instructions, void *action);
void	swap(t_list **list, t_list **instructions, void *action);
void	rotate(t_list **list, t_list **instructions, void *action);
void	revrotate(t_list **list, t_list **instructions, void *action);
void	print_ops(t_list *instructions);

#endif
