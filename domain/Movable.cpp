#pragma once

#include <cstdint>
#include <vector>


const uint64_t MAX_JUMP_TIME = 2;

class Movable {
	public:
		uint64_t pos_x = 1;
		uint64_t pos_y = 28;

	private:
		uint64_t jump_time = 0;
		bool is_jumping = false;
		bool is_falling = false;

	private:
		bool has_floor(std::vector<std::pair<uint64_t, uint64_t>>& platforms) {
			bool has_floor = false;
			auto next_fall_pos = pos_y + 1;
			for (auto& platform : platforms) {
				if (pos_x >= platform.first &&
					pos_x <= platform.first + 9 &&
					next_fall_pos == platform.second) {
					has_floor = true;
					break;
				}
			}
			return has_floor;
		}

	public:
		void move_left(std::vector<std::pair<uint64_t, uint64_t>>& platforms) {
			auto nextPos = pos_x - 1;
			if (nextPos <= 0) {
				return;
			}
			pos_x--;
			if (!has_floor(platforms) && pos_y < 28 && !is_jumping) {
				is_falling = true;
				jump_time = 0;
			}
		}

		void move_right(std::vector<std::pair<uint64_t, uint64_t>>& platforms) {
			auto nextPos = pos_x + 1;
			if (nextPos >= 119) {
				return;
			}
			pos_x++;
			if (!has_floor(platforms) && pos_y < 28 && !is_jumping) {
				is_falling = true;
				jump_time = 0;
			}
		}

		void update_jump(std::vector<std::pair<uint64_t, uint64_t>>& platforms) {
			if (!is_jumping && !is_falling) {
				return;
			}
			if (is_jumping) {
				if (jump_time > MAX_JUMP_TIME) {
					is_jumping = false;
					is_falling = true;
					jump_time = 0;
				}
				else {
					pos_y--;
					jump_time++;
				}
			}
			if (is_falling) {
				bool has_floor = false;
				auto next_fall_pos = pos_y + 1;
				for (auto& platform : platforms) {
					if (pos_x >= platform.first && 
						pos_x <= platform.first + 9 &&
						next_fall_pos == platform.second) {
						has_floor = true;
						break;
					}
				}
				if (has_floor || next_fall_pos == 29) {
					is_falling = false;
					return;
				}

				pos_y++;
			}
		}

		void jump() {
			if (is_jumping || is_falling) {
				return;
			}
			is_jumping = true;
		}
};