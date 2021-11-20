#include "kGui.h"

Component create_button(int width, int height, char *text, void (*fn)()) {
	Component component;
	component.type = 2;
	component.data.button.width = width;
	component.data.button.height = height;
	component.data.button.fn = fn;
	component.data.button.text = malloc(strlen(text) + 1);
	memcpy(component.data.button.text, text, strlen(text) + 1);

	return component;
}

void _draw_button(Button button, int x, int y) {
	Rectangle btnRect = (Rectangle){x, y, button.width, button.height};

	if (button.pressed)
		DrawRectangleEx(btnRect, kGS.settings.buttonPressedColor);
	else
		DrawRectangleEx(btnRect, kGS.settings.buttonReleasedColor);

	DrawRectangleLinesEx(btnRect, kGS.settings.buttonBorderSize, kGS.settings.borderColor);

	DrawText(button.text, x + kGS.settings.padding, y + kGS.settings.padding, kGS.settings.fontSize,
			 kGS.settings.fontColor);
}