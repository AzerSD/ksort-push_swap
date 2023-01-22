/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_duplicates_ht.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asioud <asioud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 00:01:12 by asioud            #+#    #+#             */
/*   Updated: 2023/01/21 08:01:28 by asioud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

typedef struct hash_table
{
	int		size;
	int		*array;
}	t_hash_table;

static t_hash_table	*create_hash_table(int size)
{
	t_hash_table	*ht;

	ht = (t_hash_table *)malloc(sizeof(t_hash_table));
	ht->size = size;
	ht->array = ft_calloc(ht->size, sizeof(int));
	return (ht);
}

// Hash an integer to a table index
static unsigned int	hash(int key, unsigned int size)
{
	return (((unsigned int)key) % size);
}

// Insert a key into a hash table
static void	insert(t_hash_table *ht, int key)
{
	unsigned int	index;

	index = hash(key, ht->size);
	ht->array[index] = key;
}

// Returns true if the key is in the hash table, false otherwise
static int	search(t_hash_table *ht, int key)
{
	unsigned int	index;

	index = hash(key, ht->size);
	if (ht->array[index] == key)
		return (1);
	return (0);
}

int	check_duplicates_ht(int *numbers, int count)
{
	t_hash_table	*ht;
	int				i;

	ht = create_hash_table(count);
	i = 0;
	while (i < count)
	{
		if (search(ht, numbers[i]))
			return (1);
		insert(ht, numbers[i]);
		i++;
	}
	free(ht->array);
	free(ht);
	return (0);
}
