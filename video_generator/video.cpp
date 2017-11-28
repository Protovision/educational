#include "video.h"

bool video_generator::video::is_open() const
{
	return ps_ != nullptr;
}

std::size_t video_generator::video::width() const
{
	return width_;
}

std::size_t video_generator::video::height() const
{
	return height_;
}

std::size_t video_generator::video::rate() const
{
	return rate_;
}

bool video_generator::video::open(const std::string& filename, std::size_t w,
						std::size_t h, std::size_t r)
{
	std::stringstream ss;

	ss << "ffmpeg -y -f rawvideo -pixel_format rgb24 " <<
		"-video_size " << w << "x" << h << " -r " << r << " "
		"-i - -pixel_format yuv420p -vcodec mpeg4 -an -q:v 5 " << filename;
	ps_ = portable_popen(ss.str(), "w");
	width_ = w;
	height_ = h;
	rate_ = r;
	return ps_ != nullptr;
}

void video_generator::video::close()
{
	portable_pclose(ps_);
	ps_ = nullptr;
}

video_generator::video& video_generator::operator<<(video& v,
				const frame& f)
{
	std::fwrite(f.data(), 1, f.width() * f.height() * 3, v.ps_);
	return v;
}
