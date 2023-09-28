/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrichard <lrichard@student.42lyon.f>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 20:13:47 by lrichard          #+#    #+#             */
/*   Updated: 2021/10/12 17:43:25 by lrichard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	is_sorted(t_list *list)
{
	while (list)
	{
		if (list->next && \
			*(int *)(list->content) > *(int *)((list->next)->content))
			return (0);
		list = list->next;
	}
	return (1);
}

void	sort3(t_list **a, t_list **instructions, int len)
{
	if (len == 2)
		swap(a, instructions, (void *)1);
	else if (*(int *)((*a)->content) == 0)
	{
		revrotate(a, instructions, (void *)9);
		swap(a, instructions, (void *)1);
	}
	else if (*(int *)((*a)->content) == 1)
	{
		if (*(int *)(((*a)->next)->content) == 0)
			swap(a, instructions, (void *)1);
		else
			revrotate(a, instructions, (void *)9);
	}
	else if (*(int *)((*a)->content) == 2)
	{
		rotate(a, instructions, (void *)6);
		if (!is_sorted(*a))
			swap(a, instructions, (void *)1);
	}
}

void	sort5(t_list **a, t_list **b, t_list **instructions, int len)
{
	int	pushed;

	pushed = 0;
	while (pushed < 2)
	{
		if (*(int *)((*a)->content) == len - 1 || \
			*(int *)((*a)->content) == len - 2)
		{
			pushed++;
			push(a, b, instructions, (void *)5);
		}
		else
			rotate(a, instructions, (void *)6);
	}
	if (!is_sorted(*a))
		sort3(a, instructions, len - 2);
	if (is_sorted(*b))
		swap(b, instructions, (void *)2);
	push(b, a, instructions, (void *)4);
	push(b, a, instructions, (void *)4);
	rotate(a, instructions, (void *)6);
	rotate(a, instructions, (void *)6);
}

void	radix_sort(t_list **a, t_list **b, t_list **instructions, int len)
{
	int	i;
	int	shift;
	int	digits;

	shift = -1;
	digits = 0;
	i = len - 1;
	while (i >> digits)
		digits++;
	while (++shift < digits)
	{
		i = len;
		while (i--)
		{
			if (*(int *)((*a)->content) >> shift & 1)
				rotate(a, instructions, (void *)6);
			else
				push(a, b, instructions, (void *)5);
		}
		while (*b)
			push(b, a, instructions, (void *)4);
	}
}

void	push_swap(t_list **a, t_list **b, t_list **instructions, int len)
{
	if (is_sorted(*a))
		return ;
	if (len < 4)
		sort3(a, instructions, len);
	else if (len < 6)
		sort5(a, b, instructions, len);
	else
		radix_sort(a, b, instructions, len);
	print_ops(*instructions);
}
