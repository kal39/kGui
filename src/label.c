#include "kGui.h"

Component create_label(int width, int height, char *text) {
	Label label = (Label){malloc(strlen(text) + 1)};
	memcpy(label.text, text, strlen(text) + 1);

	Component component = (Component){width, height, 0};
	component.data.label = label;
	return component;
}

void change_label_text(ComponentId id, char *format, ...) {
	char buff[MAX_TEXT_LENGTH];
	va_list args;
	va_start(args, format);
	vsnprintf(buff, MAX_TEXT_LENGTH, format, args);
	va_end(args);

	Label *l = &kGS.windows[id.winIdx].components[id.compIdx].data.label;
	l->text = realloc(l->text, strlen(buff) + 1);
	memcpy(l->text, buff, strlen(buff) + 1);
}

void draw_label(Label *label, int x, int y) {
	DrawText(label->text, x + kGS.settings.borderSize, y + kGS.settings.borderSize, kGS.settings.fontSize,
			 kGS.settings.fontColor);
}