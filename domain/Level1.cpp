#pragma once

#include "asciilibur.hpp"
#include "Level.cpp"

class Level1: public Level {
	public:
		Level1(const asciilibur::FrameBuffer& buffer) : Level(buffer) {}

	public:
		void draw() {
			for (auto platform : getPlatforms()) {
				draw_platform(platform.first, platform.second);
			}

			m_buffer.draw('F', 54, 21);
		}

		std::vector<std::pair<uint64_t, uint64_t>> getPlatforms() {
			return {
				{20, 28},
				{40, 28},
				{80, 28},

				{10, 26},
				{35, 26},
				{66, 26},
				{90, 26},
				{110, 26},

				{1, 24},
				{33, 24},
				{46, 24},
				{67, 24},
				{80, 24},
				{105, 24},

				{50, 22}
			};
		}
};