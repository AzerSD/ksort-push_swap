/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asioud <asioud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 05:57:33 by asioud            #+#    #+#             */
/*   Updated: 2023/01/22 08:03:56 by asioud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>

# include "../libft/includes/libft.h"

# define RED "\e[0;31m"
# define YEL "\e[0;33m"

typedef struct s_node
{
	int				data;
	int				s_index;
	struct s_node	*next;
}					t_node;

typedef struct s_stack
{
	t_node			*head;
	int				size;
}					t_stack;

////////////////////////// PARSING //////////////////////////

int			*arg_parse(int argc, char **argv, int length);
int			check_digits(int argc, char **argv);
void		check_range(char **s_numbers, int *numbers);

////////////////////////// struct utils //////////////////////////

void		init_stack(t_stack *stack_a, t_stack *stack_b, int *nb, int c);
void		push_stack(t_stack *stack, int index, int data);
int			pop_stack(t_stack *stack);

////////////////////////// INSTRUCTIONS //////////////////////////

void		reverse_rotate_both(t_stack *stack_a, t_stack *stack_b);
void		push(t_stack *stack1, t_stack *stack2, char x, bool b);
void		rotate_both(t_stack *stack_a, t_stack *stack_b);
void		reverse_rotate(t_stack *stack, char x, bool b);
void		swap_both(t_stack *stack1, t_stack *stack2);
void		rotate(t_stack *stack, char x, bool b);
void		swap(t_stack *stack, char x, bool b);

////////////////////////// Sorting //////////////////////////////

void		sort(t_stack *stack_a, t_stack *stack_b, int *numbers, int length);
void		s_insertion_sort(t_stack *stack_a, t_stack *stack_b, int i);
void		k_sort1(t_stack *stack_a, t_stack *stack_b, int length);
void		k_sort2(t_stack *stack_a, t_stack *stack_b, int length);
void		simple_sort(t_stack *stack, int length);
int			is_sorted(t_stack *stack);

////////////////////////// Utils ///////////////////////////////

int			count_r(t_node *stack, int index);
int			get_min_index(t_stack *stack);
void		free_stack(t_stack *stack);

#endif // PUSH_SWAP_H