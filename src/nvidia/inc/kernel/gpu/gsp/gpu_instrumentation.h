/**
 * kernel-open/nvidia/gpu_instrumentation.h must contain an identical definition
 * of GspMsgQueueInfo through manual intervention.
 */
#ifndef GPU_INSTRUMENTATION_H
#define GPU_INSTRUMENTATION_H

#include "nvtypes.h"

struct GspMsgQueueInfo {
  //
  // The shared buffer: page table, then command queue, then status queue. It is
  // allocated NV_MEMORY_NONCONTIGUOUS, which is why no physical address appears
  // here - a physical base names only the first page, and offsets past 0xfff
  // resolve to unrelated memory. memdescMap gives the whole buffer one
  // virtually contiguous kernel mapping, so shared_mem_kva is the only base
  // that indexes correctly. This is also the only region the GPU can reach by
  // DMA.
  //
  NvU64 shared_mem_kva;
  NvU64 shared_mem_size;

  //
  // Offsets within the shared buffer. cmd_queue_offset is not just layout: with
  // MSGQ_FLAGS_SWAP_RX the driver publishes its *status* queue read cursor into
  // the command queue, so rxReadPtr lives at cmd_queue_offset + rxHdrOff.
  //
  NvU64 cmd_queue_offset;
  NvU64 cmd_queue_size;
  NvU64 status_queue_offset;
  NvU64 status_queue_size;

  // Live pointer: dereferenced on each procfs read, not a snapshot.
  NvU32 *rx_seq_num_addr;

  //
  // pCmdQueueElement, the staging buffer the elemCount overflow lands in. Plain
  // kernel heap - not part of the shared buffer and not reachable by GPU DMA;
  // the overflow is precisely how GPU-controlled bytes escape into it.
  //
  // staging_kva + staging_size is the first out-of-bounds byte, i.e. the
  // address a KASAN report should name. Whether KASAN can see it at all depends
  // on where the buffer came from: a kmalloc'd one carries a redzone, a
  // vmalloc'd one only under CONFIG_KASAN_VMALLOC, and an embedded one
  // (staging_isolated == 0) has pMetaData sitting in-bounds right behind it, so
  // there is nothing to hit.
  //
  NvU64 staging_kva;
  NvU64 staging_size;
  NvU64 staging_isolated;
};

void setGspMsgQueueInfo(const struct GspMsgQueueInfo *info);
void setGspStagingBuffer(NvU64 kva, NvU64 size, NvU64 isolated);
void clearGspMsgQueueInfo(void);
const struct GspMsgQueueInfo *getGspMsgQueueInfo(void);

#endif
