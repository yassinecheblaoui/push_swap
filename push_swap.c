/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachebla <yachebla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 17:46:21 by yachebla          #+#    #+#             */
/*   Updated: 2023/06/24 17:54:57 by yachebla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

void push_swap(t_swap *data)
{
	int i;
	int j;
	while (data->a)
	{
		i = 0;
		j = 0;
		while (data->a[i] < data->a[i + 1])
			i++;
		while (data->a[j] > data->a[j + 1])
			j++;
		if (i < j)
		{
			while (i > 0)
			{
				ra(data);
				i--;
			}
		}
		else
		{
			while (j > 0)
			{
				rra(data);
				j--;
			}
		}
		pb(data);
	}
	// while (data->b)
	// 	pa(data);
}
void pb(t_swap *data)
{
	int i;
	int j;
	int tmp;

	i = 0;
	j = 0;
	tmp = data->a[0];
	while (data->a[i])
		i++;
	while (j < i)
	{
		data->a[j] = data->a[j + 1];
		j++;
	}
	data->a[j] = tmp;
	i = 0;
	j = 0;
	while (data->b[i])
		i++;
	while (j < i)
	{
		data->b[j] = data->b[j + 1];
		j++;
	}
	data->b[j] = tmp;
}
void rra(t_swap *data)
{
	int i;
	int j;
	int tmp;

	i = 0;
	j = 0;
	tmp = data->a[0];
	while (data->a[i])
		i++;
	while (j < i)
	{
		data->a[j] = data->a[j + 1];
		j++;
	}
	data->a[j] = tmp;
}
void ra(t_swap *data)
{
	int i;
	int j;
	int tmp;

	i = 0;
	j = 0;
	tmp = data->a[0];
	while (data->a[i])
		i++;
	while (j < i)
	{
		data->a[j] = data->a[j + 1];
		j++;
	}
	data->a[j] = tmp;
}
	
int	main()
{
	t_swap data;

	parssing(&data);
}