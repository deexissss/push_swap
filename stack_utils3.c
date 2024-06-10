/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjehaes <tjehaes@student.42luxembourg      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 08:00:12 by tjehaes           #+#    #+#             */
/*   Updated: 2024/06/10 12:51:22 by tjehaes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_stacklast(t_stack *stack)
{
	t_node	*current;

	if (stack -> top == NULL)
		return (0);
	current = stack -> top;
	while (current -> next != NULL)
		current = current -> next;
	return (current -> data);
}

int	get_min(t_stack *stack)
{
	long	min;
	t_node	*current;

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
