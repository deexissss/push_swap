/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjehaes <tjehaes@student.42luxembourg      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 09:56:42 by tjehaes           #+#    #+#             */
/*   Updated: 2024/06/10 13:04:11 by tjehaes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	both_rotate(t_stack *stack1, t_stack *stack2, t_node *cheapest)
{
	t_node	*current1;
	t_node	*current2;

	current1 = stack1 -> top;
	current2 = stack2 -> top;
	while (current2 != cheapest -> target && current1 != cheapest)
		rr(stack1, stack2);
	current_index(stack1);
	current_index(stack2);
}

void	both_reverse_rotate(t_stack *stack1, t_stack *stack2, t_node *cheapest)
{
	t_node	*current1;
	t_node	*current2;

	current1 = stack1 -> top;
	current2 = stack2 -> top;
	while (current2 != cheapest -> target && current1 != cheapest)
		rrr(stack1, stack2);
	current_index(stack1);
	current_index(stack2);
}

void	move_a_to_b(t_stack *stack1, t_stack *stack2)
{
	t_node	*cheapest;

	cheapest = get_cheapest(stack1);
	if (cheapest -> above_median && cheapest -> target -> above_median)
		both_rotate(stack1, stack2, cheapest);
	else if (!(cheapest -> above_median)
		&& !(cheapest -> target -> above_median))
		both_reverse_rotate(stack1, stack2, cheapest);
	push_preparation(stack1, 'a');
	push_preparation(stack2, 'b');
	pb(stack1, stack2);
}

void	move_b_to_a(t_stack *stack1, t_stack *stack2)
{
	push_preparation(stack1, 'a');
	pa(stack2, stack1);
}

void	min_to_top(t_stack *stack)
{
	t_node	*current;

	current = stack -> top;
	while (current && current -> data != get_min(stack))
	{
		if (get_min(stack) > stack_size(stack) / 2)
			ra(stack);
		else
			rra(stack);
		current = stack -> top;
	}
}
