/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalfunc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysensoy <ysensoy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 19:59:05 by ysensoy           #+#    #+#             */
/*   Updated: 2022/09/20 21:40:12 by ysensoy          ###   ########.fr       */
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

int		arg_controller(int argc, char **argv)
{
	int i;

	i = 0;
	if (argc != 5 && argc != 6)
	{
		write(2, "Arguman sayisi hatali🔪\n", 24);
		return(-1);
	}
	while (argv[i] != '\0')
	{
		if (ft_atoi(argv[i] <= 0))
		{
			write(2, "You should use different number🔢\n", 33);
			return(-1);
		}
		i++;
	}
	return(0);
}

int		gettime_stamp(long long timestamp)
{
	struct timeval tv;
	long  now;

	gettimeofday(&tv, NULL);
	now = (tv.tv_sec * 1000) + (tv.tv_usec * 1000);
	if (!timestamp)
		return(now);
	return(now - timestamp);
}
