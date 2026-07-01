#ifndef GPU_INSTRUMENTATION_KO_H
#define GPU_INSTRUMENTATION_KO_H

#include <linux/types.h>

struct GspMsgQueueInfo {
  u64 status_queue_iova;
  u64 status_queue_offset;
  u64 status_queue_size;
};

const struct GspMsgQueueInfo *getGspMsgQueueInfo(void);

#endif
