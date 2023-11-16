/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachebla <yachebla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 17:46:21 by yachebla          #+#    #+#             */
/*   Updated: 2023/11/16 20:55:36 by yachebla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

void push_stack(int *stack, int value)
{
	int i;

	i = 0;
	while (stack[i])
		i++;
	stack[i] = value;
}

void print_stack(int *stack)
{
	int i;

	i = 0;
	while (stack[i])
	{
		printf("%d\n", stack[i]);
		i++;
	}
}

void	pop_stack(int *stack)
{
	int i;

	i = 0;
	while (stack[i])
		i++;
	stack[i - 1] = 0;
}

void	swap_stack(int *stack)
{
	int tmp;

	tmp = stack[0];
	stack[0] = stack[1];
	stack[1] = tmp;
}



// int	main(int	ac, char **av)
// {
// 	t_stack data;
// 	int i=0;
// 	while (av[i])
// 	{
// 		puts(av[i++]);
// 	}
	
// 	// parssing(&data);
// }
int main(int ac, char **av) 
{
  t_stack a;
  t_stack b;
  if (ac < 2) 
    ft_protect(1);
  parce_args(av);
}