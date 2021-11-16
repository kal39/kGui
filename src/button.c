#include "kGui.h"

Component create_button(int width, int height, char *text, void (*fn)()) {
	Button button = (Button){malloc(strlen(text) + 1), fn};
	memcpy(button.text, text, strlen(text) + 1);

	Component component = (Component){width, height, 1};
	component.data.button = button;
	return component;
}

void change_button_text(ComponentId id, char *format, ...) {
	char buff[MAX_TEXT_LENGTH];
	va_list args;
	va_start(args, format);
	vsnprintf(buff, MAX_TEXT_LENGTH, format, args);
	va_end(args);

	Button *b = &kGS.windows[id.winIdx].components[id.compIdx].data.button;
	b->text = realloc(b->text, strlen(buff) + 1);
	memcpy(b->text, buff, strlen(buff) + 1);
}

void _draw_button(Component *component, int x, int y) {
	int textLength = MeasureText(component->data.button.text, kGS.settings.fontSize);
	Rectangle btnRect = (Rectangle){x, y, textLength + kGS.settings.borderSize * 2,
									kGS.settings.fontSize + kGS.settings.borderSize * 2};

	if (component->data.button.pressed)
		DrawRectangleEx(btnRect, kGS.settings.buttonPressedColor);
	else
		DrawRectangleEx(btnRect, kGS.settings.buttonReleasedColor);

	DrawRectangleLinesEx(btnRect, kGS.settings.buttonBorderSize, kGS.settings.borderColor);

	DrawText(component->data.button.text, x + kGS.settings.borderSize, y + kGS.settings.borderSize,
			 kGS.settings.fontSize, kGS.settings.fontColor);
}