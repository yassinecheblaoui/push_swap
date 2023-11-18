/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachebla <yachebla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 17:46:14 by yachebla          #+#    #+#             */
/*   Updated: 2023/11/18 20:42:24 by yachebla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int is_alldigit(char **result) {
  int j = 0;
  while (result[j])
  {
      int i = 0;
      while(result[j][i])
      {
        if ((result[j][i] < '0' || result[j][i] > '9') && result[j][i] != '-' &&  result[j][i] != '+')
          ft_protect(3);
        i++;
      }
      j++;
  }
  return 0;
}

void ft_free(char **arr,char *str,int j)
{
  int i;
  
  i = 0;
  if (str)
    free(str);
  if(arr)
  {
    while (i < j)
      free(arr[i++]);
    free(arr);
  }
}

void init_stack(t_stack *a, char **result , int len)
{
	int		i;
	int		j;
	int		value;
	t_stack	*new_node;
	
	i = 0;
	j = len - 1;
	while (i < len )
	{
		value = ft_atoi(result[j]);
		printf("%d--\n",value);
		new_node = malloc(sizeof(t_stack));
		if (!new_node)
		  ft_protect(1);
		new_node->value = value;
		new_node->next = a;
		a = new_node;
		i++;
		j--;
	}
	print_stack(a);
}
int parce_args(char **av, t_stack *a) 
{
  int i;
  int j;
  int size;
  char **splited;
  char **result;

  i = 1; 
  size = 0;
  while (av[i])
  {
    splited = ft_split(av[i],' ');
    j = 0;
    while(splited[j])
      j++;
    size += j;
    ft_free(splited,NULL,j);
    i++;
  }
  result = (char **)malloc(sizeof(char *) * size + 1);
  if (!result)
    ft_protect(1);
  i = 1;
  j = 0;
  while (av[i])
  {
    size = 0;
    splited = ft_split(av[i],' ');
    while(splited[size])
    {
      result[j] = ft_strdup(splited[size]);
      printf("%s ===\n",result[j]);
      size++;
      j++;
    }
    ft_free(splited,NULL,size);
    i++;
    
  }
  result[j] = NULL;
  is_alldigit(result);
  check_double(result);
  check_sign(result);
  check_int(result);
  a = NULL;
  init_stack(a,result, j);
//   print_stack(a);
  // ft_free(result,NULL,j);
  // while (1)
  // {
    
  // }
  return 0;
}
void	ft_protect(int x)
{
	if (x == 1)
		write(2,"Error\n", ft_strlen("Error\n"));
	if (x == 2)
		write(2,"Error double arg\n", ft_strlen("Error double arg\n"));
	if (x == 3)
		write(2,"Error arg not digit\n", ft_strlen("Error arg not digit\n"));
	exit(1);
}

