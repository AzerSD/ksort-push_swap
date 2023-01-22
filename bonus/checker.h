/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asioud <asioud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 10:16:37 by asioud            #+#    #+#             */
/*   Updated: 2023/01/22 08:03:36 by asioud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <limits.h>

# include "../libft/includes/libft.h"

# define BUFF_SIZE 5
# define RED "\e[0;31m"

typedef struct s_node
{
	int				data;
	struct s_node	*next;
}					t_node;

typedef struct s_stack
{
	t_node			*head;
	int				size;
}					t_stack;

//////////////////////////////  Utils  //////////////////////////

void		get_instructions(t_stack *stack_a, t_stack *stack_b);
void		init_stack(t_stack *stack_a, t_stack *stack_b, int *nb, int c);
int			exec_(t_stack *stack_a, t_stack *stack_b, char *commands);

////////////////////////// INSTRUCTIONS //////////////////////////

int			pop_stack(t_stack *stack);
void		push_stack(t_stack *stack, int data);
void		swap(t_stack *stack);
void		rotate(t_stack *stack);
void		swap_both(t_stack *stack1, t_stack *stack2);
void		reverse_rotate(t_stack *stack);
void		rotate_both(t_stack *stack_a, t_stack *stack_b);
void		push(t_stack *stack1, t_stack *stack2);
void		reverse_rotate_both(t_stack *stack_a, t_stack *stack_b);

void		free_stack(t_stack *stack);
int			is_sorted(t_stack *stack);

////////////////////////// INSTRUCTIONS //////////////////////////

void		check_range(char **s_numbers, int *numbers);
int			check_digits(int argc, char **argv);
int			*arg_parse(int argc, char **argv, int count);

#endif // CHECKER_H