/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_up.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/30 16:03:57 by npineau           #+#    #+#             */
/*   Updated: 2014/06/26 19:47:10 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/shm.h>
#include <sys/msg.h>
#include <sys/sem.h>
#include <stdio.h>
#include "gfx.h"

int	clean_up(t_env *e)
{
	struct shmid_ds	tmp;

	x_int(-1, shmctl(e->shm.shmid, IPC_STAT, &tmp), "shmctl", e);
	if (tmp.shm_nattch == 0)
	{
		if (shmctl(e->shm.shmid, IPC_RMID, NULL) == -1)
			perror("shmctl");
		x_int(-1, semctl(e->shm.semid, 0, IPC_RMID), "semctl", e);
	}
	else if (tmp.shm_nattch == 1)
		shmdt(e->shm.shm);
	else if (tmp.shm_nattch > 1)
		return (0);
	return (1);
}
