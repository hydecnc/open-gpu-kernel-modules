#ifndef GPU_INSTRUMENTATION_KO_H
#define GPU_INSTRUMENTATION_KO_H

// Must mirror struct GspMsgQueueInfo in
// src/nvidia/inc/kernel/gpu/gsp/gpu_instrumentation.h.
struct GspMsgQueueInfo {
  u64 shared_mem_kva;
  u64 shared_mem_size;
  u64 cmd_queue_offset;
  u64 cmd_queue_size;
  u64 status_queue_offset;
  u64 status_queue_size;
};

const struct GspMsgQueueInfo *getGspMsgQueueInfo(void);

#endif
