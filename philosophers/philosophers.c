/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysensoy <ysensoy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 16:50:29 by ysensoy           #+#    #+#             */
/*   Updated: 2022/09/25 17:43:41 by ysensoy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	program_ender(t_setter	*setter)
{
	int	i;

	i = -1;
	while (++i < setter->philosoph_counter)
		pthread_mutex_destroy(&setter->forks[i]);
	free(setter->forks);
	free(setter->philosoph);
	free(setter->situation);
	free(setter->philosoph->t_id);
	free(setter);
	return(0);
}

void	setter(t_setter *ptr, char **argv)
{
	int	i;

	i = 0;
	ptr->philosoph_counter = ft_atoi(argv[1]);
	ptr->dead_time = ft_atoi(argv[2]);
	ptr->eat_time = ft_atoi(argv[3]);
	ptr->sleep_time = ft_atoi(argv[4]);
	ptr->destp_count = 0;
	ptr->forks = malloc(sizeof(pthread_mutex_t) * ptr->philosoph_counter);
	if (argv[5] != NULL)
		ptr->eat_destination = ft_atoi(argv[5]);
	ptr->philosoph = malloc(sizeof(t_philo) * ptr->philosoph_counter);
	ptr->situation = malloc(ptr->philosoph_counter);
	pthread_mutex_init(&ptr->dest_philo, NULL);
	pthread_mutex_init(&ptr->msg, NULL);
	while (ptr->philosoph_counter > i)
	{
		ptr->philosoph[i].setter = ptr;
		ptr->philosoph[i].timestamp = timeinc(0);
		ptr->situation[i] = 0;
		ptr->philosoph[i].eat = 0;
		ptr->philosoph[i].philo_position = i;
		pthread_mutex_init(&ptr->forks[i], NULL);
		i++;
	}
}

int main(int argc, char **argv)
{
	t_setter	a;
	int			i;

	i = 0;
	a.death_check = 0;
	a.eat_check = 0;
	if (arg_controller(argc, argv, 1, 0) == -1)
		return(1);
	setter(&a, argv);
	while (a.philosoph_counter > i)
	{
		pthread_create(&a.philosoph[i].t_id, NULL, &mainer, &a.philosoph[i]);
		i++;
	}
	i = 0;
	while (a.philosoph_counter > i)
	{
		pthread_join(a.philosoph[i].t_id , NULL);
		i++;
	}
	return(0);
}
