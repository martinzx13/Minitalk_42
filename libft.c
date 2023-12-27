/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-pma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 16:39:04 by juan-pma          #+#    #+#             */
/*   Updated: 2023/12/27 16:42:41 by juan-pma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_checker(char *s)
{
	while (*s)
	{
		if (!ft_isdigit(*s)) 
			return (0);
		s++;
	}
	return (1);
}

int	ft_isdigit(char s)
{
	if (s >= '0' && s <= '9') 
		return (1);
	return (0);
}

void	ft_putnbr(unsigned int nbr)
{
	char			num;
	unsigned int	result;

	result = 0;
	if (nbr > 9)
		ft_putnbr(nbr / 10);
	result = result * 10 + (nbr % 10);
	num = result + '0';
	write(1, &num, 1);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}
