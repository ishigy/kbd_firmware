/*
 * (C) 2020 Sadao Ikebe @bonyarou
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H
#include "key_duration.h"
#include <timer.h>

static keypress_timer_expired_func_t callback;
static uint16_t timer_id;
bool timer_started = false;

void keypress_timer_init(keypress_timer_expired_func_t _clbk) {
    callback = _clbk;
    // ここにタイマーをゼロにする処理がない！？
}
// keypress_timer_startが意味のない処理になっていたのが原因だった。
void keypress_timer_start(uint16_t count) {
    if(!timer_started) {
        timer_id = timer_read();
        timer_started = true;
    }
    if (timer_elapsed(timer_id) >= count) {
        timer_started = false;
        callback();
    }
}