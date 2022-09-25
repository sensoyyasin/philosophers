/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysensoy <ysensoy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 18:04:28 by ysensoy           #+#    #+#             */
/*   Updated: 2022/09/25 17:41:38 by ysensoy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_atoi(char *str)
{
	int	sign;
	int result;

	result = 0;
	sign = 1;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-')
		sign *= -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + *str - 48;
		str++;
	}
	return(result * sign);
}

int 	arg_controller(int argc, char **argv, int i, int j)
{
	if (argc != 5 && argc != 6)
	{
		write(2, "Number of argument is fault ❌\n", 32);
		return(-1);
	}
	while (i < argc)
	{
		while (argv[i][j] != '\0')
		{
			if ((argv[i][j] >= '0' && argv[i][j] <= '9'))
				j++;
			else if (j == 0 && argv[i][j] == '+' && argv[i][j + 1] > 32)
				j++;
			else
				return (-1);
		}
		j = 0;
		if (ft_atoi(argv[i]) <= 0)
			return (-1);
		i++;
	}
	return(1);
}

int		fy_printf(t_philo *ptr, char *str)
{
	pthread_mutex_lock(&ptr->setter->msg);
	if (ptr->setter->death_check == 1 || ptr->setter->eat_check == 1)
	{
		pthread_mutex_unlock(&ptr->setter->msg);
		return(0);
	}
	printf("timestamp_in_ms %ld | Philosoph_id : %d | %s\n",
		timeinc(ptr->timestamp), ptr->philo_position + 1, str);
	pthread_mutex_unlock(&ptr->setter->msg);
	return(1);
}

long	timeinc(long timestamp)
{
	long long now;
	struct timeval current_time;

	gettimeofday(&current_time, NULL);
	now = (current_time.tv_sec * 1000) + (current_time.tv_usec / 1000);
	if (!timestamp)
		return(now);
	else
		return(now - timestamp);
}

void	ft_sleep(int now)
{
	long long timestamp;

	timestamp = timeinc(0);
	while (timeinc(0) - timestamp < now)
		usleep(100);
}
