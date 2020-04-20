/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_uniq.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wstygg <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/09 15:38:21 by wstygg            #+#    #+#             */
/*   Updated: 2020/04/09 15:38:21 by wstygg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "conf.h"

int		check_uniq(int param, int uniq[PARAMS_N], int i, char *str)
{
	if (uniq[param])
	{
		fprintf(stderr, "Error at [%d] line:\n%s\n", i + 1, str);
		(param == COMMAND) ? ft_crash("Duplicate \"command\" parameter!\n") : 0;
		(param == DIRECTORY) ? ft_crash("Duplicate \"directory\" parameter!\n")
							 : 0;
		(param == UMASK) ? ft_crash("Duplicate \"umask\" parameter!\n") : 0;
		(param == COPIES) ? ft_crash("Duplicate \"copies\" parameter!\n") : 0;
		(param == STDOUT) ? ft_crash("Duplicate \"stdout\" parameter!\n") : 0;
		(param == STDERR) ? ft_crash("Duplicate \"stderr\" parameter!\n") : 0;
		(param == RESTART) ? ft_crash("Duplicate \"restart\" parameter!\n") : 0;
		(param == RETRIES) ? ft_crash("Duplicate \"retries\" parameter!\n") : 0;
		(param == ON_START) ? ft_crash("Duplicate \"on_start\" parameter!\n")
							: 0;
		(param == STOP_SIGNAL) ? ft_crash("Duplicate \"stop_signal\" "
										  "parameter!\n") : 0;
		(param == STOP_WAITING) ? ft_crash("Duplicate \"stop_waiting\" "
										   "parameter!\n") : 0;
		(param == SUCCESS_WAITING) ? ft_crash("Duplicate \"success_waiting\" "
											  "parameter!\n") : 0;
		(param == END_CODES) ? ft_crash("Duplicate \"end_codes\" parameter!\n")
							 : 0;
		(param == ENV) ? ft_crash("Duplicate \"env\" parameter!\n") : 0;
	}
	uniq[param] = 1;
	return (1);
}
