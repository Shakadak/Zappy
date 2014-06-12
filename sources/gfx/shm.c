/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibanez <jibanez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/11 18:33:04 by jibanez           #+#    #+#             */
/*   Updated: 2014/06/11 19:06:52 by jibanez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/shm.h>
#include <sys/sem.h>
#include "libft.h"
#include "gfx_struct.h"

int			sem_lock(t_env *gfx, int lock)
{
	struct sembuf	sb;

	sb.sem_num = 0;
	sb.sem_op = lock;
	if ((semop(gfx->semid, &sb, 1)) == -1)
		return (ft_error("semop: can't lock sem"));
	return (0);
}

int			init_shm(t_env *gfx)
{
	key_t			key;

	if ((key = ftok("gfx", 's')) == -1)
		return (ft_error("ftok: can't get key"));
	if ((gfx->shmid = shmget(key, 4096, IPC_CREAT | 0644)) == -1)
		return (ft_error("shmget: can't get shmid"));
	if ((gfx->shm = shmat(gfx->shmid, 0, 0)) == (char *)(-1))
		return (ft_error("shmatt: can't map the shared memory"));
	ft_memset(gfx->shm, 0, 4096);
	gfx->semid = semget(key, 1, IPC_EXCL | IPC_CREAT | 0644);
	if (gfx->semid == -1)
		return (ft_error("semget: can't get semid"));
	return (0);
}

int			shm_free(t_env *gfx)
{
	struct	shmid_ds	buff;

	shmdt(gfx->shm);
	shmctl(gfx->shmid, IPC_RMID, &buff);
	semctl(gfx->semid, 0, IPC_RMID);
	return (0);
}
