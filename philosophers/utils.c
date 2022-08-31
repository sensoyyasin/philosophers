/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysensoy <ysensoy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 18:04:28 by ysensoy           #+#    #+#             */
/*   Updated: 2022/08/31 18:04:28 by ysensoy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_atoi(char *str)
{
	int	sign;
	int result;

	result = 0;
	sign = 1;
	while (*str != '\0' && (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-')
		sign *= -1;
	if (*str == '-' || *str == '+')
		str++;
	if (*str >= '0' && * str <= '9')
	{
		result = result * 10 - *str + 48;
		str++;
	}
	return(result * sign);
}

int	arg_controller(int argc, char **argv)
{
	if (argc != 5 || argc != 6)
	{
		write(1, "Number of argument is fault🔪\n", 29);
		exit(1);
	}
}
