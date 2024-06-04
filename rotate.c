/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjehaes <tjehaes@student.42luxembourg      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 11:19:51 by tjehaes           #+#    #+#             */
/*   Updated: 2024/06/04 11:51:07 by tjehaes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate(stack	*stack)
{
	node	*top_nb;
	node	*bottom_nb;

	if (stack -> top == NULL || stack -> top -> next == NULL)
		return ;
	top_nb = stack -> top;
	bottom_nb = stack -> top;
	while (bottom_nb -> next != NULL)
		bottom_nb = bottom_nb -> next;
	stack -> top = top_nb -> next;
	top_nb -> next = NULL;
	bottom_nb -> next = top_nb;
}

void	ra(stack *stack)
{
	ft_rotate(stack);
	ft_printf("ra\n");
}

void	rb(stack *stack)
{
	ft_rotate(stack);
	ft_printf("rb\n");
}

void	rr(stack *stacka, stack *stackb)
{
	ft_rotate(stacka);
	ft_rotate(stackb);
	ft_printf("rr\n");
}
