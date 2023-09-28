/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrichard <lrichard@student.42lyon.f>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 17:25:32 by lrichard          #+#    #+#             */
/*   Updated: 2021/10/12 17:41:47 by lrichard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <pushswap.h>

void	push(t_list **from, t_list **to, t_list **instructions, void *action)
{
	t_list	*tmp;

	tmp = *from;
	if ((*from)->next)
		((*from)->next)->previous = (*from)->previous;
	*from = (*from)->next;
	lstadd_front(to, tmp);
	lstadd(instructions, lstnew(action));
}

void	swap(t_list **list, t_list **instructions, void *action)
{
	int	*tmp;

	tmp = (*list)->content;
	(*list)->content = ((*list)->next)->content;
	((*list)->next)->content = tmp;
	lstadd(instructions, lstnew(action));
}

void	rotate(t_list **list, t_list **instructions, void *action)
{
	((*list)->previous)->next = *list;
	*list = (*list)->next;
	((*list)->previous)->next = 0;
	lstadd(instructions, lstnew(action));
}

void	revrotate(t_list **list, t_list **instructions, void *action)
{
	(((*list)->previous)->previous)->next = 0;
	((*list)->previous)->next = *list;
	*list = (*list)->previous;
	lstadd(instructions, lstnew(action));
}

void	print_ops(t_list *instructions)
{
	while (instructions)
	{
		if ((int *)instructions->content == (int *)1)
			prints("sa");
		else if ((int *)instructions->content == (int *)2)
			prints("sb");
		else if ((int *)instructions->content == (int *)4)
			prints("pa");
		else if ((int *)instructions->content == (int *)5)
			prints("pb");
		else if ((int *)instructions->content == (int *)6)
			prints("ra");
		else if ((int *)instructions->content == (int *)9)
			prints("rra");
		printc('\n');
		instructions = instructions->next;
	}
}
