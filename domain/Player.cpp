#include "Movable.cpp"
#include "asciilibur.hpp"

class Player : Movable {
	public:
		Player(const asciilibur::FrameBuffer& buffer) :
			m_buffer(buffer) {}

	private:
		asciilibur::FrameBuffer m_buffer;

	public:
		void draw(std::vector<std::pair<uint64_t, uint64_t>>& platforms, const Config& config) {
			update_jump(platforms, config);
			m_buffer.draw('@', pos_x, pos_y);
		}
		void move_left(std::vector<std::pair<uint64_t, uint64_t>>& platforms) {
			Movable::move_left(platforms);
		}
		void move_right(std::vector<std::pair<uint64_t, uint64_t>>& platforms) {
			Movable::move_right(platforms);
		}

		void jump() {
			Movable::jump();
		}

		uint64_t get_pos_x() {
			return pos_x;
		}

		uint64_t get_pos_y() {
			return pos_y;
		}
};