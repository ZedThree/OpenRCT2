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

#ifndef _CONFIG_H_
#define _CONFIG_H_

#include <windows.h>
#include "rct2.h"

enum {
	CONFIG_FLAG_ALWAYS_SHOW_GRIDLINES = (1 << 0),
	CONFIG_FLAG_SHOW_HEIGHT_AS_UNITS = (1 << 1),
	CONFIG_FLAG_DISABLE_SMOOTH_LANDSCAPE = (1 << 2)	
};

enum {
	SHORTCUT_CLOSE_TOP_MOST_WINDOW,
	SHORTCUT_CLOSE_ALL_FLOATING_WINDOWS,
	SHORTCUT_CANCEL_CONSTRUCTION_MODE,
	SHORTCUT_PAUSE_GAME,
	SHORTCUT_ZOOM_VIEW_OUT,
	SHORTCUT_ZOOM_VIEW_IN,
	SHORTCUT_ROTATE_VIEW,
	SHORTCUT_ROTATE_CONSTRUCTION_OBJECT,
	SHORTCUT_UNDERGROUND_VIEW_TOGGLE,
	SHORTCUT_REMOVE_BASE_LAND_TOGGLE,
	SHORTCUT_REMOVE_VERTICAL_LAND_TOGGLE,
	SHORTCUT_SEE_THROUGH_RIDES_TOGGLE,
	SHORTCUT_SEE_THROUGH_SCENERY_TOGGLE,
	SHORTCUT_INVISIBLE_SUPPORTS_TOGGLE,
	SHORTCUT_INVISIBLE_PEOPLE_TOGGLE,
	SHORTCUT_HEIGHT_MARKS_ON_LAND_TOGGLE,
	SHORTCUT_HEIGHT_MARKS_ON_RIDE_TRACKS_TOGGLE,
	SHORTCUT_HEIGHT_MARKS_ON_PATHS_TOGGLE,
	SHORTCUT_ADJUST_LAND,
	SHORTCUT_ADJUST_WATER,
	SHORTCUT_BUILD_SCENERY,
	SHORTCUT_BUILD_PATHS,
	SHORTCUT_BUILD_NEW_RIDE,
	SHORTCUT_SHOW_FINANCIAL_INFORMATION,
	SHORTCUT_SHOW_RESEARCH_INFORMATION,
	SHORTCUT_SHOW_RIDES_LIST,
	SHORTCUT_SHOW_PARK_INFORMATION,
	SHORTCUT_SHOW_GUEST_LIST,
	SHORTCUT_SHOW_STAFF_LIST,
	SHORTCUT_SHOW_RECENT_MESSAGES,
	SHORTCUT_SHOW_MAP,
	SHORTCUT_SCREENSHOT,
	SHORTCUT_COUNT
};

enum {
	SCREENSHOT_FORMAT_BMP,
	SCREENSHOT_FORMAT_PNG
};

extern uint16 gShortcutKeys[SHORTCUT_COUNT];

void config_reset_shortcut_keys();
void config_load();
void config_save();


// New config format

typedef struct configuration {
	uint8 screenshot_format;
	char game_path[MAX_PATH];
} configuration_t;

extern configuration_t gConfig;

void config_init();

#endif
