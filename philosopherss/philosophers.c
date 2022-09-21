/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysensoy <ysensoy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 19:59:01 by ysensoy           #+#    #+#             */
/*   Updated: 2022/09/20 21:39:57 by ysensoy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int		ender(t_setter *setter)
{
	pthread_mutex_destroy(&setter->right_fork);
	pthread_mutex_destroy(&setter->left_fork);
	free(setter->philosophers);
	free(setter->situation);
	free(setter->philosophers->thread_id);
	return(0);
}

void	initializer(t_setter *ptr, char **argv)
{
	int i;

	i = 0;
	ptr->philosoph_counter = ft_atoi(argv[1]);
	ptr->dead_time = ft_atoi(argv[2]);
	ptr->eat_time = ft_atoi(argv[3]);
	ptr->sleep_time = ft_atoi(argv[4]);
	ptr->eat_counter = 0;
	if (argv[5] != NULL)
		ptr->eat_destination_timer = ft_atoi(argv[5]);
	ptr->philosophers = malloc(sizeof(t_philo) * ptr->philosoph_counter);
	ptr->situation = malloc(ptr->philosoph_counter);
	pthread_mutex_init(&ptr->right_fork, NULL);
	pthread_mutex_init(&ptr->left_fork, NULL);
	while (ptr->philosoph_counter > i)
	{
		ptr->philosophers->eat = 0;
		ptr->philosophers->think = 0;
		ptr->philosophers->full = 0;
		ptr->philosophers->die = 0;
		ptr->philosophers->philo_position = i;
		ptr->philosophers->timestamp = gettime_stamp(0);
		i++;
	}
}

int main(int argc, char **argv)
{
	int			i;
	t_setter	*s;

	if (arg_controller(&s, argv)==-1)
		return (1);
	initializer(&s, argv);
	i = 0;
	while (s->philosoph_counter > i)
	{
		pthread_create(s->philosophers[i].thread_id, NULL, &mainer, NULL);
		i++;
	}
	i = 0;
	while (s->philosoph_counter > i)
	{
		pthread_join(s->philosophers[i].thread_id, NULL);
		i++;
	}
	return(ender(&s));
}
