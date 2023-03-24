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
				{20, 27},
				{40, 27},
				{80, 27},

				{10, 25},
				{35, 25},
				{66, 25},
				{90, 25},
				{110, 25},

				{1, 23},
				{33, 23},
				{46, 23},
				{67, 23},
				{80, 23},
				{105, 23},

				{50, 21}
			};
		}
};