/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachebla <yachebla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 23:58:24 by yachebla          #+#    #+#             */
/*   Updated: 2023/11/18 23:58:26 by yachebla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void push_stack(t_stack **stack, int value)
{
	t_stack *new_node;

	new_node = malloc(sizeof(t_stack));
	if (!new_node)
		ft_protect(1);
	new_node->value = value;
	new_node->next = *stack;
}

void print_stack(t_stack *stack)
{
	while (stack)
	{
		printf("%d\n", stack->value);
		stack = stack->next;
	}
}

void swap_stack(t_stack **stack)
{
	int tmp;

	if (*stack && (*stack)->next)
	{
		tmp = (*stack)->value;
		(*stack)->value = (*stack)->next->value;
		(*stack)->next->value = tmp;
	}
}

void bring_index(t_data *data, t_info *info)
{
	int i;
	int j;

	i = 0;
	while (i < data->size_a)
	{
		j = 0;
		while (j < info->len)
		{
			if (data->a[i] == info->array[j])
			{
				data->a[i] = j;
				break ;
			}
			j++;
		}
		i++;
	}
}

void init_info(t_info *info, int len)
{
	info->array = malloc(sizeof(int) * len);
	if (!info->array)
		ft_protect(1);
	info->len = len;
	info->index = 0;
}
 
void init_data(t_data *data, int len)
{
	data->a = malloc(sizeof(int) * len);
	if (!data->a)
		ft_protect(1);
	data->b = malloc(sizeof(int) * len);
	if (!data->b)
		ft_protect(1);
	data->size_a = len;
	data->size_b = 0;
}

void data_to_stack(t_data *data, t_stack **stack)
{
	int i;

	i = 0;
	while (i < data->size_a)
	{
		push_stack(stack, data->a[i]);
		i++;
	}
}

void exit_free(t_data *data, t_info *info)
{
	free(data->a);
	free(data->b);
	free(info->array);
}

// void sort(t_data *data, t_info *info)
// {
// 	int i;
// 	int j;
// 	int tmp;

// 	i = 0;
// 	while (i < info->len)
// 	{
// 		j = i + 1;
// 		while (j < info->len)
// 		{
// 			if (info->array[i] > info->array[j])
// 			{
// 				tmp = info->array[i];
// 				info->array[i] = info->array[j];
// 				info->array[j] = tmp;
// 			}
// 			j++;
// 		}
// 		i++;
// 	}
// }

int check_sort(t_data *data)
{
	int i;

	i = 0;
	while (i < data->size_a - 1)
	{
		if (data->a[i] > data->a[i + 1])
			return (0);
		i++;
	}
	return (1);
}

// void rotate_stack(t_stack **stack)
// {
// 	t_stack *tmp;
// 	t_stack *tmp2;

// 	if (*stack && (*stack)->next)
// 	{
// 		tmp = *stack;
// 		tmp2 = *stack;
// 		while (tmp->next)
// 			tmp = tmp->next;
// 		*stack = (*stack)->next;
// 		tmp->next = tmp2;
// 		tmp2->next = NULL;
// 	}
// void print_stack(int *stack)
// {
// 	int i;

// 	i = 0;
// 	while (stack[i])
// 	{
// 		printf("%d\n", stack[i]);
// 		i++;
// 	}
// }

// // void	pop_stack(int *stack)
// // {
// // 	int i;

// // 	i = 0;
// // 	while (stack[i])
// // 		i++;
// // 	stack[i - 1] = 0;
// // }

// void	swap_stack(int *stack)
// {
// 	int tmp;

// 	tmp = stack[0];
// 	stack[0] = stack[1];
// 	stack[1] = tmp;
// }



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
//   t_stack b;

//   a = NULL;
//   a = malloc(sizeof(t_stack));
//   a->value = 1;
//   a->next = NULL;
//   push_stack(&a, 2);
  if (ac < 2) 
    ft_protect(1);
  parce_args(av, &a);

}