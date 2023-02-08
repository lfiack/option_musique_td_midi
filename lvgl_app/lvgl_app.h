/*
 * lvgl_app.h
 *
 *  Created on: 8 févr. 2023
 *      Author: laurentf
 */

#ifndef LVGL_APP_LVGL_APP_H_
#define LVGL_APP_LVGL_APP_H_

#include <stdint.h>

#define TAB_NUMBER 2
#define CC_SLIDERS 4
#define GAIN_INIT 0
#define TAB_CC 0
#define TAB_MIDI_IN 1

int disp_cc_values(int argc, char ** argv);
int disp_midi_in(int argc, char ** argv);
void create_tabs(void);
void create_sliders(void);
void create_midi_in(void);

#endif /* LVGL_APP_LVGL_APP_H_ */
