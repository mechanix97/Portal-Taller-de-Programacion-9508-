#ifndef OUTPUTFORMAT_H
#define OUTPUTFORMAT_H

#include <cstdio>
#include <string>
#include <stdexcept>
extern "C" {
    #include <libavformat/avformat.h>
    #include <libavcodec/avcodec.h>
    #include <libavutil/opt.h>
    #include <libswscale/swscale.h>
}

#include "../include/FormatContext.h"

class AVCodec;
class AVFrame;
class AVPacket;
class AVOutputFormat;
class AVStream;
class AVCodecContext;
class FormatContext;
class SwsContext;

class OutputFormat {
private: 
    uint32_t resx;
    uint32_t resy;
    FormatContext& context;
    AVOutputFormat* avOutputFormat;
    AVStream* video_avstream;
    AVCodecContext* codecContext;
    int currentPts;
    FILE* outputFile;
    AVFrame* frame;
    AVPacket* pkt;
public:
    explicit OutputFormat(FormatContext& context,const std::string& filename,uint32_t x, uint32_t y);
    ~OutputFormat();
    void writeFrame(const char* data, SwsContext* swsContext);
    void close();
private:
    void initFrame();
    void codecContextInit(AVCodec* codec);

};
#endif
