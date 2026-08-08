#include "core/core.h"
#include "gpu/gsp/gpu_instrumentation.h"

static struct GspMsgQueueInfo cached_info;
static int info_valid = 0;

void setGspMsgQueueInfo(const struct GspMsgQueueInfo *info) {
  cached_info = *info;
  info_valid = 1;
}

void setGspStagingBuffer(NvU64 kva, NvU64 isolated) {
  cached_info.staging_kva = kva;
  cached_info.staging_isolated = isolated;
}

void clearGspMsgQueueInfo(void) { info_valid = 0; }

const struct GspMsgQueueInfo *getGspMsgQueueInfo(void) {
  return info_valid ? &cached_info : NULL;
}
