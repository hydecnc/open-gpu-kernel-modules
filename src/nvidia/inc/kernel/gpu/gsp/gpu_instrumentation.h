#ifndef GPU_INSTRUMENTATION_H
#define GPU_INSTRUMENTATION_H

#include "nvtypes.h"

struct GspMsgQueueInfo {
  RmPhysAddr status_queue_iova;
  NvU64 status_queue_offset;
  NvU64 status_queue_size;
  NvU32 *rx_seq_num_addr;
};

void setGspMsgQueueInfo(const struct GspMsgQueueInfo *info);
void clearGspMsgQueueInfo(void);
const struct GspMsgQueueInfo *getGspMsgQueueInfo(void);

#endif
