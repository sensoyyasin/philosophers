/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysensoy <ysensoy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 16:50:29 by ysensoy           #+#    #+#             */
/*   Updated: 2022/09/21 13:52:24 by ysensoy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	program_ender(t_setter	*setter)
{
	pthread_mutex_destroy(&setter->right_fork);
	pthread_mutex_destroy(&setter->left_fork);
	free(setter->philosoph);
	free(setter->situation);
	//free(setter->philosoph->t_id);
	//free(setter);
	return(0);
}

void	setter(t_setter *ptr, char **argv)
{
	int	i;

	i = 0;
	ptr->philosoph_counter = ft_atoi(argv[1]); //filozof sayisi
	ptr->dead_time = ft_atoi(argv[2]); //ölme zamani
	ptr->eat_time = ft_atoi(argv[3]); //yemek zamani
	ptr->sleep_time = ft_atoi(argv[4]); //uyuma zamani
	ptr->eat_counter = 0; //yeme hedefi
	if (argv[5] != NULL)
		ptr->eat_destination_timer = ft_atoi(argv[5]);
	ptr->philosoph = malloc(sizeof(t_philo) * ptr->philosoph_counter);
	ptr->situation = malloc(ptr->philosoph_counter);
	pthread_mutex_init(&ptr->right_fork, NULL);
	pthread_mutex_init(&ptr->left_fork, NULL);
	while (ptr->philosoph_counter > i)
	{
		ptr->philosoph[i].setter = ptr;
		ptr->philosoph[i].timestamp = timeinc(0);
		ptr->situation[i] = 0;
		ptr->philosoph[i].eat = 0;
		ptr->philosoph[i].full = 0;
		ptr->philosoph[i].think = 0;
		ptr->philosoph[i].philo_position = i;
		i++;
	}
}

// void		dead(t_setter *ptr)
// {
// 	int i;
// 	while (!ptr->die)
// 	{
// 		i = 0;
// 		while (ptr->philosoph_counter > i && !ptr->die)
// 		{
// 			if (timeinc(0) - ptr->philo[i].last_eat > ptr->dead_time)
// 			{
// 				printf("dead\n");
// 				ptr->die = true;
// 			}
// 			usleep(100);
// 			if (ptr->eat_destination_timer != 0 && ptr->philo[0].eat >= ptr->eat_destination_timer)
// 				ptr->everything_isok = true;
// 			i++;
// 		}
// 	}

// }

int main(int argc, char **argv)
{
	t_setter	a;
	int			i;

	a.exit_status = 0;
	i = 0;
	if (arg_controller(argc, argv) == -1)
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
	return(program_ender(&a));
}
