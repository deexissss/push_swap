/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack2_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjehaes <tjehaes@student.42luxembourg      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 13:39:26 by tjehaes           #+#    #+#             */
/*   Updated: 2024/06/04 15:07:10 by tjehaes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_min(stack *stack)
{
	long	min;
	node	*current;

	min = LONG_MAX;
	current = stack -> top;
	if (stack == NULL)
		return (0);
	while (current != NULL)
	{
		if (current -> data < min)
			min = current -> data;
		current = current -> next;
	}
	return (min);
}

void	set_target_b(stack *stack1, stack *stack2)
{
	node	*current1;
	node	*current2;
	node	*target_node;
	long	best_match_ind;

	while (current2)
	{
		best_match_ind = LONG_MAX;
		current1 = stack1 -> top;
		while (current1)
		{
			if (current1 -> data > current2 -> data
				&& current1 -> data < best_match_ind)
			{
				best_match_ind = current1 -> data;
				target_node = current1;
			}
		}
		if (best_match_ind == LONG_MAX)
			current2 -> target -> data = find_min(stack1);
		else
			current2 -> target = target_node;
		current2 = current2 -> next;
	}
}

void	init_nodes_2(stack *stack1, stack *stack2)
{
	current_index(stack1);
	current_index(stack2);
	set_target_b(stack1, stack2);
}
