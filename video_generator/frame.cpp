#include "frame.h"

std::size_t video_generator::frame::width() const
{
	return width_;
}

std::size_t video_generator::frame::height() const
{
	return height_;
}

const unsigned char* video_generator::frame::data() const
{
	return data_.data();
}

void video_generator::frame::clear(const pixel& p)
{
	std::size_t i = 0;

	while (i != width() * height() * 3) {
		data_[i++] = p.red;
		data_[i++] = p.green;
		data_[i++] = p.blue;
	}
}

void video_generator::frame::dimensions(std::size_t w, std::size_t h)
{
	data_.resize(w * h * 3);
	width_ = w;
	height_ = h;
}

const video_generator::pixel& video_generator::frame::operator[](
					const coordinate& c) const
{
	return *(reinterpret_cast<const video_generator::pixel*>(data_.data() +
					(c.row * width() + c.column) * 3));
}


video_generator::pixel& video_generator::frame::operator[](
					const coordinate& c)
{
	return *reinterpret_cast<video_generator::pixel*>(data_.data() +
					(c.row * width() + c.column) * 3);
}
