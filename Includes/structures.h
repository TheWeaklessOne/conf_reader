/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wstygg <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/07 16:30:25 by wstygg            #+#    #+#             */
/*   Updated: 2020/04/21 16:21:33 by wstygg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

# include <stdlib.h>

# define BUFF_SIZE		10
# define END_CODES_N	255

enum					e_restart
{
	NEVER = 0,
	ALWAYS,
	ON_CRASH
};

enum					e_params
{
	COMMAND = 0,
	DIR,
	UMASK,
	COPIES,
	STDOUT,
	STDERR,
	RESTART,
	RETRIES,
	ON_START,
	STOP_SIGNAL,
	STOP_WAITING,
	SUCCESS_WAITING,
	END_CODES,
	ENV,
	PARAMS_N
};

typedef struct			s_task
{
	int					remake;					//флаг, нужно ли пересоздавать процесс. Каждый новый процесс имеет remake = 1,
												// но если мы прочитали новый conf, и в предыдущем был процессс с тем же именем,
												// и его содержимое не менялось, то remake = 0
	char				*name;					//имя процесса в структуре
	char				*command;				//путь к команде или ее название
	char				*directory;				//рабочая директория программы
	int					umask;					//число для функции umask()
	int					copies;					//количество экземпляров программы
	int					tstdout;				//перенаправление stdout
	int 				tstderr;				//перенаправление stderr
	int					restart;				//флаг, при каких условиях нужно перезапускать программу
	int					retries;				//сколько нужно сделать попыток рестарта при неудачном завершении
	int					on_start;				//запускать программу при старте taskmaster или нет
	int					stop_signal;			//какой сигнал следует считать сигналом завершения программы
	int					stop_waiting;			//сколько нужно ждать нормального завершения программы после сигнала стоп, прежде чем сделать kill
	int					success_waiting;		//сколько времени должно пройти, прежде чем программа будет считаться успешно запущенной
	int					end_codes[END_CODES_N];	//какие коды, возвращаемые программой, стоит считать за успешное завершение
	char				**env;					//переменные среды для программы, если NULL, то стандартно
}						t_task;

typedef struct			s_get_next_line
{
	char				*lp_cmp;
	char				*lp_prev;
	char				*line;
	size_t				line_count;
	size_t				interval;
	size_t				tmp;
	ssize_t				count;
	char				buffer[BUFF_SIZE];
}						t_get_next_line;

#endif
