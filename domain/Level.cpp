#pragma once

#include "asciilibur.hpp"
#include <vector>

class Level {
	public:
		Level(const asciilibur::FrameBuffer& buffer) : m_buffer(buffer) {}

	public:
		uint64_t PLATFORM_SIZE = 9;
		asciilibur::FrameBuffer m_buffer;

	public:
		void draw_platform(uint64_t pos_x, uint64_t pos_y) {
			for (int i = 0; i < PLATFORM_SIZE; i++) {
				m_buffer.draw('=', pos_x + i, pos_y);
			}
		}

		virtual void draw() {}
		virtual std::vector<std::pair<uint64_t, uint64_t>> getPlatforms() {
			throw "not implemented";
		}
};