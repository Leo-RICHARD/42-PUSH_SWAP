/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrichard <lrichard@student.42lyon.f>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 21:39:51 by lrichard          #+#    #+#             */
/*   Updated: 2021/10/12 21:12:12 by lrichard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <pushswap.h>

void	apply_mask(int *inputs, int *inputs_masked)
{
	int	i;
	int	i3;

	i = 0;
	inputs_masked[0] = inputs[0];
	while (++i < inputs[0])
	{
		inputs_masked[i] = 0;
		i3 = 0;
		while (++i3 < inputs[0])
			if (inputs[i] > inputs[i3])
				inputs_masked[i]++;
	}
}

int	make_list(t_list **a, int *inputs)
{
	int		i;
	t_list	*atmp;

	i = 0;
	while (++i < inputs[0])
	{
		lstadd(a, lstnew(&(inputs[i])));
		if (!*a)
			return (0);
	}
	(*a)->previous = lstlast(*a);
	atmp = *a;
	while (atmp->next)
	{
		(atmp->next)->previous = atmp;
		atmp = atmp->next;
	}
	return (1);
}

int	check_duplicates(int *inputs)
{
	int	i;
	int	i3;

	i = 0;
	while (++i < inputs[0])
	{
		i3 = 0;
		while (++i3 < inputs[0])
			if (i != i3 && inputs[i] == inputs[i3])
				return (0);
	}
	return (1);
}

int	get_args(int *inputs, int ac, char **av)
{
	int			i;
	int			i3;
	long int	tmp;

	i = 0;
	while (++i < ac)
	{
		i3 = -1;
		while (av[i][++i3])
		{
			if ((av[i][i3] == '-' || av[i][i3] == '+') && i3 == 0)
				i3++;
			else if (av[i][i3] < 48 || av[i][i3] > 57)
				return (0);
		}
		tmp = atoi_ovf(av[i]);
		if (tmp == 2147483648)
			return (0);
		inputs[i] = (int)tmp;
	}
	inputs[0] = ac;
	return (check_duplicates(inputs));
}
