#include "Movable.cpp"
#include "asciilibur.hpp"

class Player : Movable {
	public:
		Player(const asciilibur::FrameBuffer& buffer) :
			m_buffer(buffer) {}

	private:
		asciilibur::FrameBuffer m_buffer;

	public:
		void draw() {
			update_jump();
			m_buffer.draw('@', pos_x, pos_y);
		}
		void move_left() {
			Movable::move_left();
		}
		void move_right() {
			Movable::move_right();
		}

		void jump() {
			Movable::jump();
		}
};