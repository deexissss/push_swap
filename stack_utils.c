/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjehaes <tjehaes@student.42luxembourg      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 11:49:29 by tjehaes           #+#    #+#             */
/*   Updated: 2024/06/03 10:37:59 by tjehaes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

node	*create_new_node(int data)
{
	node	*new_node;

	new_node = malloc(sizeof(node));
	if (!new_node)
	{
		ft_printf("memory allocation failed \n");
		exit(1);
	}
	new_node -> data = data;
	new_node -> next = NULL;
	return (new_node);
}

void	init_stack(stack *stack)
{
	stack -> top = NULL;
}

int	is_empty(stack *stack)
{
	if (stack -> top == NULL)
		return (1);
	return (0);
}

void	add_node(stack *stack, int data)
{
	node	*new_node;

	new_node = create_new_node(data);
	if (!is_empty(stack))
		new_node -> next = stack -> top;
	stack -> top = new_node;
}

int	remove(stack *stack)
{
	node	*temp;
	int		top_data;

	if (is_empty(stack))
	{
		ft_printf("Pile vide");
		return (-1);
	}
	temp = stack -> top;
	top_data = temp -> data;
	stack -> top = stack -> top -> next;
	free(temp);
	return (top_data);
}
