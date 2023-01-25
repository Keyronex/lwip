#ifndef ARCH_SYS_ARCH_H
#define ARCH_SYS_ARCH_H

#include <nanokern/thread.h>
#include <stdbool.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/* can we do spl here instead? */

#define SYS_ARCH_PROTECT(x) nk_wait(&x, "lwip_arch_rprotect", false, false, -1)
#define SYS_ARCH_UNPROTECT(x) nk_mutex_release(&x)
/* is this right? */
#define SYS_ARCH_DECL_PROTECT(x) static kmutex_t x = KMUTEX_INITIALIZER(x);

typedef ksemaphore_t sys_sem_t;
typedef kmutex_t     sys_mutex_t;
typedef kmsgqueue_t  sys_mbox_t;
typedef kthread_t   *sys_thread_t;

/* todo lmao */
#define LWIP_RAND() (0xdeadbeef)

#ifdef __cplusplus
}
#endif

#endif /* ARCH_SYS_ARCH_H */
