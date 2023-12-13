/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachebla <yachebla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 17:46:14 by yachebla          #+#    #+#             */
/*   Updated: 2023/06/24 17:56:11 by yachebla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int isAllDigit(char *str) {
  int i = 0;
  while(str[i]) {
    if ((str[i] < '0' || str[i] > '9') && str[i] != '-' &&  str[i] != '+')
      return 1;
    i++;
  }
  return 0;
}
void ft_free(char **arr,char *str,size_t j) {
  int i;
  
  i = 0;
  if (str)
    free(str);
  if(arr) {
    while (i < j)
      free(arr[i++]);
    free(arr);
  }
}

int parce_args(char **av
) {
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
    while(splited[j]) {
      j++;
    }
    size += j;
    ft_free(splited,NULL,j);
    i++;
  }
  result = (char **)malloc(sizeof(char *) * size + 1);
  i = 1;
  while (av[i])
  {
    splited = ft_split(av[i],' ');
    j = 0;
    while(splited[j]) {
      result[size] = ft_strdup(splited[j]);
      printf("%s ===\n",result[size]);
      size++;
      j++;
    }
    // ft_free(splited,NULL,j);
    i++;
  }

  // i = 0;
  // while (result[i])
  // {
  //   if (isAllDigit(result[i]))
  //     return 1;
  //   i++;
  // }
  

  return 0;
}

int main(int ac, char **av) {
  t_stack a;
  t_stack b;
  if (ac < 2) {
    write(2,"Error\n", ft_strlen("Error\n"));
    return (1);
  }
  if(parce_args(av)) {
    write(2,"Error\n", ft_strlen("Error\n"));
    return (1);
  }
}