/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olfhal <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 16:10:53 by olfhal            #+#    #+#             */
/*   Updated: 2026/04/10 16:10:55 by olfhal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*last_node(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
	{
		stack = stack->next;
	}
	return (stack);
}

int	is_sorted(t_stack *stack, char stack_name)
{
	int	val;

	if (stack_name == 'a')
	{
		val = stack->value;
		while (stack->next)
		{
			stack = stack->next;
			if (val > stack->value)
				return (0);
			val = stack->value;
		}
	}
	else if (stack_name == 'b')
	{
		val = last_node(stack)->value;
		while (stack->previous)
		{
			stack = stack->previous;
			if (val > stack->value)
				return (0);
			val = stack->value;
		}
	}
	return (1);
}

static void	push_swap(t_stack **stack_a, t_stack **stack_b, int stack_size)
{
	if (stack_size == 2 && !is_sorted(*stack_a, 'a'))
		sa(*stack_a);
	else if (stack_size == 3)
		tiny_sort(stack_a);
	else if (stack_size > 3 && !is_sorted(*stack_a, 'a'))
		sort(stack_a, stack_b);
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		stack_size;

	if (ac < 2)
		return (0);
	if (!is_correct_input(av))
		exit_error(NULL, NULL);
	stack_b = NULL;
	stack_a = init_stack_from_args(ac, av);
	stack_size = get_stack_size(stack_a);
	set_indexes(stack_a, stack_size);
	push_swap(&stack_a, &stack_b, stack_size);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
