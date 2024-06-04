/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjehaes <tjehaes@student.42luxembourg      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 11:24:34 by tjehaes           #+#    #+#             */
/*   Updated: 2024/06/04 11:52:14 by tjehaes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_reverse_rotate(stack *stack)
{
	node	*second_bottom_nb;
	node	*bottom_nb;

	if (stack -> top == NULL || stack -> top -> next == NULL)
		return ;
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

void	rra(stack *stack)
{
	ft_reverse_rotate(stack);
	ft_printf("rra\n");
}

void	rrb(stack *stack)
{
	ft_reverse_rotate(stack);
	ft_printf("rrb\n");
}

void	rrr(stack *stacka, stack *stackb)
{
	ft_reverse_rotate(stacka);
	ft_reverse_rotate(stackb);
	ft_printf("rrr\n");
}
