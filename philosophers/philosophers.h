/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysensoy <ysensoy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 16:39:46 by ysensoy           #+#    #+#             */
/*   Updated: 2022/08/31 18:09:57 by ysensoy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>

typedef	struct philosophers
{
	int philo_bos;
	int	philo_counter;
	int	full;
	int eat;
	int last_eat;
	int think;
	int sleep;
}		t_philo;


int	ft_atoi(char *str);
int	arg_controller(int argc, char **argv);

#endif
