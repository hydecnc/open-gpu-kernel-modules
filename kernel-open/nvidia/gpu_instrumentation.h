#ifndef GPU_INSTRUMENTATION_KO_H
#define GPU_INSTRUMENTATION_KO_H

struct GspMsgQueueInfo {
  u64 status_queue_iova;
  u64 status_queue_offset;
  u64 status_queue_size;
  u32 *rx_seq_num_addr;
};

const struct GspMsgQueueInfo *getGspMsgQueueInfo(void);

#endif
