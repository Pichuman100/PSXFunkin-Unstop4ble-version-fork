/*
  This Source Code Form is subject to the terms of the Mozilla Public
  License, v. 2.0. If a copy of the MPL was not distributed with this
  file, You can obtain one at http://mozilla.org/MPL/2.0/.
*/

#include "events.h"
#include "stage.h"
#include "timer.h"
#include "random.h"
#include "mutil.h"

Events event_speed;

static void Events_GetEventsValue(Event* event)
{
	//Events
	switch(event->event & EVENTS_FLAG_VARIANT)
	{
		case EVENTS_FLAG_SPEED: //Scroll Speed!!
		{
			event_speed.value1 = event->value1;
			event_speed.value2 = event->value2;
			break;
		}
		case EVENTS_FLAG_GF: //Set GF Speed!!
		{
			stage.gf_speed = (event->value1 >> FIXED_SHIFT) * 4;
			break;
		}
		case EVENTS_FLAG_CAMZOOM: //Add Camera Zoom!!
		{
			stage.charbump += event->value1;
			stage.bump += event->value2;
			break;
		}
		default: //nothing lol
		break;
	}
}

static void Events_CheckEvents(Chart* chart)
{
	for (Event *event = chart->cur_event; event->pos != 0xFFFF; event++)
	{
		//Update event pointer
		if (event->pos > (chart->note_scroll >> FIXED_SHIFT))
			break;

		else
			chart->cur_event++;

		if (event->event & EVENTS_FLAG_PLAYED)
			continue;

		Events_GetEventsValue(event);
		event->event |= EVENTS_FLAG_PLAYED;
	}
}

void Events_Tick(void)
{
	//Scroll Speed!
	stage.speed += (FIXED_MUL(stage.ogspeed, event_speed.value1) - stage.speed) / (((event_speed.value2 / 60) + 1));
}

void Events_StartEvents(void)
{
	Events_CheckEvents(&stage.chart);
	Events_CheckEvents(&stage.event_chart);
	Events_Tick();
}

//Initialize some stuffs
void Events_Load(void)
{
	//Scroll Speed
	event_speed.value1 = FIXED_UNIT;
	event_speed.value2 = 0;
}