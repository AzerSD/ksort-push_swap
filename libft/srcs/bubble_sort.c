/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asioud <asioud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 09:01:14 by asioud            #+#    #+#             */
/*   Updated: 2023/01/09 09:07:08 by asioud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

// bubble sort function
void	bubble_sort(int array[], int n)
{
	int	i;
	int	j;

	i = 0;
	while (i < n - 1)
	{
		j = 0;
		while (j < n - i - 1)
		{
			if (array[j] > array[j + 1])
				swap(&array[j], &array[j + 1]);
			j++;
		}
		i++;
	}
}

// # include <stdio.h>
// // Function to print the elements of an array
// void printArray(int array[], int size)
// {
// 	int i;
// 	for (i=0; i < size; i++)
// 		printf("%d ", array[i]);
// }

// // Main Function
// int main()
// {
// 	int array[] = {89, 32, 20, 113, -15};
// 	int size = sizeof(array)/sizeof(array[0]);
// 	bubble_sort(array, size);
// 	printf("Sorted array: [ ");
// 	printArray(array, size);
// 	printf("]");
// 	return (0);
// }