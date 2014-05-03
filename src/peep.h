/*****************************************************************************
 * Copyright (c) 2014 Ted John, Peter Hill
 * OpenRCT2, an open source clone of Roller Coaster Tycoon 2.
 *
 * This file is part of OpenRCT2.
 *
 * OpenRCT2 is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.

 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *****************************************************************************/

#ifndef _PEEP_H_
#define _PEEP_H_

#include "rct2.h"

#define PEEP_MAX_THOUGHTS 5

enum PEEP_TYPE {
	PEEP_TYPE_GUEST,
	PEEP_TYPE_STAFF
};

enum STAFF_TYPE {
	STAFF_TYPE_HANDYMAN,
	STAFF_TYPE_MECHANIC,
	STAFF_TYPE_SECURITY,
	STAFF_TYPE_ENTERTAINER
};

enum PEEP_THOUGHT_TYPE {
	PEEP_THOUGHT_TYPE_NONE = 255
};

enum PEEP_STATE {
	PEEP_STATE_QUEUING_FRONT = 2,
	PEEP_STATE_ON_RIDE = 3,
	PEEP_STATE_LEAVING_RIDE = 4,
	PEEP_STATE_WALKING = 5,
	PEEP_STATE_QUEUING = 6,
	PEEP_STATE_ENTERING_RIDE = 7,
	PEEP_STATE_SITTING = 8,
	PEEP_STATE_PICKED = 9,
	PEEP_STATE_PATROLLING = 10, // Not sure
	PEEP_STATE_MOPING = 11,
	PEEP_STATE_SWEEPING = 12,
	PEEP_STATE_ENTERING_PARK = 13,
	PEEP_STATE_LEAVING_PARK = 14,
	PEEP_STATE_ANSWERING = 15,
	PEEP_STATE_FIXING = 16,
	PEEP_STATE_BUYING = 17,
	PEEP_STATE_WATCHING = 18,
	PEEP_STATE_EMPTYING_BIN = 19,
	
	PEEP_STATE_WATERING = 21,
	PEEP_STATE_HEADING_TO_INSPECTION = 22,
	PEEP_STATE_INSPECTING = 23
};

enum PEEP_FLAGS {
	PEEP_FLAGS_LEAVING_PARK = (1 << 0),
	PEEP_FLAGS_SLOW_WALK = (1 << 1),

	PEEP_FLAGS_TRACKING = (1 << 3),
	PEEP_FLAGS_WAVING = (1 << 4), // Makes the peep wave

	PEEP_FLAGS_PHOTO = (1 << 6), // Makes the peep take a picture
	PEEP_FLAGS_PAINTING = (1 << 7), 

	PEEP_FLAGS_LITTER = (1 << 9), // Makes the peep throw litter
	PEEP_FLAGS_LOST = (1 << 10), // Makes the peep feel lost (animation trigerred)
	PEEP_FLAGS_HUNGER = (1 << 11), // Makes the peep become hungry quicker
	PEEP_FLAGS_BATHROOM = (1 << 12), // Makes the peep want to go to the bathroom
	PEEP_FLAGS_CROWDED = (1 << 13), // The peep will start feeling crowded

	PEEP_FLAGS_NAUSEA = (1 << 15), // Makes the peep feel sick (e.g. after an extreme ride)

	PEEP_FLAGS_EATING = (1 << 17), // Reduces hunger
	PEEP_FLAGS_EXPLODE = (1 << 18),

	PEEP_FLAGS_JOY = (1 << 23), // Makes the peep jump in joy
	PEEP_FLAGS_ANGRY = (1 << 24),
	PEEP_FLAGS_ICE_CREAM = (1 << 25) // Unconfirmed
};

typedef struct {
	uint8 type;
	uint8 item;
	uint8 pad_3;
	uint8 pad_4;
} rct_peep_thought;

typedef struct {
	uint8 sprite_identifier;		// 0x00
	uint8 pad_01;
	uint16 pad_02;
	uint16 next;					// 0x04
	uint16 pad_06;
	uint8 var_08;
	uint8 pad_09;
	sint16 var_0A;
	uint16 var_0C;
	sint16 x;						// 0x0E
	sint16 y;						// 0x10
	sint16 z;						// 0x12
	uint8 pad_14[0x09];
	uint8 direction;				// 0x1D
	uint32 pad_1E;
	uint16 name_string_idx;			// 0x22
	uint16 next_x;					// 0x24
	uint16 next_y;					// 0x26
	uint16 next_z;					// 0x28
	uint8 var_2A;
	uint8 state;					// 0x2B
	uint8 pad_2C;
	uint8 sprite_type;				// 0x2D
	uint8 type;						// 0x2E
	uint8 staff_type;				// 0x2F
	uint8 tshirt_colour;			// 0x30
	uint8 trousers_colour;			// 0x31
	uint8 pad_32[0x06];
	uint8 energy;					// 0x38
	uint8 energy_growth_rate;		// 0x39
	uint8 happiness;				// 0x3A
	uint8 happiness_growth_rate;	// 0x3B
	uint8 nausea;					// 0x3C
	uint8 nausea_growth_rate;		// 0x3D
	uint8 hunger;					// 0x3E
	uint8 thirst;					// 0x3F
	uint8 bathroom;					// 0x40
	uint8 pad_041[0x27];
	uint8 current_ride;				// 0x68
	uint8 pad_69;
	uint8 current_train;   	        // 0x6A
	uint8 current_car;				// 0x6B
	uint8 current_seat;				// 0x6C
	uint8 pad_6D[0x0F];
	uint8 rides_been_on[32];		// 0x7C
	uint32 id;						// 0x9C
	sint32 cash_in_pocket;			// 0xA0
	sint32 cash_spent;				// 0xA4
	uint8 pad_A8[8];
	rct_peep_thought thoughts[PEEP_MAX_THOUGHTS];	// 0xB0
	uint16 pad_C4;
	uint8 var_C6;
	uint8 pad_C7;
	uint32 flags;					// 0xC8
	uint8 var_CC;					
	uint8 pad_CD[0x17];
	uint16 paid_to_enter;			// 0xE4
	uint16 paid_on_rides;			// 0xE6
	uint16 paid_on_food;			// 0xE8
	uint16 paid_on_souvenirs;		// 0xEA
	uint8 no_of_food;				// 0xEC
	uint8 no_of_drinks;				// 0xED
	uint8 no_of_souvenirs;			// 0xEE
	uint8 pad_EF[0x07];
	uint8 balloon_colour;			// 0xF6
	uint8 umbrella_colour;			// 0xF7
	uint8 hat_colour;				// 0xF8
	uint8 favourite_ride;			// 0xF9
} rct_peep;

int peep_get_staff_count();
void peep_update_all();

#endif
