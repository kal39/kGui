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
	DrawRectangle(w->x, w->y, w->cols * w->gridWidth, kGS.settings.titleBarHeight, kGS.settings.titleBarColor);
	DrawRectangleLinesEx((Rectangle){w->x, w->y, w->cols * w->gridWidth, kGS.settings.titleBarHeight},
						 kGS.settings.borderSize, kGS.settings.borderColor);
	DrawText(w->title, w->x + kGS.settings.borderSize * 2,
			 w->y + kGS.settings.titleBarHeight / 2 - kGS.settings.fontSize / 2, kGS.settings.fontSize,
			 kGS.settings.fontColor);

	// main body
	DrawRectangle(w->x, w->y + kGS.settings.titleBarHeight - kGS.settings.borderSize, w->cols * w->gridWidth,
				  w->rows * w->gridHeight, kGS.settings.windowColor);
	DrawRectangleLinesEx((Rectangle){w->x, w->y + kGS.settings.titleBarHeight - kGS.settings.borderSize,
									 w->cols * w->gridWidth, w->rows * w->gridHeight},
						 kGS.settings.borderSize, kGS.settings.borderColor);

	// components
	for (int i = 0; i < w->rows; i++) {
		for (int j = 0; j < w->cols; j++) {
			Component *c = &w->components[j + i * w->cols];
			int x = j * w->gridWidth + kGS.settings.borderSize;
			int y = i * w->gridHeight + kGS.settings.titleBarHeight + kGS.settings.borderSize;

			switch (c->type) {
				case 0:
					draw_label(&c->data.label, x, y);
					break;

				default:
					break;
			}
		}
	}
}