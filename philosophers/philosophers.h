/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysensoy <ysensoy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 16:39:46 by ysensoy           #+#    #+#             */
/*   Updated: 2022/09/30 18:53:08 by ysensoy          ###   ########.fr       */
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

typedef struct setter	t_setter;
typedef struct philo
{
	pthread_t		t_id;
	struct setter	*setter;
	int				p_pos;
	int				eat;
	long long		last_eat;
	long long		timestamp;
}		t_philo;

typedef struct setter
{
	pthread_mutex_t	*forks;
	pthread_mutex_t	dest_philo;
	pthread_mutex_t	msg;
	t_philo			*philosoph;
	char			*situation;
	int				philosoph_counter;
	int				dead_time;
	int				eat_time;
	int				sleep_time;
	int				eat_destination;
	int				destp_count;
	int				eat_check;
	int				death_check;
}		t_setter;

//mainer
void	*mainer(void *philo);
int		eating(t_philo *philo, int i);
int		sleeping(t_philo *philo);
int		thinking(t_philo *philo);

//utils
int		ft_atoi(char *str);
int		arg_controller(int argc, char **argv, int i, int j);
long	timeinc(long timestamp);
int		has_taken_fork(t_philo *ptr);
int		fy_printf(t_philo *ptr, char *str);
void	ft_sleep(int now);
long	timeinc(long timestamp);
int		ctrl(int dead);

#endif
