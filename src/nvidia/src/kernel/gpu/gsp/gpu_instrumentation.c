#include "core/core.h"
#include "gpu/gsp/gpu_instrumentation.h"

static struct GspMsgQueueInfo cached_info;
static int info_valid = 0;

void setGspMsgQueueInfo(const struct GspMsgQueueInfo *info) {
  cached_info = *info;
  info_valid = 1;
}

const struct GspMsgQueueInfo *getGspMsgQueueInfo(void) {
  if (!info_valid) {
    return NULL;
  }
  return &cached_info;
}
