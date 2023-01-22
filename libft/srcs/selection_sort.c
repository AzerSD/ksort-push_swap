/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asioud <asioud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 09:15:34 by asioud            #+#    #+#             */
/*   Updated: 2023/01/21 08:11:59 by asioud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

// Function to swap elements
void	swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

// Selection Sort
void	selection_sort(int array[], int n)
{
	int	i;
	int	j;
	int	min_element;

	i = 0;
	while (i < n - 1)
	{
		min_element = i;
		j = i + 1;
		while (j < n)
		{
			if (array[j] < array[min_element])
				min_element = j;
			j++;
		}
		swap(&array[min_element], &array[i]);
		i++;
	}
}

// #include <stdio.h>  
// // Function to print the elements of an array
// void printArray(int array[], int size) 
// { 
// int i; 
// for (i=0; i < size; i++) 
// printf("%d ", array[i]); 
// }   
// // Main Function
// int main() 
// { 
// int array[] = {15, 10, 99, 53, 36}; 
// int size = sizeof(array)/sizeof(array[0]); 
// selectionSort(array, size); 
// printf("Sorted array: [ "); 
// printArray(array, size); 
// printf(" ]"); 
// return 0; 
// }