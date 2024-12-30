/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-pma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 17:07:33 by juan-pma          #+#    #+#             */
/*   Updated: 2023/12/27 17:45:45 by juan-pma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <unistd.h>
# include <stdlib.h> 
# include <stdio.h>

# define ANSI_RED     "\x1b[31m"
# define ANSI_GREEN   "\x1b[32m"
# define ANSI_YELLOW  "\x1b[33m"
# define ANSI_BLUE    "\x1b[34m"
# define ANSI_MAGENTA "\x1b[35m"
# define ANSI_CYAN    "\x1b[36m"
# define ANSI_RESET   "\x1b[0m"
# define ANSI_BOLD          "\x1b[1m"
# define ANSI_UNDERLINE     "\x1b[4m"

// Libft programs. 

void	ft_putstr(char *str);
void	ft_putnbr(unsigned int nbr);
int		ft_isdigit(char s);
int		ft_checker(char *s);
#endif
