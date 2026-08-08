#ifndef GPU_INSTRUMENTATION_KO_H
#define GPU_INSTRUMENTATION_KO_H

// Must mirror struct GspMsgQueueInfo in
// src/nvidia/inc/kernel/gpu/gsp/gpu_instrumentation.h.
struct GspMsgQueueInfo {
  u64 status_queue_offset;
  u64 status_queue_size;
  u32 *rx_seq_num_addr;
  u64 shared_mem_kva;
  u64 shared_mem_size;
  u64 cmd_queue_offset;
  u64 cmd_queue_size;
  u64 staging_kva;
  u64 staging_isolated;
};

const struct GspMsgQueueInfo *getGspMsgQueueInfo(void);

#endif
