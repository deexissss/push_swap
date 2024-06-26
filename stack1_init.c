/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack1_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjehaes <tjehaes@student.42luxembourg      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 13:39:12 by tjehaes           #+#    #+#             */
/*   Updated: 2024/06/10 12:53:11 by tjehaes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	current_index(t_stack *stack)
{
	int		i;
	int		median;
	t_node	*current;

	i = 0;
	if (!stack || !stack -> top)
		return ;
	current = stack -> top;
	median = stack_size(stack) / 2;
	while (current)
	{
		current -> index = i;
		if (i <= median)
			current -> above_median = true;
		else
			current -> above_median = false;
		current = current -> next;
		i++;
	}
}

void	set_target_a(t_stack *stack1, t_stack *stack2)
{
	t_node	*current1;
	t_node	*current2;
	t_node	*target_node;
	long	best_match_ind;

	current1 = stack1 -> top;
	while (current1)
	{
		best_match_ind = LONG_MIN;
		current2 = stack2 -> top;
		while (current2)
		{
			if (current2 -> data < current1 -> data
				&& current2 -> data > best_match_ind)
			{
				best_match_ind = current2 -> data;
				target_node = current2;
			}
			current2 = current2 -> next;
		}
		if (best_match_ind == LONG_MIN)
			current1 -> target -> data = get_max(stack2);
		else
			current1 -> target = target_node;
		current1 = current1 -> next;
	}
}

void	cost(t_stack *stack1, t_stack *stack2)
{
	int		len1;
	int		len2;
	t_node	*current;

	len1 = stack_size(stack1);
	len2 = stack_size(stack2);
	current = stack1 -> top;
	while (current)
	{
		current -> push_cost = current -> index;
		if (!(current -> above_median))
			current -> push_cost = len1 - (current -> index);
		if (current -> target -> above_median)
			current -> push_cost += current -> target -> index;
		else
			current -> push_cost += len2 - (current -> target -> index);
		current = current -> next;
	}
}

void	set_cheapest_nb(t_stack *stack)
{
	long	cheapest_val;
	t_node	*cheapest_node;
	t_node	*current;

	current = stack -> top;
	if (!stack || !stack -> top)
		return ;
	cheapest_val = LONG_MAX;
	while (current)
	{
		if (current -> push_cost < cheapest_val)
		{
			cheapest_val = current -> push_cost;
			cheapest_node = current;
		}
		current = current -> next;
	}
	cheapest_node -> cheapest = true;
}

void	init_nodes_1(t_stack *stack1, t_stack *stack2)
{
	current_index(stack1);
	current_index(stack2);
	set_target_a(stack1, stack2);
	cost(stack1, stack2);
	set_cheapest_nb(stack1);
}
