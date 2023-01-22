/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asioud <asioud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 09:42:15 by asioud            #+#    #+#             */
/*   Updated: 2023/01/22 07:47:36 by asioud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	exec_(t_stack *stack_a, t_stack *stack_b, char *commands)
{
	if (!ft_strcmp(commands, "pa\n"))
		push(stack_a, stack_b);
	else if (!ft_strcmp(commands, "pb\n"))
		push(stack_b, stack_a);
	else if (!ft_strcmp(commands, "sa\n"))
		swap(stack_a);
	else if (!ft_strcmp(commands, "sb\n"))
		swap(stack_b);
	else if (!ft_strcmp(commands, "ss\n"))
		swap_both(stack_a, stack_b);
	else if (!ft_strcmp(commands, "ra\n"))
		rotate(stack_a);
	else if (!ft_strcmp(commands, "rb\n"))
		rotate(stack_b);
	else if (!ft_strcmp(commands, "rr\n"))
		rotate_both(stack_a, stack_b);
	else if (!ft_strcmp(commands, "rra\n"))
		reverse_rotate(stack_a);
	else if (!ft_strcmp(commands, "rrb\n"))
		reverse_rotate(stack_b);
	else if (!ft_strcmp(commands, "rrr\n"))
		reverse_rotate_both(stack_a, stack_b);
	else
		return (0);
	return (1);
}

void	init_stack(t_stack *stack_a, t_stack *stack_b, int *nb, int c)
{
	int	i;

	stack_b->head = NULL;
	stack_a->head = NULL;
	stack_b->size = 0;
	stack_a->size = 0;
	i = c - 1;
	while (i >= 0)
	{
		push_stack(stack_a, nb[i]);
		i--;
	}
}

void	get_instructions(t_stack *stack_a, t_stack *stack_b)
{
	char	*line;

	while (ft_fgets(&line))
	{
		if (ft_strncmp(line, "\n", 1) == 0)
			break ;
		exec_(stack_a, stack_b, line);
		free(line);
		line = NULL;
	}
	free(line);
	if (is_sorted(stack_a))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

int	main(int argc, char **argv)
{
	t_stack	stack_a;
	t_stack	stack_b;
	int		count;
	int		*numbers;

	if (argc == 1)
		display_error(RED "Error", 1);
	count = check_digits(argc, argv);
	numbers = arg_parse(argc, argv, count);
	if (count <= 1 || check_duplicates_bf(numbers, count))
	{
		free(numbers);
		if (count == 1)
			display_error("Error", 1);
		display_error(RED "Error", 1);
	}
	init_stack(&stack_a, &stack_b, numbers, count);
	get_instructions(&stack_a, &stack_b);
	free(numbers);
	free_stack(&stack_a);
	return (0);
}
