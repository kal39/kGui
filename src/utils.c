#include "kGui.h"

void _draw_rectangle(Rectangle rectangle, Color color) {
	DrawRectangle(rectangle.x, rectangle.y, rectangle.width, rectangle.height, color);
}

int _mouse_in_area(int x, int y, int w, int h) {
	return GetMouseX() > x && GetMouseX() < x + w && GetMouseY() > y && GetMouseY() < y + h;
}