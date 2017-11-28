#ifndef COMMON_TYPES_H
#define COMMON_TYPES_H
#include <cstdint>
#include <cstddef>

namespace video_generator {

	struct pixel {
		std::uint8_t red, green, blue;
	};

	struct coordinate {
		std::size_t row, column;
	};

	struct vector {
		double vertical, horizontal;
	};

	inline coordinate to_coordinate(const vector& v)
	{
		return coordinate{static_cast<std::size_t>(v.vertical),
				static_cast<std::size_t>(v.horizontal)};
	}

	inline vector to_vector(const coordinate& c)
	{
		return vector{static_cast<double>(c.row),
				static_cast<double>(c.column)};
	}
};

#endif
