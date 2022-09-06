/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forker.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysensoy <ysensoy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 17:10:34 by ysensoy           #+#    #+#             */
/*   Updated: 2022/09/06 20:32:34 by ysensoy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

//void    eat()
//void    sleep()
//void    think()

void    has_taken_fork(t_philo *ptr)
{
    int i;
    int r_fork;
    int l_fork;
    char *situation;

    i = ptr->philo_counter;
    if (ptr->philo_counter < 2)
        return ;
    r_fork = (ptr->philo_position + 1) % i;
    l_fork = (ptr->philo_position - 1 + i) % i;

    pthread_mutex_lock(&ptr.);
}

void    forker()
{

}
