#ifndef DLM_PROVIDERS_MAGIC_H__
#define DLM_PROVIDERS_MAGIC_H__

#include <inttypes.h>

typedef uintptr_t magic_t;

#define DLM_MAGIC_CAST(magic) ((magic_t)(magic))

#define DLM_MAGIC_BASE_OFFSET 16
#define DLM_MAGIC_NUM_MASK ((DLM_MAGIC_CAST(1) << DLM_MAGIC_BASE_OFFSET) - 1)
#define DLM_MAGIC_BASE_MASK (~DLM_MAGIC_NUM_MASK)

#define DLM_MAGIC_BASE_EXTRACT(magic) \
	(DLM_MAGIC_CAST(magic) & DLM_MAGIC_BASE_MASK)
#define DLM_MAGIC_NUM_EXTRACT(magic) \
	(DLM_MAGIC_CAST(magic) & DLM_MAGIC_NUM_MASK)

#define DLM_MAGIC_BASE_CREATE(base) \
	(DLM_MAGIC_CAST(base) << DLM_MAGIC_BASE_OFFSET)
#define DLM_MAGIC_CREATE(base, num) \
	(DLM_MAGIC_BASE_EXTRACT(base) | DLM_MAGIC_NUM_EXTRACT(num))

#define DLM_MAGIC_BASE_CHECK(magic, base) \
	(DLM_MAGIC_BASE_EXTRACT(magic) == DLM_MAGIC_CAST(base))
#define DLM_MAGIC_NUM_CHECK(magic, num) \
	(DLM_MAGIC_NUM_EXTRACT(magic) == DLM_MAGIC_CAST(base))

#define DLM_MAGIC_UNDEFINED (DLM_MAGIC_BASE_CREATE(0xDEAD), 0B11)

/* memory */

#define DLM_MAGIC_MEM_BASE DLM_MAGIC_BASE_CREATE(0xDEE9)
#define DLM_MAGIC_IS_MEM(magic) \
	(DLM_MAGIC_BASE_EXTRACT(magic) == DLM_MAGIC_MEM_BASE)
#define DLM_MAGIC_MEM_CREATE(num) \
	DLM_MAGIC_CREATE(DLM_MAGIC_MEM_BASE, num)

#define DLM_MAGIC_MEM_VMS	DLM_MAGIC_MEM_CREATE(11)
#define DLM_MAGIC_MEM_OPENCL	DLM_MAGIC_MEM_CREATE(22)
#define DLM_MAGIC_MEM_IB	DLM_MAGIC_MEM_CREATE(33)

#endif /* DLM_PROVIDERS_MAGIC_H__ */
