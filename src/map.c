/*****************************************************************************
 * Copyright (c) 2014 Ted John
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

#include "addresses.h"
#include "climate.h"
#include "date.h"
#include "map.h"

#define GET_MAP_ELEMENT(x) (&(RCT2_ADDRESS(RCT2_ADDRESS_MAP_ELEMENTS, rct_map_element)[x]))
#define TILE_MAP_ELEMENT_POINTER(x) (RCT2_ADDRESS(RCT2_ADDRESS_TILE_MAP_ELEMENT_POINTERS, rct_map_element*)[x])

static void tiles_init();

/**
 * 
 *  rct2: 0x0068AB4C
 */
void map_init()
{
	int i;
	rct_map_element *map_element;

	date_reset();
	RCT2_GLOBAL(0x0138B580, sint16) = 0;
	RCT2_GLOBAL(0x010E63B8, sint32) = 0;

	for (i = 0; i < MAX_TILE_MAP_ELEMENT_POINTERS; i++) {
		map_element = GET_MAP_ELEMENT(i);
		map_element->type = 0;
		map_element->flags = MAP_ELEMENT_FLAG_LAST_TILE;
		map_element->base_height = 14;
		map_element->clearance_height = 14;
		map_element->properties.surface.slope = 0;
		map_element->properties.surface.terrain = 0;
		map_element->properties.surface.grass_length = 1;
		map_element->properties.surface.ownership = 0;
	}

	RCT2_GLOBAL(0x013B0E70, sint16) = 0;
	RCT2_GLOBAL(0x013CE774, sint16) = 0;
	RCT2_GLOBAL(0x013CE776, sint16) = 0;
	RCT2_GLOBAL(0x01358830, sint16) = 4768;
	RCT2_GLOBAL(0x01358832, sint16) = 5054;
	RCT2_GLOBAL(RCT2_ADDRESS_MAP_SIZE, sint16) = 150;
	RCT2_GLOBAL(0x01358836, sint16) = 4767;
	RCT2_GLOBAL(0x01359208, sint16) = 7;
	tiles_init();
	RCT2_CALLPROC_EBPSAFE(0x0068ADBC);

	climate_reset(CLIMATE_WARM);
}

/**
 * 
 *  rct2: 0x0068AFFD
 */
static void tiles_init()
{
	int i, x, y, lastTile;

	for (i = 0; i < MAX_TILE_MAP_ELEMENT_POINTERS; i++)
		TILE_MAP_ELEMENT_POINTER(i) = TILE_UNDEFINED_MAP_ELEMENT;

	rct_map_element *mapElement = RCT2_ADDRESS(RCT2_ADDRESS_MAP_ELEMENTS, rct_map_element);
	rct_map_element **tile = RCT2_ADDRESS(RCT2_ADDRESS_TILE_MAP_ELEMENT_POINTERS, rct_map_element*);
	for (y = 0; y < 256; y++) {
		for (x = 0; x < 256; x++) {
			*tile++ = mapElement;
			do {
				lastTile = (mapElement->flags & MAP_ELEMENT_FLAG_LAST_TILE);
				mapElement++;
			} while (!lastTile);
		}
	}

	// Possible next free map element
	RCT2_GLOBAL(0x0140E9A4, rct_map_element*) = mapElement;
}