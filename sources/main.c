/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrichard <lrichard@student.42lyon.f>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 19:20:43 by lrichard          #+#    #+#             */
/*   Updated: 2021/11/22 16:26:17 by lrichard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <pushswap.h>

void	del(void *content)
{
	(void)content;
}

void	free_all(t_list *a, t_list *b, t_list *instructions, int *inputs)
{
	lstclear(&a, &del);
	lstclear(&b, &del);
	lstclear(&instructions, &del);
	free(inputs);
}

int	error(t_list *a, t_list *b, t_list *instructions, int *inputs)
{
	write(2, "Error\n", 6);
	free_all(a, b, instructions, inputs);
	return (0);
}

int	init_tabs(int **inputs, int **inputs_masked, int ac, char **av)
{
	if (!nmalloc((void **)inputs, sizeof(int) * ac) || \
		!nmalloc((void **)inputs_masked, sizeof(int) * ac) || \
		!get_args(*inputs, ac, av))
	{
		free(*inputs);
		return (0);
	}
	apply_mask(*inputs, *inputs_masked);
	free(*inputs);
	return (1);
}

int	main(int ac, char **av)
{
	int		*inputs;
	int		*inputs_masked;
	t_list	*a;
	t_list	*b;
	t_list	*instructions;

	a = 0;
	b = 0;
	instructions = 0;
	inputs = 0;
	inputs_masked = 0;
	if (ac == 1)
		return (0);
	if (!init_tabs(&inputs, &inputs_masked, ac, av) || \
		!make_list(&a, inputs_masked))
		return (error(a, b, instructions, inputs_masked));
	push_swap(&a, &b, &instructions, ac - 1);
	free_all(a, b, instructions, inputs_masked);
	return (0);
}
