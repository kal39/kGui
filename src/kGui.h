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
void process_gui();

// window
ComponentID create_window(int x, int y, int cols, int rows, int cellWidth, int cellHeight, char *title);
void _draw_window(Window *w);
void _process_window(Window *w);

// components
ComponentID add_component(ComponentID destination, int x, int y, Component component);
void change_component_text(ComponentID compId, char *format, ...);
Component *_get_component(ComponentID compId);
void _draw_component(ComponentID compID, int x, int y);
void _process_component(ComponentID compID, int x, int y);

// grid
Component create_grid(int cols, int rows, int cellWidth, int cellHeight);
void _draw_grid(Grid *grid, int x, int y);
void _process_grid(Grid *grid, int x, int y);

// label
Component create_label(int width, int height, char *text);
void _draw_label(Label *label, int x, int y);

// textbox

// button
Component create_button(int width, int height, char *text, void (*fn)());
void _draw_button(Button *button, int x, int y);
void _process_button(Button *button, int x, int y);

// slider

// util
void _draw_rectangle(Rectangle rectangle, Color color);
int _mouse_in_area(int x, int y, int w, int h);

#endif