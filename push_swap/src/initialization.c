/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olfhal <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 16:10:05 by olfhal            #+#    #+#             */
/*   Updated: 2026/04/10 16:10:10 by olfhal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*init_stack_from_args(int argc, char **argv)
{
	t_stack	*head;
	t_stack	*new_node;
	long	val;
	int		j;

	head = NULL;
	j = 1;
	while (j < argc)
	{
		val = ft_atoi(argv[j]);
		if (val < INT_MIN || val > INT_MAX)
			exit_error(&head, NULL);
		new_node = stack_new((int)val);
		if (!new_node)
			exit_error(&head, NULL);
		if (head == NULL)
			head = new_node;
		else
			stack_add_bottom(&head, new_node);
		j++;
	}
	return (head);
}

static t_stack	*find_max_unindexed(t_stack *lst)
{
	t_stack	*max_node;
	int		max_val;

	max_node = NULL;
	max_val = INT_MIN;
	while (lst)
	{
		if (lst->index == 0 && lst->value >= max_val)
		{
			max_val = lst->value;
			max_node = lst;
		}
		lst = lst->next;
	}
	return (max_node);
}

void	set_indexes(t_stack *stack, int size)
{
	t_stack	*node;
	int		current_index;

	current_index = size - 1;
	while (current_index >= 0)
	{
		node = find_max_unindexed(stack);
		if (!node)
			break ;
		node->index = current_index;
		current_index--;
	}
}

void sorter(t_stack **a, t_stack **b)
{
    int size;
    int pos;

	size = get_stack_size(*a);
    pb(a, b);
    pb(a, b);
    while (get_stack_size(*a) > 3)
    {
        set_indexes(*a, size);
        set_indexes(*b, size);
        get_target_position(a, b);
        get_cost(a, b);
        cheapest_move(a, b);
    }
    if (!is_sorted(*a, 'a'))
    {
        if ((*a)->index > (*a)->next->index)
            sa(*a);
        if (!is_sorted(*a, 'a'))
            rra(a);
        if (!is_sorted(*a, 'a'))
            sa(*a);
    }
    while (*b)
    {
        set_indexes(*a, size);
        set_indexes(*b, size);
        get_target_position(a, b);
        get_cost(a, b);
        cheapest_move(a, b);
    }
    pos = get_lowest_index_position(a);
    while (pos)
    {
        (pos <= get_stack_size(*a) / 2) ? ra(a) : rra(a);
        pos = get_lowest_index_position(a);
    }
}