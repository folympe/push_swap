/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olfhal <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 17:12:40 by olfhal            #+#    #+#             */
/*   Updated: 2026/02/23 17:12:44 by olfhal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_cost(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*node;
	int		size_a;
	int		size_b;

	size_a = get_stack_size(*stack_a);
	size_b = get_stack_size(*stack_b);
	node = *stack_b;
	while (node)
	{
		if (node->pos <= size_b / 2)
			node->cost_b = node->pos;
		else
			node->cost_b = (size_b - node->pos) * -1;
		if (node->target_pos <= size_a / 2)
			node->cost_a = node->target_pos;
		else
			node->cost_a = (size_a - node->target_pos) * -1;
		node = node->next;
	}
}

void	cheapest_move(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*node;
	int		best_cost;
	int		best_cost_a;
	int		best_cost_b;
	int		current_cost;

	node = *stack_b;
	best_cost = INT_MAX;
	best_cost_a = 0;
	best_cost_b = 0;
	while (node)
	{
		current_cost = abs_val(node->cost_a) + abs_val(node->cost_b);
		if (current_cost < best_cost)
		{
			best_cost = current_cost;
			best_cost_a = node->cost_a;
			best_cost_b = node->cost_b;
		}
		node = node->next;
	}
	move(stack_a, stack_b, best_cost_a, best_cost_b);
}
