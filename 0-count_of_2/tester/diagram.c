/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   diagram.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 15:57:42 by mtaylor           #+#    #+#             */
/*   Updated: 2019/06/30 15:57:43 by mtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int		parse_flags(int argc, char **argv)
{
	int	c;
	int flag = 0;
	while ((c = getopt(argc, argv, "d")) != -1)
	{
		if (c == 'd')
			flag = 1;
	}
	return (flag);
}

void	print_diagram(int n)
{
	char *str = NULL;
	int	first = 1;

	printf("\e[2m");
	for (int i = 0; i <= n; ++i)
	{
		asprintf(&str, "%d", i);
		if (strchr(str, '2'))
		{
			if (first == 0)
				printf(", ");
			first = 0;
			for (int j = 0; str[j]; ++j)
			{
				if (str[j] == '2')
					printf("\e[4m%c\e[24m", str[j]);
				else
					printf("%c", str[j]);
			}
		}
		free(str);
		str = NULL;
	}
	printf("\n\e[0m");
}