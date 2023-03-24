#include <cstdint>

class Movable {
	public:
		uint64_t pos_x = 0;
		uint64_t pos_y = 10;

	public:
		void move_left() {
			pos_x--;
		}

		void move_right() {
			pos_x++;
		}
};