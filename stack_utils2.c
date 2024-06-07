/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjehaes <tjehaes@student.42luxembourg      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 10:13:32 by tjehaes           #+#    #+#             */
/*   Updated: 2024/06/07 08:35:20 by tjehaes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_size(t_stack *stack)
{
	int		i;
	t_node	*temp;

	i = 0;
	temp = stack -> top;
	while (temp != NULL)
	{
		temp = temp -> next;
		i++;
	}
	return (i);
}

t_node	*get_last_node(t_stack *stack)
{
	t_node	*last;

	last = stack -> top;
	while (last != NULL && last -> next != NULL)
		last = last -> next;
	return (last);
}

void	add_node(t_stack *stack, int data)
{
	t_node	*new_node;
	t_node	*current;

	new_node = create_new_node(data);
	if (new_node == NULL)
		return ;
	if (is_empty(stack))
		stack -> top = new_node;
	else
	{
		current = stack -> top;
		while (current -> next != NULL)
			current = current -> next;
		current -> next = new_node;
	}
}

void	display_stack(t_stack *stack)
{
	t_node	*temp;

	temp = stack -> top;
	while (temp != NULL)
	{
		ft_printf("%d\n", temp -> data);
		temp = temp -> next;
	}
}

int	find_max(t_stack *stack)
{
	int		max;
	t_node	*current;

	if (stack == NULL)
		return (0);
	max = stack -> top -> data;
	current = stack -> top;
	while (current != NULL)
	{
		if (current -> data > max)
			max = current -> data;
		current = current -> next;
	}
	return (max);
}
