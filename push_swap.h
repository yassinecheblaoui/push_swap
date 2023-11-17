/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachebla <yachebla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 17:51:45 by yachebla          #+#    #+#             */
/*   Updated: 2023/11/17 18:53:04 by yachebla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <stdbool.h>
# define INT_MIN  -2147483648
# define INT_MAX  2147483647

typedef struct  Stack
{
  int   value;
  struct    Stack *next;
} t_stack;

typedef struct info
{
  int   *array;
  int   len;
} t_info;

typedef struct  t_data
{
  int   *a;
  int   *b;
  int   size_a;
  int   size_b;
} t_data;

void print_stack(t_stack *stack);

char	**ft_split(char const *s, char c);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s1);
long	ft_atoi(const char *str);
void	ft_protect(int x);
void	check_double(char **av);
void	check_sign(char **result);
void check_int(char **str);
int parce_args(char **av, t_stack *a);
void push_stack(t_stack **stack, int value);
#endif