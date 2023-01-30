/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 10:10:17 by yhuberla          #+#    #+#             */
/*   Updated: 2023/01/30 10:10:17 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>
# include <pthread.h>
# include <sys/types.h>
# include <signal.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <semaphore.h>

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
	int			num;
	int			t_last_meal;
	int			meal_count;
	int			t_start;
	int			pid;
	pthread_t	death;
	t_table		*table;
}				t_philo;

struct	s_table {
	int		seats;
	int		t_die;
	int		t_eat;
	int		t_sleep;
	int		satiety;
	sem_t	*full_belly;
	t_philo	*philos;
	sem_t	*forks;
	sem_t	*mailbox;
};

int		parse_input(t_table *table, int ac, char **av);

int		init_semaphores(t_table *table);
void	close_semaphores(t_table *table);

int		init_processes(t_table *table);
void	kill_processes(t_table *table, int limit);

void	output_msg(t_philo *philo, char *msg);
int		output_error(char *msg);

int		get_time(void);
void	*death_check(void *arg);

#endif
