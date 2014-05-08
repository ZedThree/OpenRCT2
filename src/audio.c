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

#include "audio.h"
#include "addresses.h"
#include "rct2.h"

void get_dsound_devices()
{
	RCT2_CALLPROC(0x0040502E);
}

int sound_prepare(int sound_id, rct_sound *sound, int var_8, int var_c)
{
	return RCT2_CALLFUNC_4(0x00404C6D, int, int, rct_sound*, int, int, sound_id, sound, var_8, var_c);
}

void sound_play_panned(int sound_id, int x)
{
	RCT2_CALLPROC_X(0x006BB76E, sound_id, x, 0, 0, 0, 0, 0);
}

int sound_play(rct_sound* sound, int looping, int volume, int pan, int frequency)
{
	return RCT2_CALLFUNC_5(0x00404E7F, int, rct_sound*, int, int, int, int, sound, looping, volume, pan, frequency);
}

void sound_stop(rct_sound* sound)
{
	RCT2_CALLPROC_1(0x00404DD8, rct_sound*, sound);
}

/**
*
*  rct2: 0x006BABB4
*/
void pause_sounds() {
	if (++RCT2_GLOBAL(0x009AF59C, uint8) == 1) {
		RCT2_CALLPROC_EBPSAFE(0x006BCAE5);
		RCT2_CALLPROC_EBPSAFE(0x006BABDF);
		RCT2_CALLPROC_EBPSAFE(0x006BCA9F);
		RCT2_CALLPROC_EBPSAFE(0x006BD07F);
	}
}

/**
*
*  rct2: 0x006BABD8
*/
void unpause_sounds() {
	RCT2_GLOBAL(0x009AF59C, uint8)--;
}