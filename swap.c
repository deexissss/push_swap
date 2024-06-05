/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjehaes <tjehaes@student.42luxembourg      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 11:16:29 by tjehaes           #+#    #+#             */
/*   Updated: 2024/06/05 08:27:31 by tjehaes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_stack *stack)
{
	t_node	*nb1;
	t_node	*nb2;

	if (stack -> top == NULL || stack -> top -> next == NULL)
		return ;
	nb1 = stack -> top;
	nb2 = stack -> top -> next;
	nb1 -> next = nb2 -> next;
	nb2 -> next = nb1;
	stack -> top = nb2;
}

void	sa(t_stack *stack)
{
	ft_swap(stack);
	ft_printf("sa\n");
}

void	sb(t_stack *stack)
{
	ft_swap(stack);
	ft_printf("sb\n");
}

void	ss(t_stack *stacka, t_stack *stackb)
{
	ft_swap(stacka);
	ft_swap(stackb);
	ft_printf("ss\n");
}
