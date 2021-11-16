#include "kGui.h"

WindowId create_window(int x, int y, int cols, int rows, char *title) {
	Window w = (Window){x, y, malloc(strlen(title) + 1), cols, rows, 0, 0, malloc(sizeof(Component) * cols * rows)};
	memcpy(w.title, title, strlen(title) + 1);

	for (int i = 0; i < w.rows * w.cols; i++) {
		w.components[i] = EMPTY_COMPONENT;
	}

	kGS.windowCount++;
	kGS.windows = realloc(kGS.windows, sizeof(Window) * kGS.windowCount);
	kGS.windows[kGS.windowCount - 1] = w;

	return kGS.windowCount - 1;
}

void _draw_window(WindowId id) {
	Window *w = &kGS.windows[id];

	// title bar
	Rectangle titleRect = (Rectangle){w->x, w->y, w->cols * w->gridWidth, kGS.settings.titleBarHeight};
	DrawRectangleEx(titleRect, kGS.settings.titleBarColor);
	DrawRectangleLinesEx(titleRect, kGS.settings.borderSize, kGS.settings.borderColor);
	DrawText(w->title, w->x + kGS.settings.borderSize * 2,
			 w->y + kGS.settings.titleBarHeight / 2 - kGS.settings.fontSize / 2, kGS.settings.fontSize,
			 kGS.settings.fontColor);

	// main body
	Rectangle mainRect = (Rectangle){w->x, w->y + kGS.settings.titleBarHeight - kGS.settings.borderSize,
									 w->cols * w->gridWidth, w->rows * w->gridHeight};
	DrawRectangleEx(mainRect, kGS.settings.windowColor);
	DrawRectangleLinesEx(mainRect, kGS.settings.borderSize, kGS.settings.borderColor);

	// components
	for (int i = 0; i < w->rows; i++) {
		for (int j = 0; j < w->cols; j++) {
			Component *c = &w->components[j + i * w->cols];
			int x = w->x + j * w->gridWidth + kGS.settings.borderSize;
			int y = w->y + i * w->gridHeight + kGS.settings.titleBarHeight + kGS.settings.borderSize;

			switch (c->type) {
				case 0:
					_draw_label(c, x, y);
					break;

				case 1:
					_draw_button(c, x, y);
					break;

				default:
					break;
			}
		}
	}
}