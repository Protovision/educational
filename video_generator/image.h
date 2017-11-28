#ifndef IMAGE_H
#define IMAGE_H
#include "common_types.h"
#include "portable_popen.h"
#include "frame.h"
#include <cstddef>
#include <cstdio>
#include <string>
#include <vector>
#include <sstream>

namespace video_generator {

	class image {
	public:
		bool is_open() const;
		std::size_t width() const;
		std::size_t height() const;
		const unsigned char* data() const;
		void draw(frame& f, const coordinate& c) const;

		bool open(const std::string& filename, std::size_t w,
							std::size_t h);
		void close();

		const pixel& operator[](const coordinate& c) const;
	private:
		std::size_t width_, height_;
		std::vector<unsigned char> data_;
	};

}

#endif
