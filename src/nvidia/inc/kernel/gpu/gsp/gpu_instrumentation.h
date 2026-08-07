#ifndef GPU_INSTRUMENTATION_H
#define GPU_INSTRUMENTATION_H

#include "nvtypes.h"

struct GspMsgQueueInfo {
  RmPhysAddr status_queue_iova;
  NvU64 status_queue_offset;
  NvU64 status_queue_size;
  NvU32 *rx_seq_num_addr;

  //
  // The shared buffer is allocated NV_MEMORY_NONCONTIGUOUS, so
  // status_queue_iova only names its *first* page - offsets past 0xfff resolve
  // to unrelated physical memory. Anything walking the ring must go through the
  // kernel mapping instead, which memdescMap makes virtually contiguous across
  // the whole buffer. Both queues live inside it at the offsets below.
  //
  NvU64 shared_mem_kva;
  NvU64 shared_mem_size;
  NvU64 cmd_queue_offset;
  NvU64 cmd_queue_size;
};

void setGspMsgQueueInfo(const struct GspMsgQueueInfo *info);
void clearGspMsgQueueInfo(void);
const struct GspMsgQueueInfo *getGspMsgQueueInfo(void);

#endif
