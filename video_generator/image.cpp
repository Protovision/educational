#include "image.h"

bool video_generator::image::is_open() const
{
	return !data_.empty();
}

std::size_t video_generator::image::width() const
{
	return width_;
}

std::size_t video_generator::image::height() const
{
	return height_;	
}

const unsigned char* video_generator::image::data() const
{
	return data_.data();
}

void video_generator::image::draw(frame& f, const coordinate& c) const
{
	coordinate source, dest;

	source = { 0, 0 };
	dest = c;
	while (source.row != height()) {
		while (source.column != width()) {
			f[dest] = (*this)[source];
			++source.column;
			++dest.column;
		}
		source.column = 0;
		dest.column -= width();
		++source.row;
		++dest.row;
	}
}

bool video_generator::image::open(const std::string& filename, std::size_t w, 
								std::size_t h)
{
	std::stringstream ss;
	FILE* f;
	int ch;

	ss << "ffmpeg -i " << filename << " -f rawvideo -pix_fmt rgb24" <<
		" -vf scale=" << w << ':' << h << " - ";
	f = portable_popen(ss.str(), "r");
	if (!f) return false;
	while ((ch = fgetc(f)) != EOF) data_.push_back(ch);
	portable_pclose(f);
	width_ = w;
	height_ = h;
	return true;
}

void video_generator::image::close()
{
	data_.clear();
	data_.shrink_to_fit();
}

const video_generator::pixel& video_generator::image::operator[](
						const coordinate& c) const
{
	return *(reinterpret_cast<const pixel*>(data_.data() +
					(c.row * width() + c.column) * 3));
}

