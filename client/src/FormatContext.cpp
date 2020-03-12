#include "../include/FormatContext.h"

FormatContext::FormatContext() {
    this->pFormatCtx = avformat_alloc_context();
}

FormatContext::~FormatContext() {
    avformat_free_context(this->pFormatCtx);
}

AVFormatContext * FormatContext::getContext() const {
    return this->pFormatCtx;
}
