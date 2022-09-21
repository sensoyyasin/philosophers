/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysensoy <ysensoy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 20:11:22 by ysensoy           #+#    #+#             */
/*   Updated: 2022/09/20 21:38:20 by ysensoy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void    has_taken_fork(t_philo *ptr)
{
    int i;
    int r_fork;
    int l_fork;
    char *situation;

    i = ptr->setter->philosoph_counter;
    r_fork = (ptr->philo_position + 1) % i;
    l_fork = (ptr->philo_position - 1 + i) % i;
    situation = ptr->philo_position;
    pthread_mutex_lock(&ptr->setter->right_fork);
    if (!situation[l_fork] && !situation[r_fork] && !situation[ptr->philo_position])
    {
        situation[ptr->philo_position] = 1;
        printf("Right fork has been taken");
        printf("Left fork has been taken");
    }
    pthread_mutex_unlock(&ptr->setter->right_fork);
}

void	*mainer(void *phil)
{
	t_philo		*philo;

	phil = (t_philo *)philo;
	thinking(philo);
	thinking(philo);
	thinking(philo);
}

void	thinking(t_philo *ptr)
{
}

void	eating(t_philo *ptr)
{

}

void	sleeping(t_philo *ptr)
{

}
