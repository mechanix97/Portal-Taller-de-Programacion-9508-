#ifndef _VIDEO_RECORDER_H_
#define _VIDEO_RECORDER_H_

#include <SDL2/SDL.h>
#include <stdexcept>
#include <sstream>
#include <iomanip>
#include <ctime>
#include <vector>
#include <string>
extern "C" {
#include <libavformat/avformat.h>
#include <libswscale/swscale.h>
}
#include "../../common/include/thread.h"
#include "../../common/include/protected_queue.h"
#include "../include/SdlWindow.h"
#include "../include/SdlTexture.h"
#include "../include/FormatContext.h"
#include "../include/OutputFormat.h"

class VideoRecorder : public Thread{
	bool recording,running,stoping;
	uint32_t bufferWidth;
    uint32_t bufferHeight;
    uint32_t frameCount;
    ProtectedQueue<std::vector<char>*> frames;
	FormatContext context;
    OutputFormat* videoOutput;
    SwsContext * ctx;
public:
	VideoRecorder();
	~VideoRecorder();
	virtual void run() override;
    void stop();
	void startRecording(uint32_t width, uint32_t height);
	void recordFrame(SDL_Renderer* renderer);
	void stopRecording();
	void checkResolution(uint32_t width, uint32_t height);
	std::string generateName();
	bool isRecording() const;
};

#endif
