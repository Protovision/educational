#ifndef VIDEO_H
#define VIDEO_H
#include "frame.h"
#include "portable_popen.h"
#include <cstdio>
#include <sstream>

namespace video_generator {

	class video {
	friend video& operator<<(video& v, const frame& f);
	public:
		bool is_open() const;
		std::size_t width() const;
		std::size_t height() const;
		std::size_t rate() const;

		bool open(const std::string& filename, std::size_t w,
					std::size_t h, std::size_t r); 
		void close();
	private:
		std::size_t width_, height_, rate_;
		FILE* ps_;
	};

	video& operator<<(video& v, const frame& f);
}

#endif
