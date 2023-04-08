#ifndef KRX_INCLUDE_LWIPOPTS_H
#define KRX_INCLUDE_LWIPOPTS_H

#include <abi-bits/errno.h>
#include <kdk/kernel.h>
#include <bsdqueue/queue.h>

#undef errno
#define errno curcpu()->running_thread->errno

#if 1
#define LWIP_DEBUG 1
#define TCP_DEBUG                       LWIP_DBG_ON
//#define ETHARP_DEBUG                    LWIP_DBG_ON
//#define PBUF_DEBUG                      LWIP_DBG_ON
//#define IP_DEBUG                        LWIP_DBG_ON
//#define TCPIP_DEBUG                     LWIP_DBG_ON
//#define DHCP_DEBUG                      LWIP_DBG_ON
//#define UDP_DEBUG                       LWIP_DBG_ON
#endif

/*! We chain pbufs in ethernet device output queues. */
#define LWIP_PBUF_CUSTOM_DATA STAILQ_ENTRY(pbuf) stailq_entry;

#define LWIP_NETIF_API 1
#define LWIP_SOCKET 0

#define LWIP_TIMERS 1

#define TCPIP_MBOX_SIZE 256

#if 0
#define LWIP_DHCP 1
#define LWIP_DNS 1
#define LWIP_SOCKET 1

#define LWIP_NETIF_API 1
#endif

#endif /* KRX_INCLUDE_LWIPOPTS_H */
