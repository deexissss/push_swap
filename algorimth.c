/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorimth.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjehaes <tjehaes@student.42luxembourg      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 09:50:58 by tjehaes           #+#    #+#             */
/*   Updated: 2024/05/17 15:39:55 by tjehaes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	display_stack(stack *stack)
{
	node	*temp;

	temp = stack -> top;
	while (temp != NULL)
	{
		ft_printf("%d\n", temp -> data);
		temp = temp -> next;
	}
}
/*
int	main(int argc, char **argv)
{
	stack	*stack1;
	stack	*stack2;
	int		i;
	int		nb;

	stack1 = malloc(sizeof(stack));
	stack2 = malloc(sizeof(stack));
	if (!stack1 || !stack2)
		return (1);
	init_stack(stack1);
	init_stack(stack2);
	i = 1;
	if (argc > 1)
	{
		while (i + 1 <= argc)
		{
			nb = ft_atoi(argv[i]);
			add_node(stack1, nb);
			i++;
		}
		ft_printf("before modification\n");
                display_stack(stack1);
                display_stack(stack2);
		ft_swap(stack1);
		ft_push(stack1, stack2);
		ft_push(stack1, stack2);
		ft_push(stack1, stack2);
		ft_swap(stack2);
	}
	ft_printf("stack a \n");
	display_stack(stack1);
	ft_printf("\nstack b\n");
	display_stack(stack2);
	while (!is_empty(stack1))
		remove(stack1);
	while (!is_empty(stack2))
		remove(stack2);
	free(stack1);
	free(stack2);
	return (0);
}*/
