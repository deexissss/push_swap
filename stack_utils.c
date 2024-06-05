/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjehaes <tjehaes@student.42luxembourg      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 11:49:29 by tjehaes           #+#    #+#             */
/*   Updated: 2024/06/05 09:46:42 by tjehaes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*create_new_node(int data)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	if (!new_node)
	{
		ft_printf("memory allocation failed \n");
		exit(1);
	}
	new_node -> data = data;
	new_node -> next = NULL;
	return (new_node);
}

void	init_stack(t_stack *stack)
{
	stack -> top = NULL;
}

int	is_empty(t_stack *stack)
{
	if (stack -> top == NULL)
		return (1);
	return (0);
}

void	add_node(t_stack *stack, int data)
{
	t_node	*new_node;

	new_node = create_new_node(data);
	if (!is_empty(stack))
		new_node -> next = stack -> top;
	stack -> top = new_node;
}

int	ft_remove(t_stack *stack)
{
	t_node	*temp;
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
