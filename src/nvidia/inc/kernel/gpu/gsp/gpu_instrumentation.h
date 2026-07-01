#ifndef GPU_INSTRUMENTATION_H
#define GPU_INSTRUMENTATION_H

#include "nvtypes.h"

struct GspMsgQueueInfo {
  RmPhysAddr status_queue_iova;
  NvU64 status_queue_offset;
  NvU64 status_queue_size;
};

void setGspMsgQueueInfo(const struct GspMsgQueueInfo *info);
const struct GspMsgQueueInfo *getGspMsgQueueInfo(void);

#endif
