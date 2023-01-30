/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 09:44:24 by yhuberla          #+#    #+#             */
/*   Updated: 2023/01/30 13:11:07 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>
# include <pthread.h>

# define MSG_ARGS  "Usage :\n./philo number_of_philosophers time_to_die \
time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]\n"
# define MSG_INPUT "Arguments must be non zero positive integers\n"
# define MSG_FORK  "has taken a fork"
# define MSG_EAT   "is eating"
# define MSG_SLEEP "is sleeping"
# define MSG_THINK "is thinking"
# define MSG_DIE   "died"

typedef struct s_table	t_table;

typedef struct s_philo {
	int				num;
	int				t_last_meal;
	int				meal_count;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	pthread_t		thread;
	t_table			*table;
}				t_philo;

struct	s_table {
	int				alive;
	int				seats;
	int				t_start;
	int				t_die;
	int				t_eat;
	int				t_sleep;
	int				satiety;
	t_philo			*philos;
	pthread_mutex_t	*forks;
	pthread_mutex_t	mailbox;
	pthread_mutex_t	var_access;
};

int		parse_input(t_table *table, int ac, char **av);

int		init_mutex(t_table *table);
void	destroy_all_mutex(t_table *table, int limit);

int		init_threads(t_table *table);
void	destroy_all_threads(t_table *table, int limit);

void	output_msg(t_philo *philo, char *msg);
int		output_error(char *msg);

int		get_time(void);
void	death_cycle(void *arg);

#endif
