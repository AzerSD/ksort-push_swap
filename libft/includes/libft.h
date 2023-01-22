/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asioud <asioud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 12:59:15 by asioud            #+#    #+#             */
/*   Updated: 2023/01/22 08:22:00 by asioud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <unistd.h>
# include <stdlib.h>
# include <stdint.h>
# include <stdbool.h>
# include <stdarg.h>
# define BUFFER_SIZE 10000

# if defined(__linux__)
#  define NULL_OUTPUT "(nil)"
# elif defined(__APPLE__)
#  define NULL_OUTPUT "0x0" 
# endif

typedef enum elem
{
	CONTENT,
	INDEX,
}	t_elem;

/**
 * @param content : The data contained in the element. 
 * The void * allows to store any kind of data.
 * @param next : The next element`s address or NULL if it`s the last element.
 */
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

typedef struct s_complex
{
	double	real;
	double	imm;
}	t_complex;

/**
 * return x * x
 * @param x to square
 * @return x squared
*/
int		sqr(int x);

/**
 * return x * x
 * @param x to square
 * @return x squared
*/
double	sqr_d(double x);

/**
 * Square root of a number
 * @param number number to be squared
*/
int		ft_sqrt(int number);

/**
 * Checks if c is a space.
 * @param c The character.
 * @return Whether c is a space.
 */
bool	ft_isspace(int32_t c);

/**
 * Checks if c is an alphabetical character.
 * @param c The character.
 * @return Whether c is an alphabetical character.
 */
bool	ft_isalpha(int32_t c);

/**
 * Display and error and exits if yeet = 1
 * @param error_msg The error msg
 * @param yeet if you want to exit or not
*/
void	display_error(char *error_msg, bool yeet);

/**
 * Checks if c is a number.
 * @param c The character.
 * @return Whether c is a number.
 */
bool	ft_isdigit(char c);

/**
 * Checks if string is numeric.
 * @param str the string.
 * @return Whether str is numeric.
*/
bool	ft_isnum(char *str);

/**
 * Checks if string is float
 * @param str the string
 * @return whether it's a float
*/
bool	ft_isfloat(char *str);

/**
 * Checks if c is a alpha numeric character (alphabetic or number)
 * @param c The character.
 * @return Whether c is a alphanumeric character.
 */
bool	ft_isalnum(int32_t c);

/**
 * Checks if c is an ASCII character.
 * @param c The character.
 * @return Whether c is an ASCII character.
 */
bool	ft_isascii(int32_t c);

/**
 * Checks if c is a printable character.
 * @param c The character.
 * @return Whether c is a a printable character.
 */
bool	ft_isprint(int32_t c);

/** 
 * Checks the length of str.
 * @param str A string.
 * @return The length of the string.
 */
size_t	ft_strlen(const char *str);

/**
 * Checks the length of str, ignoring a specified character.
 * @param str A string.
 * @param ignore The character not to be counted. 
 * @return The length of the string.
 */
int		ft_strlen_ignore(const char *str, char ignore);

/** 
 * Fills src up to n with c.
 * @param src Appointed memory to be filled.
 * @param c Byte to fill src with.
 * @param n The amount of bytes the memory is filled with c.
 * @return A pointer to the memory area of src.
 */
void	*ft_memset(void *src, int32_t c, size_t n);

/** 
 * Fills src up to n with null terminators.
 * @param src Appointed memory to be filled.
 * @param n The amount of bytes the memory is filled with null terminators.
 * @return A pointer to the memory area of src.
 */
void	ft_bzero(void *src, size_t n);

/**
 * Copies n bytes from memory area src to memory area dest. 
 * Memory areas may not overlap
 * @param dst Appointed memory to be filled.
 * @param src Memory area to be copied from.
 * @param n The amount of bytes copied from src to dest.
 * @return A pointer to the memory area of dest.
 */
void	*ft_memcpy(void *dst, const void *src, size_t n);

/**
 * Copies n bytes from memory area src to memory area dest. 
 * Memory areas may overlap
 * @param dst Appointed memory to be filled.
 * @param src Memory area to be copied from.
 * @param n The amount of bytes copied from src to dest.
 * @return A pointer to the memory area of dest.
 */
void	*ft_memmove(void *dst, const void *src, size_t n);

/**
 * Copies up to size - 1 characters from the NUL-terminated 
 * string src to dst, NUL-terminating the result. as long as size 
 * is larger than 0. A byte for NUL 
 * should be included in size. Src must be NUL-terminated.
 * @param dest Where src is to be copied to.
 * @param src The string to be copied to dest.
 * @param size How many characters are to be copied.
 * @return The total length of the string it tried to create: 
 * the initial length of dst plus the length of src.
 */
size_t	ft_strlcpy(char *dst, const char *src, size_t size);

/**
 * Appends the NUL-terminated string src to the end of dst. 
 * It will append at most size - strlen(dst) - 1 bytes, 
 * NUL-terminating the result.
 * @param dest The string that is to be appended upon. 
 * @param src The string that is to be appended to dest.
 * @param size How many characters are to be appended to dest.
 * @return The total length of the string it tried to create: the length of src.
 */
size_t	ft_strlcat(char *dst, const char *src, size_t size);

/**
 * Converts lowercase letters to uppercase.
 * @param c Letter to be converted if it is lowercase.
 * @return An uppercase letter.
 */
int32_t	ft_toupper(int32_t c);

/**
 * Converts uppercase letters to lowercase.
 * @param c Letter to be converted if it is uppercase.
 * @return A lowercase letter.
 */
int32_t	ft_tolower(int32_t c);

/**
 * Returns a pointer to the first occurance of c in str.
 * @param str String in which the character will be searched.
 * @param c Character to be searched for in the string.
 * @return A pointer to the first occurance of c in str.
 */
char	*ft_strchr(const char *str, int32_t c);

/**
 * Returns a pointer to the last occurance of c in str.
 * @param str String in which the character will be searched.
 * @param c Character to be searched for in the string.
 * @return A pointer to the last occurance of c in str.
 */
char	*ft_strrchr(const char *str, int32_t c);

/**
 * Compares str1 and str2 and checks whether the length of the strings
 * are the same.
 * @param str1 First string to be compared.
 * @param str2 Second string to be compared.
 * @return < 0 if str1 is less than str2, > 0 if str2 is less than str1, 
 * 0 if they are equal and -1 if the lengths are not the same.
 */
int32_t	ft_strcmp(const char *str1, const char *str2);

/**
 * Compares str1 and str2 up to n bytes.
 * @param str1 First string to be compared.
 * @param str2 Second string to be compared.
* @param n Amount of bytes to be compared.
 * @return < 0 if str1 is less than str2, > 0 if str2 is less than str1, 
 * 0 if they are equal.
 */
int32_t	ft_strncmp(const char *str1, const char *str2, size_t n);

/**
 * Searches for the first occurance of c in ptr up to n. 
 * Checks a memory area instead of just a string 
 * and checks after null terminators.
 * @param ptr Memory area in which the character will be searched.
 * @param content content to be located.
 * @param n Number of bytes to be analyzed.
 * @return A pointer to the first occurance of c in str 
 * or NULL if t he character does not occur.
 */
void	*ft_memchr(const void *ptr, int32_t c, size_t n);

/**
 * Compares str1 and str2 up to n bytes. It differs from strcmp 
 * in that it compares not just strings and it continues 
 * to check after null terminators.
 * @param ptr1 First memory area to be compared.
 * @param ptr2 Second memory area to be compared.
 * @param n Amount of bytes to be compared.
 * @return < 0 if str1 is less than str2, > 0 if str2 is less than str1, 
 * 0 if they are equal.
 */
int32_t	ft_memcmp(const void *ptr1, const void *ptr2, size_t n);

/**
 * Checks if the entirity of the needle occurs in the haystack up to n bytes.
 * @param needle The string that has to be searched for in the haystack
 * @param haystack The string that has to be searched in.
 * @param n Number of bytes to be analyzed.
 * @return A pointer to the first character of the first occurance 
 * of needle in the haystack. NULL if haystack doesn't occur anywhere. 
 * Haystack if needle is empty.
 */
char	*ft_strnstr(const char *haystack, const char *needle, size_t n);

/**
 * Converts a string to integers.
 * @param str The string to be converted.
 * @return The converted content or 0 on error.
 */
int32_t	ft_atoi(const char *str);

/**
 * Converts a string to integers in 64 bit format.
 * @param str The string to be converted.
 * @return The converted content in 64 bits or 0 on error.
 */
int64_t	ft_atoll(const char *str);

/**
 * Converts a string to double
 * @param str The string to be converted
 * @return The converted number
*/
double	ft_atof(const char *str);
/**
 * Allocates memory for an array of num objects of size and 
 * initializes all bytes in the allocated storage to zero.
 * @param num Number of objects.
 * @param size Size of each object.
 * @return If allocation succeeds return a pointer to the first 
 * allocated byte that is suitably aligned for any object type. 
 * On failure, returns a null pointer.
 */
void	*ft_calloc(size_t num, size_t size);

/**
 * Copies str to a new memory location and returns a pointer to that string.
 * @param str The string to be duplicated.
 * @return A pointer to a new memory location with the duplicated string.
 */
char	*ft_strdup(const char *str);

/**
 * Allocates (with malloc(3)) and returns a substring from the string `s`. 
 * The substring begins at index `start` and is of maximum size `len`.
 * @param str The string from which to create the substring.
 * @param start The start index of the substring in the string `s`.
 * @param len The maximum length of the substring.
 * @return The substring. NULL if the allocation fails.
 */
char	*ft_substr(char const *str, uint32_t start, size_t len);

/**
 * Allocates (with malloc(3)) and returns a new string, 
 * which is the result of the concatenation of `s1` and `s2`.
 * @param str1 The prefix string.
 * @param str2 The suffix string.
 * @return The new string. NULL if the allocation fails.
 */
char	*ft_strjoin(char const *str1, char const *str2);

/**
 * Allocates (with malloc(3)) and returns a new string, 
 * which is the result of the concatenation of `s1` and `s2`.
 * But frees str1!
 * @param str1 The prefix string.
 * @param str2 The suffix string.
 * @return The new string. NULL if the allocation fails.
 */
char	*ft_strjoin_str1(char *str1, char *str2);

/**
 * Allocates (with malloc(3)) and returns a new string, 
 * which is the result of the concatenation of `s1` and `s2`.
 * But frees str2!
 * @param str1 The prefix string.
 * @param str2 The suffix string.
 * @return The new string. NULL if the allocation fails.
 */
char	*ft_strjoin_str2(char *str1, char *str2);

/**
 * Allocates (with malloc(3)) and returns a new string, 
 * which is the result of the concatenation of `s1` and `s2`.
 * But frees both strings!
 * @param str1 The prefix string.
 * @param str2 The suffix string.
 * @return The new string. NULL if the allocation fails.
 */
char	*ft_strjoin_free(char *str1, char *str2);

/**
 * Allocates (with malloc(3)) and returns a copy of `s1` 
 * with the characters specified in `set` removed from the beginning 
 * and the end of the string.
 * @param str1 The string to be trimmed.
 * @param set The reference set of characters to trim.
 * @return The trimmed string. NULL if the allocation fails.
 */
char	*ft_strtrim(char const *str, char const *set);

/**
 * Allocates (with malloc(3)) and returns an array of strings 
 * obtained by splitting `s` using the character `c` as a delimiter. 
 * The array must be ended by a NULL pointer.
 * @param str The string to be split.
 * @param c The delimiter character.
 * @return The array of new strings resulting from the split. 
 * NULL if the allocation fails.
 */
char	**ft_split(char const *str, char del);

/**
 * Allocates (with malloc(3)) and returns a string representing 
 * the integer received as an argument. Negative numbers must be handled.
 * @param n the integer to convert.
 * @return The string representing the integer. NULL if the allocation fails.
 */
char	*ft_itoa(int32_t n);

/**
 * Applies the function `f` to each character of the string `s` 
 * to create a new string (with malloc(3)) resulting from 
 * successive applications of `f`.
 * @param str The string on which to iterate.
 * @param f The function to apply to each character.
 * @return The string created from the successive applications 
 * of `f`. Returns NULL if the allocation fails.
 */
char	*ft_strmapi(char const *str, char (*f)(uint32_t, char));

/**
 * Applies the function f to each character of the string 
 * passed as argument, and passing its index as first argument. 
 * Each character is passed by address to f to be modified if necessary
 * @param str The string on which to iterate.
 * @param f The function to apply to each character.
 * @return None.
 */
void	ft_striteri(char *str, void (*f)(uint32_t, char*));

/**
 * Outputs the character `c` to the given file descriptor.
 * @param str The character to output.
 * @param f The file descriptor on which to write.
 * @return How much it has written. *(custom libft)
 */
int32_t	ft_putchar_fd(char c, int32_t fd);

/**
 * Outputs the string `s` to the given file descriptor.
 * @param str The string to output.
 * @param fd The file descriptor on which to write.
 * @return How much it has written. *(custom libft)
 */
int32_t	ft_putstr_fd(char *str, int32_t fd);

/**
 * Outputs the string `s` to the given file descriptor, followed by a newline.
 * @param str The string to output.
 * @param fd The file descriptor on which to write.
 * @return None.
 */
void	ft_putendl_fd(char *str, int32_t fd);

/**
 * Outputs the integer `n` to the given file descriptor.
 * @param nbr The integer to output.
 * @param fd The file descriptor on which to write.
 * @return How much it has written *(custom libft)
 */
int32_t	ft_putnbr_fd(int32_t nbr, int32_t fd);

/**
 * Outputs the integer `n` to the given file descriptor.
 * @param nbr The integer to output, only acceptes unsigned integers.
 * @param fd The file descriptor on which to write.
 * @return How much it has written *(custom libft)
 */
int32_t	ft_uputnbr_fd(uint32_t nbr, int32_t fd);

/**
 * Converts the given integer to hex (lowercase) and outputs it to the 
 * given file descriptor. 
 * @param nbr The integer to be converted to hex and outputted
 * @param fd The file descriptor on which to write.
 * @return How much it has written *(custom libft)
 */
int32_t	ft_hex_fd(uint64_t nbr, int32_t fd);

/**
 * Converts the given integer to hex (capital) and outputs it to the 
 * given file descriptor. 
 * @param nbr The integer to be converted to hex and outputted
 * @param fd The file descriptor on which to write.
 * @return How much it has written *(custom libft)
 */
int32_t	ft_uphex_fd(uint32_t nbr, int32_t fd);

/**
 * Will output the address of a pointer in hexidecimal
 * @param ptr The pointer which adress will be outputted
 * @return How much it has written *(custom libft)
 */
int32_t	ft_putmem_fd(size_t *ptr, int32_t fd);

/**
 * Replicates the behaviour of printf, but you can choose the file descriptor.
 * @param fd The file descriptor on which to write.
 * @param str The string to be outputted with % followed by a type descriptor 
 * whenever a variable has to be printed. (ex: "Hiello %s", where %s is a string)
 * cases: %c %s %% %i %d %u %p %x %X
 * @param ... Can receive an unfixed amount of variables.
 * @return int32_t 
 */
int32_t	ft_printf_fd(int32_t fd, const char *str, ...);

/**
 * Counts the words in a string
 * @param str The string
 * @param del The delimiter seperating what will be counted
 * @return The amount of "words" in a string
 */
size_t	ft_wcount(const char *str, char del);

/**
 * Counts the length of an integer
 * @param nbr
 * @return 
 */
size_t	ft_intlen(int32_t nbr);

/**
 * calculates the power of a number
 * @param base
 * @param power
 * @return 
 */
size_t	ft_pow(int64_t base, int32_t power);

/**
 * Resizes memory that has been allocated through malloc or calloc.
 * @param ptr The old pointer to be reallocated.
 * @param size The size of the new allocation.
 * @return A segfault.
 */
void	*ft_realloc(void *ptr, size_t size);

/**
 * Resizes memory that has been allocated through malloc or calloc.
 * But less retarded.
 * @param ptr The old pointer to be reallocated.
 * @param size The size of the new allocation.
 * @param ptr_len The size of the old allocation to prevent segfaults.
 * @return A malloced string of size size with the value of old ptr.
 */
void	*ft_realloc_n(void *ptr, size_t size, size_t ptr_len);

/**
 * Returns absolute content of x
 * @param x
 * @return absolute content of x
 */
int32_t	ft_abs(int32_t x);

/**
 * @brief 
 * 
 * @param lst_size 
 * @return size_t 
 */
size_t	binary_count(size_t lst_size);

/**
 * Finds the last occurance of char in the string 
 * and returns that position.
 */
size_t	pos_char_end(char *str, char n);

/**
 * Finds the first occurance of char in the string 
 * and returns that position.
 */
size_t	pos_char_start(char *str, char n);

// Bonus content:
/**
 * Allocates (with malloc(3)) and returns a new element. 
 * The variable `content` is initialized with the content 
 * of the parameter `content`. The variable `next` is initialized to NULL.
 * @param content The content to create the new element with.
 * @return The new element.
 */
t_list	*ft_lstnew(void *content);

/**
 * Adds the element `new` at the beginning of the list.
 * @param lst The address of the first node in the list. 
 * @param new The address of a pointer to the element to be added to the list.
 * @return None
 */
void	ft_lstadd_front(t_list **lst, t_list *new);

/**
 * Counts the number of elements in a list.
 * @param lst The beginning of the list.
 * @return Length of the list.
 */
int		ft_lstsize(t_list *lst);

/**
 * Counts the number of elements in a list.
 * @param lst The beginning of the list, this can be any list!
 * @return Length of the list.
 */
size_t	lstsize(void *lst);

/**
 * Returns the last element of the list.
 * @param lst The beginning of the list.
 * @return Last element of the list.
 */
t_list	*ft_lstlast(t_list *lst);

/**
 * Adds the element `new` at the end of the list.
 * @param lst The address of a pointer to the first link of a list.
 * @param new The address of a pointer to the element to be added to the list.
 * @return
 */
void	ft_lstadd_back(t_list **lst, t_list *new);

/**
 * Takes as a parameter an element and frees the memory 
 * of the element`s content using the function `del` 
 * given as a parameter and free the element. 
 * The memory of `next` must not be freed.
 * @param lst The element to free.
 * @param del The address of the function used to delete the content.
 * @return None.
 */
void	ft_lstdelone(t_list *lst, void (*del)(void*));

/**
 * Deletes and frees the given element and every successor 
 * of that element, using the function `del` and free(3). 
 * Finally, the pointer to the list must be set to NULL.
 * @param lst The adress of a pointer to an element.
 * @param del The adress of the function 
 * used to delete the content of the element.
 * @return None
 */
void	ft_lstclear(t_list **lst, void (*del)(void*));

/**
 * Iterates the list `lst` and applies the function `f` 
 * to the content of each element.
 * @param lst The adress of a pointer to an element.
 * @param f The adress of the function used to iterate on the list.
 * @return None.
 */
void	ft_lstiter(t_list *lst, void (*f)(void *));

/**
 * Iterates the list `lst` and applies the function `f` 
 * to the content of each element. Creates a new list resulting 
 * of the successive applications of the function `f`. 
 * The `del` function is used to delete the content of an element if needed.
 * @param lst The adress of a pointer to an element.
 * @param f The adress of the function used to iterate on the list.
 * @param del The adress of the function used to 
 * delete the content of an element if needed.
 * @return The new list. NULL if the allocation fails.
 */
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), \
		void (*del)(void *));

/**
 * Iterates through a linked list and prints the content of every node.
 * @param head Pointer to the head of the linked list.
 * @param type Which type has to be printed, 'd' for int or 's' for char *.
 */
void	ft_lstprint_fd(void *head, char type, int32_t fd);

/**
 * Prints a 2d array.
 * @param arr 2D array to be printed.
 */
void	print_2d_fd(char **arr, int32_t fd);

/**
 * @brief Frees a 2D array and guards against multiple frees of the same
 * 2D arrays by initialising the address to NULL, so the if condition
 * won't be true.
 * @param arr Pass the address of your 2D array here. It's a 3D array, 
 * so it can change the address the 2D array is pointing to and retain 
 * that content outside of the scope of this function.
 */
void	free_2d_guard(char ***arr);

/**
 * @param msg Your message to be printed on STDERR, automatically followed
 * by the line number and file name the error occured at
 * @param exit_nbr If -1
 */
void	error_line(char *msg, int32_t line, char *file, int32_t exit_nbr);

/**
 * Frees a 2D array.
 * @param arr The 2D array to be freed
 */
void	free_2d(char **arr);

/**
 * Read Input from the terminal and return line
 * @param line the returned line
 * @return nb of bytes read
*/
int		ft_fgets(char **line);

/**
 * Opens a file with 777 permission and types depend on i
 * @param filename file name
 * @param i type O_WRONLY | O_CREAT | O_APPEND ...
 * @return exit on failure, fd on sucess
*/
int		open_file(char *filename, int i);

/**
 * Gets the count of n in a string.
 * @param str The string.
 * @param n The thing to be counted in uint8_t format.
 * @return Count of n.
 */
size_t	getncount(char *str, uint8_t n);

char	*gnl_substr(char *str, uint32_t start, size_t len);
char	*gnl_strjoin(char *str1, char *str2);
char	*gnl_strchr(const char *str, int32_t c);
char	*gnl_strdup(char *str);
size_t	gnl_strlcpy(char *dst, char *src, size_t size);
int		gnl_strlen(const char *str);
char	*get_next_line(int fd);

/**
 * Sorts an array of integers in ascending order.
 * @param array The array to be sorted.
 * @param n The size of the array.
 * @return None.
*/
void	bubble_sort(int array[], int n);

/**
 * Sorts an array of integers in ascending order.
 * @param array The array to be sorted.
 * @param n The size of the array.
*/
void	selection_sort(int array[], int n);

/**
 * Sorts an array of integers in ascending order.
 * @param array The array to be sorted.
 * @param n The size of the array.
*/
void	insertion_sort(int array[], int n);

/**
 * Sorts an array of integers in ascending order.
 * @param array The array to be sorted.
 * @param n The size of the array.
*/
void	quick_sort(int arr[], int low_index, int high_index);

/**
 * Checks duplicates in an array
 * @param numbers The array to be checked.
 * @param count The size of the array.
 * @return 1 if there's duplicates, else 0.
*/
int		check_duplicates_bf(int *numbers, int count);

/**
 * Checks duplicates in an array
 * @param numbers The array to be checked.
 * @param count The size of the array.
 * @return 1 if there's duplicates, else 0.
*/
int		check_duplicates_ht(int *numbers, int count);

/**
 * Get index of an element in an array
 * @param n The element to be searched.
 * @param nb The array to be searched.
*/
int		index_of(int n, int *arr);

#endif
