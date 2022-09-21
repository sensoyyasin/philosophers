/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysensoy <ysensoy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 18:46:09 by ysensoy           #+#    #+#             */
/*   Updated: 2022/09/20 21:14:40 by ysensoy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>

typedef	struct setter t_setter;
struct timeval tv;

typedef	struct philosophers
{
	pthread_t		thread_id;
	struct setter	*setter;
	int				philo_position;
	int				think;
	int				full;
	int				situation;
	int				eat;
	int				die;
	long long		timestamp;
}	t_philo;

typedef	struct setter
{
	t_philo			*philosophers;
	char			*situation;
	pthread_mutex_t		right_fork;
	pthread_mutex_t		left_fork;
	int				philosoph_counter;
	int				eat_destination_timer;
	int				eat_time;
	int				eat_counter;
	int				sleep_time;
	int				dead_time;
}	t_setter;

void	*mainer(void *phil);
void	thinking(t_philo *ptr);
void	eating(t_philo *ptr);
void	sleeping(t_philo *ptr);
void    has_taken_fork(t_philo *ptr);

#endif
