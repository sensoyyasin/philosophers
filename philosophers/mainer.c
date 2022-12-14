/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysensoy <ysensoy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 17:10:34 by ysensoy           #+#    #+#             */
/*   Updated: 2022/09/30 19:12:38 by ysensoy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	has_taken_fork(t_philo *ptr)
{
	int		i;
	char	*situation;

	if (ptr->setter->philosoph_counter == 1)
	{
		fy_printf(ptr, "Left fork was taken🍴");
		ft_sleep(ptr->setter->dead_time);
		fy_printf(ptr, "Philosopher died💀");
		return (0);
	}
	i = ptr->setter->philosoph_counter;
	situation = ptr->setter->situation;
	pthread_mutex_lock(&ptr->setter->forks[ptr->p_pos + 1 % i]);
	pthread_mutex_lock(&ptr->setter->forks[ptr->p_pos]);
	situation[ptr->p_pos] = 1;
	if (!fy_printf(ptr, "Right fork has taken🍴"))
		return (0);
	if (!fy_printf(ptr, "Left fork has taken🍴"))
		return (0);
	return (1);
}

void	*mainer(void *philo)
{
	t_philo	*phil;

	phil = (t_philo *)philo;
	phil->last_eat = timeinc(0);
	if (phil->p_pos % 2 != 0)
		usleep(2000);
	while (1)
	{
		if (!thinking(phil))
			break ;
		if (!eating(phil, phil->setter->philosoph_counter))
			break ;
		if (!sleeping(phil))
			break ;
	}
	return (NULL);
}

int	thinking(t_philo *philo)
{
	long long	timestamp;

	if (!has_taken_fork(philo))
		return (0);
	if (timeinc(philo->last_eat) >= philo->setter->dead_time
		&& philo->setter->death_check == 0)
	{
		timestamp = timeinc(philo->timestamp);
		if (fy_printf(philo, "Philosopher died💀💀💀"))
			philo->setter->death_check = 1;
	}
	return (1);
}

int	eating(t_philo *philo, int i)
{
	if (philo->setter->situation[philo->p_pos])
	{
		philo->last_eat = timeinc(0);
		if (!fy_printf(philo, "Philosopher is eating 🍕"))
		{
			pthread_mutex_unlock(&philo->setter->forks[philo->p_pos + 1 % i]);
			pthread_mutex_unlock(&philo->setter->forks[philo->p_pos]);
			return (0);
		}
		ft_sleep(philo->setter->eat_time);
		pthread_mutex_unlock(&philo->setter->forks[philo->p_pos + 1 % i]);
		pthread_mutex_unlock(&philo->setter->forks[philo->p_pos]);
		philo->eat++;
		if (philo->eat == philo->setter->eat_destination)
		{
			pthread_mutex_lock(&philo->setter->dest_philo);
			philo->setter->destp_count++;
			pthread_mutex_unlock(&philo->setter->dest_philo);
		}
		if (philo->setter->destp_count == philo->setter->philosoph_counter)
			philo->setter->eat_check = 1;
	}
	return (1);
}

int	sleeping(t_philo *philo)
{
	if (philo->setter->situation[philo->p_pos])
	{
		if (!fy_printf(philo, "Philosoph is sleeping right now🌙💤"))
			return (0);
		ft_sleep(philo->setter->sleep_time);
		if (timeinc(philo->last_eat) >= philo->setter->dead_time
			&& philo->setter->death_check == 0)
		{
			if (!fy_printf(philo, "Philosopher died💀💀"))
				philo->setter->death_check = 1;
		}
		if (!fy_printf(philo, "Philo is thinking💭💭💭"))
			return (0);
	}
	return (1);
}
