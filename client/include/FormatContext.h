#ifndef FORMATCONTEXT_H
#define FORMATCONTEXT_H
#include <string>
#include <stdexcept>
extern "C" {
#include <libavformat/avformat.h>
}

class AVFormatContext;
class FormatContext {
public:
    FormatContext();
    ~FormatContext();
    AVFormatContext* getContext() const;
private:
    AVFormatContext *pFormatCtx;
};
#endif
