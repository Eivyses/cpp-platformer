﻿
#include <windows.h>
#include <cstdint>

#include "asciilibur.hpp"
#include "domain/Player.cpp"

constexpr const uint8_t k_width = 120;
constexpr const uint8_t k_height = 30;

bool on_update(double delta_time, Player& player) {
    // TODO: defined cross-platform keycodes
    if (asciilibur::input::get_key_state(VK_ESCAPE)) {
        // Quit game
        return false;
    } else if (asciilibur::input::get_key_state(VK_LEFT)) {
        player.move_left();
    } else if (asciilibur::input::get_key_state(VK_RIGHT)) {
        player.move_right();
    }

    // ---- Game logic here ----

    // Conitue running game
    return true;
}

void on_draw(asciilibur::FrameBuffer& buffer, uint64_t pos, Player& player) {
    // Draw something into the frame buffer
    buffer.clear_buffer();
    // buffer.draw(asciilibur::Char::SMILE_DARK, pos, 10);
    // buffer.draw(asciilibur::Char::SMILE_LIGHT, 11, 10);
    player.draw();
}

int main() {
    asciilibur::FrameBuffer buffer(k_width, k_height);
    Player player(buffer);

    bool should_run = true;
    uint64_t last_time = asciilibur::time::get_time();
    uint64_t base_pos = 10;

    while (should_run) {
        // Get delta time
        uint64_t time_now = asciilibur::time::get_time();
        uint64_t diff = time_now - last_time;
        double delta_time = static_cast<double>(time_now - last_time) / 1000.0f;
        last_time = time_now;

        // Update game
        should_run = on_update(delta_time, player);

        // Draw things into the buffer
        on_draw(buffer, base_pos, player);

        if (++base_pos >= k_width) {
            base_pos = 0;
        }

        // Render buffer to screen
        buffer.render_buffer();
    }
}
