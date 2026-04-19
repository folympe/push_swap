/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olfhal <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 13:19:39 by olfhal            #+#    #+#             */
/*   Updated: 2026/02/23 13:19:45 by olfhal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rev_rotate_both(t_stack **a, t_stack **b, int *cost_a, int *cost_b)
{
	while (*cost_a < 0 && *cost_b < 0)
	{
		(*cost_a)++;
		(*cost_b)++;
		rrr(a, b);
	}
}

void	rotate_double(t_stack **a, t_stack **b, int *cost_a, int *cost_b)
{
	while (*cost_a > 0 && *cost_b > 0)
	{
		rr(a, b);
		(*cost_a)--;
		(*cost_b)--;
	}
	while (*cost_a < 0 && *cost_b < 0)
	{
		rrr(a, b);
		(*cost_a)++;
		(*cost_b)++;
	}
}

void	rotate_a(t_stack **a, int count)
{
	if (count > 0)
	{
		while (count--)
			ra(a);
	}
	else if (count < 0)
	{
		count = -count;
		while (count--)
			rra(a);
	}
}

void	rotate_b(t_stack **b, int count)
{
	if (count > 0)
	{
		while (count--)
			rb(b);
	}
	else if (count < 0)
	{
		count = -count;
		while (count--)
			rrb(b);
	}
}

void	move(t_stack **a, t_stack **b, int cost_a, int cost_b)
{
	if (cost_a < 0 && cost_b < 0)
		rev_rotate_both(a, b, &cost_a, &cost_b);
	else if (cost_a > 0 && cost_b > 0)
		rotate_double(a, b, &cost_a, &cost_b);
	rotate_a(a, cost_a);
	rotate_b(b, cost_b);
	pa(a, b);
}
