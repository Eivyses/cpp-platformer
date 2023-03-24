#pragma once

#include <cstdint>


const uint64_t MAX_JUMP_TIME = 2;

class Movable {
	public:
		uint64_t pos_x = 1;
		uint64_t pos_y = 29;

	private:
		uint64_t jump_time = 0;
		bool is_jumping = false;
		bool is_falling = false;

	public:
		void move_left() {
			auto nextPos = pos_x - 1;
			if (nextPos <= 0) {
				return;
			}
			pos_x--;
		}

		void move_right() {
			auto nextPos = pos_x + 1;
			if (nextPos >= 119) {
				return;
			}
			pos_x++;
		}

		void update_jump() {
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
				if (jump_time > MAX_JUMP_TIME) {
					is_falling = false;
					jump_time = 0;
				}
				else {
					pos_y++;
					jump_time++;
				}
			}
		}

		void jump() {
			if (is_jumping || is_falling) {
				return;
			}
			is_jumping = true;
		}
};