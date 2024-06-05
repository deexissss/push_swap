/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack2_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjehaes <tjehaes@student.42luxembourg      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 13:39:26 by tjehaes           #+#    #+#             */
/*   Updated: 2024/06/05 08:24:59 by tjehaes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_target_b(t_stack *stack1, t_stack *stack2)
{
	t_node	*current1;
	t_node	*current2;
	t_node	*target_node;
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

void	init_nodes_2(t_stack *stack1, t_stack *stack2)
{
	current_index(stack1);
	current_index(stack2);
	set_target_b(stack1, stack2);
}
