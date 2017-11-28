#ifndef FRAME_H
#define FRAME_H
#include "common_types.h"
#include <vector>
#include <cstring>

namespace video_generator {

	class frame {
	public:
		std::size_t width() const;
		std::size_t height() const;
		const unsigned char* data() const;

		void clear(const pixel& p);
		void dimensions(std::size_t w, std::size_t h);

		const pixel& operator[](const coordinate& c) const;
		pixel& operator[](const coordinate& c);
	private:
		std::size_t width_, height_;
		std::vector<unsigned char> data_;
	};

}

#endif
