/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysensoy <ysensoy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 16:39:46 by ysensoy           #+#    #+#             */
/*   Updated: 2022/09/21 13:55:26 by ysensoy          ###   ########.fr       */
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
# include <stdbool.h>

typedef	struct setter t_setter;

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
	int			exit_status;
}		t_setter;

//mainer
void    *mainer(void *philo);
void    eating(t_philo *philo);
void	sleeping(t_philo *philo);
void    thinking(t_philo *philo);

//utils
int		ft_atoi(char *str);
int		arg_controller(int argc, char **argv);
long	timeinc(long timestamp);
void    has_taken_fork(t_philo *ptr);
void	fy_printf(t_philo *ptr, char *str);
void	ft_sleep(int now);
long	timeinc(long timestamp);
int		ctrl(int dead);


#endif