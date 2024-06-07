/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjehaes <tjehaes@student.42luxembourg      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 10:26:01 by tjehaes           #+#    #+#             */
/*   Updated: 2024/06/07 11:32:35 by tjehaes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_checksorted(t_stack *stack)
{
	t_node	*temp;

	temp = stack -> top;
	while (temp -> next != NULL)
	{
		if (temp -> data > temp -> next -> data)
			return (0);
		temp = temp -> next;
	}
	return (1);
}

int	syntax_error(char *str)
{
	int	i;

	i = 0;
	if (!(str[i] == '+' || str[i] == '-' || str[i] >= '0' && str[i] <= '9'))
		return (1);
	if ((str[i] == '+' || str[i] == '-')
		&& !(str[i + 1] >= '0' && str[i + 1] <= '9'))
		return (1);
	while (str[i] != '\0')
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (1);
		i++;
	}
	return (0);
}

int	duplicate_nb(t_stack *stack, int nb)
{
	t_node	*current;

	current = stack -> top;
	if (!stack)
		return (0);
	while (current != NULL)
	{
		if (current -> data == nb)
			return (1);
		current = current -> next;
	}
	return (0);
}

void	free_stack(t_stack *stack)
{
	t_node	*current;
	t_node	*next_node;

	if (!stack)
		return ;
	current = stack -> top;
	while (current != NULL)
	{
		next_node = current -> next;
		free(current);
		current = next_node;
	}
	free(stack);
}

void	error(t_stack *stack)
{
	free_stack(stack);
	ft_printf("Error\n");
	exit(1);
}
