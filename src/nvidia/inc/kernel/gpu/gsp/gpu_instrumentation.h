#ifndef GPU_INSTRUMENTATION_H
#define GPU_INSTRUMENTATION_H

#include "nvtypes.h"

struct GspMsgQueueInfo {
  NvU64 status_queue_offset;
  NvU64 status_queue_size;
  NvU32 *rx_seq_num_addr;

  //
  // The shared buffer is allocated NV_MEMORY_NONCONTIGUOUS, which is why no
  // physical address is exported here: any physical base names only the first
  // page, and offsets past 0xfff resolve to unrelated memory. memdescMap gives
  // the whole buffer one virtually contiguous kernel mapping, so shared_mem_kva
  // is the only address that indexes correctly. Both queues live inside it at
  // the offsets below.
  //
  NvU64 shared_mem_kva;
  NvU64 shared_mem_size;
  NvU64 cmd_queue_offset;
  NvU64 cmd_queue_size;

  //
  // pCmdQueueElement, the staging buffer the elemCount overflow lands in. Its
  // size is always GSP_MSG_QUEUE_ELEMENT_SIZE_MAX; what varies, and what decides
  // whether KASAN can see the overrun, is where it came from. A kmalloc'd buffer
  // carries a redzone, a vmalloc'd one only does under CONFIG_KASAN_VMALLOC, and
  // an embedded one (staging_isolated == 0) has pMetaData sitting in-bounds right
  // behind it, so there is nothing to hit.
  //
  NvU64 staging_kva;
  NvU64 staging_isolated;
};

void setGspMsgQueueInfo(const struct GspMsgQueueInfo *info);
void setGspStagingBuffer(NvU64 kva, NvU64 isolated);
void clearGspMsgQueueInfo(void);
const struct GspMsgQueueInfo *getGspMsgQueueInfo(void);

#endif
