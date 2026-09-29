/**
 * kernel-open/nvidia/gpu_instrumentation.h must contain an identical definition
 * of GspMsgQueueInfo through manual intervention.
 */
#ifndef GPU_INSTRUMENTATION_H
#define GPU_INSTRUMENTATION_H

#include "nvtypes.h"

struct GspMsgQueueInfo {
  NvU64 shared_mem_kva;
  NvU64 shared_mem_size;
  NvU64 cmd_queue_offset;
  NvU64 cmd_queue_size;
  NvU64 status_queue_offset;
  NvU64 status_queue_size;
};

void setGspMsgQueueInfo(const struct GspMsgQueueInfo *info);
void clearGspMsgQueueInfo(void);
const struct GspMsgQueueInfo *getGspMsgQueueInfo(void);

#endif
