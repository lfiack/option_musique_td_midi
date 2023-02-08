/*
 * lvgl_app.c
 *
 *  Created on: 8 févr. 2023
 *      Author: laurentf
 */

#include "lvgl_app.h"

#include <stdio.h>

#include "lvgl/lvgl.h"

static uint8_t cc_values[CC_SLIDERS];

static lv_obj_t * tab[TAB_NUMBER];
static lv_obj_t * tabview;
static char text_buffer[32];
static lv_obj_t * slider_CC_label[CC_SLIDERS];
static lv_obj_t * midi_in_label;

void create_CC_slider(lv_obj_t * tab, int num, const char * name);

int disp_cc_values(int argc, char ** argv)
{
	for (int i = 0 ; i < CC_SLIDERS ; i++)
	{
		printf("CC%d = %d\r\n", i, (int)cc_values[i]);
	}

	return 0;
}

int disp_midi_in(int argc, char ** argv)
{
	if (argc > 1)
	{
		for (int i = 1 ; i < argc ; i++)
		{
			lv_label_set_text(midi_in_label, argv[i]);
		}
	}
	else
	{
		printf("Error: need at least one argument\r\n");
	}

	return 0;
}

void create_tabs(void)
{
	tabview = lv_tabview_create(lv_scr_act(), LV_DIR_BOTTOM, 40);

	sprintf(text_buffer, "CC0-3");
	tab[TAB_CC] = lv_tabview_add_tab(tabview, text_buffer);

	sprintf(text_buffer, "MIDI IN");
	tab[TAB_MIDI_IN] = lv_tabview_add_tab(tabview, text_buffer);

	lv_obj_clear_flag(lv_tabview_get_content(tabview), LV_OBJ_FLAG_SCROLLABLE);
}

void create_sliders(void)
{
	create_CC_slider(tab[TAB_CC], 0, "CC0");
	create_CC_slider(tab[TAB_CC], 1, "CC1");
	create_CC_slider(tab[TAB_CC], 2, "CC2");
	create_CC_slider(tab[TAB_CC], 3, "CC3");
}

void create_midi_in(void)
{
	midi_in_label = lv_label_create(tab[TAB_MIDI_IN]);
	lv_label_set_text(midi_in_label, "Nothing yet...");
	lv_obj_align(midi_in_label, LV_ALIGN_TOP_LEFT, 10, 10);
}

static void slider_CC_event_cb(lv_event_t * e)
{
	lv_obj_t * slider = lv_event_get_target(e);
	uint32_t index = (uint32_t)lv_obj_get_user_data(slider);
	char buf[8];
	int32_t val = lv_slider_get_value(slider);
	lv_snprintf(buf, sizeof(buf), "%d", (int)val);

	cc_values[index] = val;

	lv_label_set_text(slider_CC_label[index], buf);
	lv_obj_align_to(slider_CC_label[index], slider, LV_ALIGN_OUT_RIGHT_MID, 20, 0);
}

void create_CC_slider(lv_obj_t * tab, int num, const char * name)
{
	lv_obj_t * slider_CC = lv_slider_create(tab);
	lv_slider_set_range(slider_CC, 0 , 127);
	lv_slider_set_value(slider_CC, GAIN_INIT, LV_ANIM_ON);
	lv_obj_align(slider_CC, LV_ALIGN_TOP_MID, 0, 20 + 50*num);
	lv_obj_add_event_cb(slider_CC, slider_CC_event_cb, LV_EVENT_VALUE_CHANGED, NULL);
	lv_obj_set_user_data(slider_CC, (void *)num);

	slider_CC_label[num] = lv_label_create(tab);
	sprintf(text_buffer, "%d", GAIN_INIT);	// Reuse old buffer, whatever
	lv_label_set_text(slider_CC_label[num], text_buffer);
	lv_obj_align_to(slider_CC_label[num], slider_CC, LV_ALIGN_OUT_RIGHT_MID, 20, 0);

	lv_obj_t * slider_CC_text_label;
	slider_CC_text_label = lv_label_create(tab);

	lv_label_set_text(slider_CC_text_label, name);
	lv_obj_align_to(slider_CC_text_label, slider_CC, LV_ALIGN_OUT_LEFT_MID, -15, 0);
}
