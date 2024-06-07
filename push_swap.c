/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjehaes <tjehaes@student.42luxembourg      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 15:09:25 by tjehaes           #+#    #+#             */
/*   Updated: 2024/06/07 11:34:24 by tjehaes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*int	ft_stacklast(t_stack *stack)
{
	if (stack -> top == NULL)
		return 0;
	t_node *current = stack -> top;
	while (current -> next != NULL)
		current = current -> next;
	return current -> data;
}*/

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		i;
	int		nb;
	t_node		cheap;

	stack_a = malloc(sizeof(t_stack));
	stack_b = malloc(sizeof(t_stack));
	if (!stack_a || !stack_b)
		return (1);
	if (argc <= 1)
		ft_printf("\n");
	init_stack(stack_a);
	init_stack(stack_b);
	i = 1;
	if (argc > 1)
	{
		while (i + 1 <= argc)
		{
			nb = ft_atoi(argv[i]);
			add_node(stack_a, nb);
			i++;
		}
		if (!ft_checksorted(stack_a))
		{
			if (stack_size(stack_a) == 2)
				sa(stack_a);
			else if (stack_size(stack_a) == 3)
				sort_three(stack_a);
			else
				sort_stacks(stack_a, stack_b);
		}
	}
	while (!is_empty(stack_a))
		ft_remove(stack_a);
	while (!is_empty(stack_b))
		ft_remove(stack_b);
	free(stack_a);
	free(stack_b);
	return (0);
}
