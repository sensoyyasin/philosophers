/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysensoy <ysensoy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 17:10:34 by ysensoy           #+#    #+#             */
/*   Updated: 2022/09/07 18:04:38 by ysensoy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void    has_taken_fork(t_philo *ptr)
{
    int i;
    int r_fork;
    int l_fork;
    char *situation;

    if (ptr->setter->philosoph_counter < 2)
        return ;
    i = ptr->setter->philosoph_counter;
    r_fork = (ptr->philo_position + 1) % i;
    l_fork = (ptr->philo_position - 1 + i) % i;
    situation = ptr->philo_position;
    pthread_mutex_lock(&ptr->setter->right_fork);
    if (!situation[l_fork] && !situation[r_fork] && !situation[ptr->philo_position])
    {
        situation[ptr->philo_position] = 1;
        printf("Right fork was taken🍴\n");
        printf("Left fork was taken🍴\n");
    }
    pthread_mutex_unlock(&ptr->setter->right_fork);
}

void    mainer(t_philo *philo)
{
    t_philo *philo;

    philo = (t_philo *)philo;
    philo->last_eat = timeinc(0);
    while (1)
    {
        if (philo->philo_position % 2 != 0)
            usleep(200);
        if (philo->setter->eat_counter && philo->setter->eat_destination_timer
            >= philo->setter->philosoph_counter)
        {
            pthread_mutex_lock(&philo->setter->left_fork);
            printf("The food was eaten\n");
            exit(0);
        }
        think(philo);
        eat(philo);
        sleep(philo);
    }
    return(NULL);
}

void    think(t_philo *philo)
{
    long timestamp;

    while (!philo->setter->situation[philo->philo_position])
    {
        has_taken_fork(philo);
        if (!philo->setter->situation[philo->philo_position])
        {
            if (timeinc(philo->last_eat) >= philo->setter->dead_time)
            {
                timestamp = timeinc(philo->timestamp);
                pthread_mutex_lock(&philo->setter->left_fork);
                printf("Philosoph is sleeping right now🌙\n");
            }
            exit(0);
        }
        sleep(100);
    }
    usleep(100);
}

void    eat(t_philo *philo)
{
    if (philo->setter->situation[philo->philo_position])
    {
        philo->last_eat = timeinc(0);
        printf("Eating🍕\n");
        sleep(100);
        if (philo->eat < philo->setter->eat_destination_timer)
            philo->eat++;
        if (!philo->full && philo->eat == philo->setter->eat_destination_timer)
        {
            philo->setter->eat_counter++;
            philo->full++;
        }
    }
}

void    sleep(t_philo *philo)
{
    if (philo)
}
