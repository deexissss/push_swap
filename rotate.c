/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjehaes <tjehaes@student.42luxembourg      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 11:19:51 by tjehaes           #+#    #+#             */
/*   Updated: 2024/06/05 08:22:48 by tjehaes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate(t_stack *stack)
{
	t_node	*top_nb;
	t_node	*bottom_nb;

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

void	ra(t_stack *stack)
{
	ft_rotate(stack);
	ft_printf("ra\n");
}

void	rb(t_stack *stack)
{
	ft_rotate(stack);
	ft_printf("rb\n");
}

void	rr(t_stack *stacka, t_stack *stackb)
{
	ft_rotate(stacka);
	ft_rotate(stackb);
	ft_printf("rr\n");
}
