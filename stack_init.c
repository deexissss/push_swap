/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjehaes <tjehaes@student.42luxembourg      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 08:43:42 by tjehaes           #+#    #+#             */
/*   Updated: 2024/06/05 14:38:01 by tjehaes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*get_cheapest(t_stack *stack)
{
	t_node	*current;

	current = stack -> top;
	if (!stack)
		return(NULL);
	while (current)
	{
		if (current -> cheapest)
			return (current);
		current = current -> next;
	}
	return (NULL);
}

void	push_preparation(t_stack *stack, char stack_name)
{
	t_node	*current;
	t_node	*cheap;

	if (!stack || !stack -> top)
		return ;
	current = stack -> top;
	cheap = get_cheapest(stack);
	if (!cheap)
		return ;
	while (current != cheap)
	{
		if (stack_name == 'a')
		{
			if (cheap -> data  < stack_size(stack) / 2)
				ra(stack);
			else
				rra(stack);
		}
		if (stack_name == 'b')
		{
			if (cheap -> data < stack_size(stack) / 2)
				rb(stack);
			else
				rrb(stack);
		}
	}
}
