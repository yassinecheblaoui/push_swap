/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachebla <yachebla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 17:46:14 by yachebla          #+#    #+#             */
/*   Updated: 2023/11/16 20:59:14 by yachebla         ###   ########.fr       */
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

void ft_free(char **arr,char *str,size_t j)
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

int parce_args(char **av) 
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

