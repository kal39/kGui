#ifndef K_GUI_H
#define K_GUI_H

#include <raylib.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "structs.h"

#define MAX_TEXT_LENGTH 256
#define EMPTY_COMPONENT                                                                                                \
	(Component) {                                                                                                      \
		0, 0, -1                                                                                                       \
	}

extern KGuiState kGS;

// kGui
void init_gui();
void draw_gui();

// window
WindowId create_window(int x, int y, int cols, int rows, char *title);
void _draw_window();

// component
ComponentId add_component(WindowId id, int x, int y, Component c);
void remove_component(ComponentId id);
ComponentId get_component_id(WindowId id, int x, int y);

// label
Component create_label(int width, int height, char *text);
void change_label_text(ComponentId id, char *format, ...);
void draw_label(Label *label, int x, int y);

// // textbox
// create_textbox(char *text, char alignment, int width, int height);
// void draw_textbox(Window w);
// create_editable_textbox(char *text, char alignment, int width, int height, void(*fn));
// change_text(int textBox, char *newText);

// // button
// create_button(char *text, char alignment, int width, int height, void(*fn));
// void draw_button(Window w);

// // slider

#endif