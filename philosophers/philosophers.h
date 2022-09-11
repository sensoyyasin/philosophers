/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasinsensoy <yasinsensoy@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 16:39:46 by ysensoy           #+#    #+#             */
/*   Updated: 2022/09/11 18:27:29 by yasinsensoy      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>

typedef	struct setter t_setter;
struct timeval current_time;


typedef	struct philo
{
	pthread_t		t_id;
	struct setter *setter;
	int 		philo_position;
	int			full;
	int 		eat;
	long long	last_eat;
	char		think;
	int 		sleep;
	long long 	timestamp;
}		t_philo;

typedef struct setter
{
	pthread_mutex_t	right_fork;
	pthread_mutex_t	left_fork;
	t_philo		*philosoph;
	char		*situation;
	int			philosoph_counter;
	int			dead_time;
	int			eat_time;
	int 		sleep_time;
	int			eat_destination_timer;
	int			eat_counter;
}		t_setter;

//mainer
void    *mainer(void *philo);
void    eat(t_philo *philo);
void    sleeper(t_philo *philo);
void    think(t_philo *philo);

//utils
int		ft_atoi(char *str);
void	arg_controller(int argc, char **argv);
long	timeinc(long timestamp);
void    has_taken_fork(t_philo *ptr);

#endif
