/* @license
 * This file is part of the Game Closure SDK.
 *
 * The Game Closure SDK is free software: you can redistribute it and/or modify
 * it under the terms of the Mozilla Public License v. 2.0 as published by Mozilla.
 
 * The Game Closure SDK is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * Mozilla Public License v. 2.0 for more details.
 
 * You should have received a copy of the Mozilla Public License v. 2.0
 * along with the Game Closure SDK.  If not, see <http://mozilla.org/MPL/2.0/>.
 */

#ifndef CORE_TIMER_H
#define CORE_TIMER_H

#include "core/types.h"
#include "util/detect.h"

typedef struct core_timer_t {
	int time_left;
	int duration;
	int id;
	struct core_timer_t *next;
	struct core_timer_t *prev;
	bool repeat;
	bool cleared;
	void *js_data;
} core_timer;


#ifdef __cplusplus
extern "C" {
#endif

void core_timer_tick(int dt);
void core_timer_clear_all();
void core_timer_clear(int timerId);
void core_timer_schedule(core_timer *timer);
core_timer *core_get_timer(void *js_data, int time, bool repeat);

void js_timer_fire(core_timer *timer);
void js_timer_unlink(core_timer *t);

#ifdef __cplusplus
}
#endif

#endif //CORE_TIMER_H
