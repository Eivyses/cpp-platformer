#include "Movable.cpp"
#include "asciilibur.hpp"

const static int64_t MAX_HEIGHT = 30;
const static int64_t MAX_WIDTH = 120;

class Boundaries : Movable {
	public:
		Boundaries(const asciilibur::FrameBuffer& buffer) : m_buffer(buffer) {}

	private:
		asciilibur::FrameBuffer m_buffer;

	public:
		void draw() {
			for (int i = 0; i < MAX_WIDTH - 1; i++) {
				m_buffer.draw('=', i, 0);
				m_buffer.draw('=', i, 1);
			}
			for (int i = 0; i < MAX_HEIGHT; i++) {
				m_buffer.draw('|', 0, i);
				m_buffer.draw('|', MAX_WIDTH - 1, i);
			}
		}
};