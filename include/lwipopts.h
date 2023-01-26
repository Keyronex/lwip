#ifndef LWIPOPTS_H_
#define LWIPOPTS_H_

#include <errno.h>
#include <nanokern/thread.h>

#undef errno
#define errno curcpu()->running_thread->errno

#if 0
#define LWIP_DEBUG 1
#define TCP_DEBUG                       LWIP_DBG_ON
#define ETHARP_DEBUG                    LWIP_DBG_ON
//#define PBUF_DEBUG                      LWIP_DBG_ON
#define IP_DEBUG                        LWIP_DBG_ON
#define TCPIP_DEBUG                     LWIP_DBG_ON
#define DHCP_DEBUG                      LWIP_DBG_ON
#define UDP_DEBUG                       LWIP_DBG_ON
#endif

#define LWIP_DHCP 1
#define LWIP_DNS 1
#define LWIP_SOCKET 1
#define LWIP_TIMEVAL_PRIVATE 0

#define LWIP_NETIF_API 1
#define TCPIP_MBOX_SIZE 32

#endif /* LWIPOPTS_H_ */
