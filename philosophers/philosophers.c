/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysensoy <ysensoy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 16:50:29 by ysensoy           #+#    #+#             */
/*   Updated: 2022/09/07 17:33:02 by ysensoy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	setter(t_setter *ptr, char **argv)
{
	int	i;

	i = 0;
	ptr->philosoph_counter = ft_atoi(argv[1]);
	ptr->dead_time = ft_atoi(argv[2]);
	ptr->eat_time = ft_atoi(argv[3]);
	ptr->sleep_time = ft_atoi(argv[4]);
	ptr->eat_counter = 0;
	if (argv[5] != NULL)
		ptr->eat_destination_timer = ft_atoi(argv[5]);
	ptr->philosoph = malloc(sizeof(t_philo) * ptr->philosoph_counter);
	ptr->situation = malloc(ptr->philosoph_counter);
	pthread_mutex_init(&ptr, NULL);
	pthread_mutex_init(&ptr->left_fork, NULL);
	while (ptr->philosoph_counter > i)
	{
		ptr->situation[i] = 0;
		ptr->philosoph[i].eat = 0;
		ptr->philosoph[i].full = 0;
		ptr->philosoph[i].think = 0;
		ptr->philosoph[i].philo_position = 0;
		i++;
	}


}

int main(int argc, char **argv)
{
	t_setter	a;
	int			i;
	int			j;

	i = 0;
	arg_controller(argc, argv);
	setter(&a, argv);
	while (a.philosoph_counter > i)
	{
		pthread_create(&a.philosoph[i].t_id, NULL, &mainer, NULL);
		i++;
	}
	j = 0;
	while (a.philosoph_counter > j)
	{
		pthread_join(a.philosoph[j].t_id, NULL);
		j++;
	}
	return(0);
}
