/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ord_alphlong.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 09:25:58 by exam              #+#    #+#             */
/*   Updated: 2019/09/03 10:05:07 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

char	**ft_strsplit(char *str, int *len);

void	bubble_sort(char **arr, int len, int (*f)(char*, char*));
int		alpha_order(char *a, char *b);
int		len_order(char *a, char *b);

int		ft_strlen(char *str);
