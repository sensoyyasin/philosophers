/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysensoy <ysensoy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 17:10:34 by ysensoy           #+#    #+#             */
/*   Updated: 2022/09/14 16:10:37 by ysensoy          ###   ########.fr       */
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
    situation = ptr->setter->situation;
    pthread_mutex_lock(&ptr->setter->right_fork);
    if (!situation[l_fork] && !situation[r_fork] && !situation[ptr->philo_position])
    {
        situation[ptr->philo_position] = 1;
        printf("Right fork was taken🍴\n");
        printf("Left fork was taken🍴\n");
    }
    pthread_mutex_unlock(&ptr->setter->right_fork);
}

void    *mainer(void *philo)
{
    t_philo *phil;

    phil = (t_philo *)philo;
    phil->last_eat = timeinc(0);
    while (1)
    {
        if (phil->philo_position % 2 != 0)
            usleep(200);
        if (phil->setter->eat_counter && phil->setter->eat_destination_timer
            >= phil->setter->philosoph_counter)
        {
            pthread_mutex_lock(&phil->setter->left_fork);
            printf("---Food at least %d times---\n",phil->setter->eat_destination_timer);
            exit(0);
        }
        thinking(phil);
        eating(phil);
        sleeping(phil);
    }
    return(NULL);
}

void    thinking(t_philo *philo)
{
    long long timestamp;

    while (!philo->setter->situation[philo->philo_position])
    {
        has_taken_fork(philo);
        if (!philo->setter->situation[philo->philo_position])
        {
            if (timeinc(philo->last_eat) >= philo->setter->dead_time)
            {
                timestamp = timeinc(philo->timestamp);
                pthread_mutex_lock(&philo->setter->left_fork);
                printf("Time %lld | Philo Num : %d | died 💀\n",timestamp, philo->philo_position + 1);
                exit(0);
            }
            exit(0);
        }
        ft_sleep(1);
    }
    usleep(100);
}

void    eating(t_philo *philo)
{
    if (philo->setter->situation[philo->philo_position])
    {
        philo->last_eat = timeinc(0);
        fy_printf(philo, "is eating 🍕");
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

void    sleeping(t_philo *philo)
{
    long long   x;
    if (philo->setter->situation[philo->philo_position])
    {
        printf("Philosoph is sleeping right now🌙💤\n");
        pthread_mutex_lock(&philo->setter->right_fork);
        philo->setter->situation[philo->philo_position] = 0;
        pthread_mutex_unlock(&philo->setter->right_fork);
        x = timeinc(0);
        while (philo->setter->sleep_time > timeinc(0) - x)
        {
            if (timeinc(philo->last_eat) >= philo->setter->dead_time)
            {
                pthread_mutex_lock(&philo->setter->left_fork);
                printf("The philosopher died💀💀💀\n");
                exit(0);
            }
            sleep(100);
        }
        fy_printf(philo, "Philo is sleeping💤💤💤");
    }
}
