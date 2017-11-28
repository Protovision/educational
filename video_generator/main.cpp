#include "video.h"
#include "image.h"
#include <iostream>

int main(int argc, char* argv[])
{
	const std::string image_filename = "input.png";
	const std::size_t image_width = 100;
	const std::size_t image_height = 100;
	const std::string video_filename = "output.mp4";
	const std::size_t video_width = 720;
	const std::size_t video_height = 480;
	const std::size_t video_rate = 60;
	const std::size_t video_duration = 9;

	video_generator::video video;
	video_generator::frame frame;
	video_generator::image image;
	video_generator::vector position = { 0.0, 0.0 };
	const std::size_t frame_count = video_rate * video_duration;

	image.open(image_filename, image_width, image_height);
	frame.dimensions(video_width, video_height);
	video.open(video_filename, video_width, video_height, video_rate);
	for (std::size_t frame_number = 0; frame_number != frame_count;
							++frame_number) {
		frame.clear({0, 0, 0});
		image.draw(frame, video_generator::to_coordinate(position));
		video << frame;
		position.vertical += static_cast<double>(video.height() -
					image.height()) / frame_count;
		position.horizontal += static_cast<double>(video.width() -
						image.width()) / frame_count;
	}
	video.close();
	image.close();
		

}
