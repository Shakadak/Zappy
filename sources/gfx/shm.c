/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibanez <jibanez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/11 18:33:04 by jibanez           #+#    #+#             */
/*   Updated: 2014/06/14 17:42:40 by jvincent         ###   ########.fr       */
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
	if ((semop(gfx->shm.semid, &sb, 1)) == -1)
		return (ft_error("semop: can't lock sem"));
	return (0);
}

int			init_shm(t_env *gfx, int size)
{
	key_t			key;

	if ((key = ftok("gfx", 's')) == -1)
		return (ft_error("ftok: can't get key"));
	if ((gfx->shm.shmid = shmget(key, size, IPC_CREAT | 0644)) == -1)
		return (ft_error("shmget: can't get shmid"));
	if ((gfx->shm.shm = shmat(gfx->shm.shmid, 0, 0)) == (char *)(-1))
		return (ft_error("shmatt: can't map the shared memory"));
	ft_memset(gfx->shm.shm, 0, size);
	gfx->shm.semid = semget(key, 1, IPC_EXCL | IPC_CREAT | 0644);
	if (gfx->shm.semid == -1)
		return (ft_error("semget: can't get semid"));
	return (0);
}

int			shm_free(t_env *gfx)
{
	struct	shmid_ds	buff;

	shmdt(gfx->shm.shm);
	shmctl(gfx->shm.shmid, IPC_RMID, &buff);
	semctl(gfx->shm.semid, 0, IPC_RMID);
	return (0);
}
