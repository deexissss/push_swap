/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjehaes <tjehaes@student.42luxembourg      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 11:57:12 by tjehaes           #+#    #+#             */
/*   Updated: 2024/06/04 15:04:27 by tjehaes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(stack *stack)
{
	int	nb1;
	int	nb2;
	int	nb3;

	nb1 = stack -> top -> data;
	nb2 = stack -> top -> next -> data;
	nb3 = stack -> top -> next -> next -> data;
	if (is_empty(stack) || stack_size != 3)
		return ;
	if (nb1 > nb2 && nb2 < nb3 && nb1 > nb3)
		ra(stack);
	else if (nb1 > nb2 && nb2 > nb3 && nb1 > nb3)
	{
		sa(stack);
		rra(stack);
	}
	else if (nb1 < nb2 && nb2 > nb3 && nb1 > nb3)
		rra(stack);
	else if (nb1 > nb2 && nb2 < nb3 && nb1 < nb3)
		sa(stack);
	else if (nb1 < nb2 && nb2 > nb3 && nb1 < nb3)
	{
		sa(stack);
		ra(stack);
	}
}
