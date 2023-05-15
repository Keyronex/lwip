#ifndef ARCH_SYS_ARCH_H
#define ARCH_SYS_ARCH_H

#include <stdbool.h>
#include <stdint.h>

#include "kdk/kernel.h"
#include "kdk/process.h"

#ifdef __cplusplus
extern "C" {
#endif

#define SYS_ARCH_PROTECT(x) ipl_##x = ke_spinlock_acquire(&x);
#define SYS_ARCH_UNPROTECT(x) ke_spinlock_release(&x, ipl_##x)
/* is this right? */
#define SYS_ARCH_DECL_PROTECT(x) static kspinlock_t x = KSPINLOCK_INITIALISER; static ipl_t ipl_##x;

typedef ksemaphore_t sys_sem_t;
typedef kmutex_t     sys_mutex_t;
typedef kmsgqueue_t  sys_mbox_t;
typedef ethread_t   *sys_thread_t;

/* todo lmao */
#define LWIP_RAND() (0xdeadbeef)

#ifdef __cplusplus
}
#endif

#endif /* ARCH_SYS_ARCH_H */
