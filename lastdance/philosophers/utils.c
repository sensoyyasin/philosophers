/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysensoy <ysensoy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 18:04:28 by ysensoy           #+#    #+#             */
/*   Updated: 2022/09/21 07:38:40 by ysensoy          ###   ########.fr       */
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

int 	arg_controller(int argc, char **argv)
{
	int i;

	i = 1;
	if (argc != 5 && argc != 6)
	{
		write(2, "Number of argument is fault ❌\n", 32);
		return(-1);
	}
	while (argv[i] != NULL)
	{
		if ((ft_atoi(argv[i]) <= 0))
		{
			printf("You should use different number🔢 \n");
			return(-1);
		}
		i++;
	}
	return(0);
}

void	fy_printf(t_philo *ptr, char *str)
{
	pthread_mutex_lock(&ptr->setter->left_fork);
	printf("Time : %ld | Philosoph_id : %d | %s\n",
		timeinc(ptr->timestamp), ptr->philo_position + 1, str);
	pthread_mutex_unlock(&ptr->setter->left_fork);
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
		usleep(50);
}