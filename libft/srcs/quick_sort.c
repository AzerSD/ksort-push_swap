/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asioud <asioud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 09:22:10 by asioud            #+#    #+#             */
/*   Updated: 2023/01/09 09:28:58 by asioud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

// Function to swap two elements
void	swap_elements(int *x, int *y)
{
	int	temp;

	temp = *x;
	*x = *y;
	*y = temp;
}

// Partition function
int	partition(int arr[], int low_index, int high_index)
{
	int	pivot_element;
	int	i;
	int	j;

	pivot_element = arr[high_index];
	i = (low_index - 1);
	j = low_index;
	while (j <= high_index - 1)
	{
		if (arr[j] <= pivot_element)
		{
			i++;
			swap_elements(&arr[i], &arr[j]);
		}
		j++;
	}
	swap_elements(&arr[i + 1], &arr[high_index]);
	return (i + 1);
}

// quick_sort Function
void	quick_sort(int arr[], int low_index, int high_index)
{
	int	pivot;

	if (low_index < high_index)
	{
		pivot = partition(arr, low_index, high_index);
		quick_sort(arr, low_index, pivot - 1);
		quick_sort(arr, pivot + 1, high_index);
	}
}

// #include <stdio.h>
// // Function to print array
// void	printArray(int arr[], int size)
// {
// 	int	i;

// 	for (i = 0; i < size; i++)
// 		printf("%d ", arr[i]);
// }

// // Main Function
// int	main(void)
// {
// 	int arr[] = {81, 27, 38, 99, 51, 5};
// 	int n = sizeof(arr) / sizeof(arr[0]);
// 	quick_sort(arr, 0, n - 1);
// 	printf("Sorted array: ");
// 	printArray(arr, n);
// 	return (0);
// }