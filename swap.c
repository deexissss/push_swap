/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjehaes <tjehaes@student.42luxembourg      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 11:16:29 by tjehaes           #+#    #+#             */
/*   Updated: 2024/06/04 11:50:50 by tjehaes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(stack *stack)
{
	node	*nb1;
	node	*nb2;

	if (stack -> top == NULL || stack -> top -> next == NULL)
		return ;
	nb1 = stack -> top;
	nb2 = stack -> top -> next;
	nb1 -> next = nb2 -> next;
	nb2 -> next = nb1;
	stack -> top = nb2;
}

void	sa(stack *stack)
{
	ft_swap(stack);
	ft_printf("sa\n");
}

void	sb(stack *stack)
{
	ft_swap(stack);
	ft_printf("sb\n");
}

void	ss(stack *stacka, stack *stackb)
{
	ft_swap(stacka);
	ft_swap(stackb);
	ft_printf("ss\n");
}
