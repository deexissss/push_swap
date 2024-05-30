/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjehaes <tjehaes@student.42luxembourg      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 12:55:54 by tjehaes           #+#    #+#             */
/*   Updated: 2024/05/21 14:47:53 by tjehaes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(stack *stack)
{
	node	*nb1;
	node	*nb2;

	if (stack -> top == NULL  || stack -> top -> next == NULL)
		return;
	nb1 = stack -> top;
	nb2 = stack -> top -> next;
	nb1 -> next = nb2 -> next;
	nb2 -> next = nb1;
	stack -> top = nb2;
}

void	ft_rotate(stack	*stack)
{
	node	*top_nb;
	node	*bottom_nb;

	if (stack -> top == NULL || stack -> top -> next == NULL)
		return;
	top_nb = stack -> top;
	bottom_nb = stack -> top;
	while (bottom_nb -> next != NULL)
		bottom_nb = bottom_nb -> next;
	stack -> top = top_nb -> next;
	top_nb -> next = NULL;
	bottom_nb -> next = top_nb;
}

void	ft_reverse_rotate(stack *stack)
{
	node	*second_bottom_nb;
	node	*bottom_nb;

	if (stack -> top == NULL || stack -> top -> next == NULL)
		return;
	second_bottom_nb = NULL;
	bottom_nb = stack -> top;
	while (bottom_nb -> next != NULL)
	{
		second_bottom_nb = bottom_nb;
		bottom_nb = bottom_nb -> next;
	}
	second_bottom_nb -> next = NULL;
	bottom_nb -> next = stack -> top;
	stack -> top = bottom_nb;
}

void	ft_push(stack *stack1, stack *stack2)
{
	int	data;

	data = remove(stack1);
	if (data != -1)
		add_node(stack2, data);
}
