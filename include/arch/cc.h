#ifndef CC_H_
#define CC_H_

#include <sys/time.h>

#include <libkern/libkern.h>

#include <inttypes.h>
#include <limits.h>

#ifdef __cplusplus
extern "C" {
#endif

#ifndef BYTE_ORDER
#if __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__
#define BYTE_ORDER (LITTLE_ENDIAN)
#elif __BYTE_ORDER__ == __ORDER_BIG_ENDIAN__
#define BYTE_ORDER (BIG_ENDIAN)
#else
#error "Byte order is neither little nor big!"
#endif
#endif

#define X8_F "02" PRIx8
#define U16_F PRIu16
#define S16_F PRId16
#define X16_F PRIx16
#define U32_F PRIu32
#define S32_F PRId32
#define X32_F PRIx32

#define SZT_F PRIuPTR
#define PACK_STRUCT_FIELD(x) x
#define PACK_STRUCT_STRUCT __attribute__((packed))
#define PACK_STRUCT_BEGIN
#define PACK_STRUCT_END

#define LWIP_PLATFORM_DIAG(x) kprintf x
#ifdef NDEBUG
#define LWIP_PLATFORM_ASSERT(x)
#else
#define LWIP_PLATFORM_ASSERT(x)                                            \
	do {                                                               \
		kprintf("Assertion \"%s\" failed at %s:%d\n", x, __FILE__, \
		    __LINE__);                                             \
		kfatal("fatal in lwip");                                   \
	} while (0)
#endif
#ifdef __cplusplus
}
#endif

#endif /* CC_H_ */
