#include "kGui.h"

ComponentID create_window(int x, int y, int cols, int rows, int cellWidth, int cellHeight, char *title) {
	Component grid = create_grid(cols, rows, cellWidth, cellHeight);

	kGS.componentCount++;
	kGS.components = realloc(kGS.components, sizeof(Component) * kGS.componentCount);
	kGS.components[kGS.componentCount - 1] = grid;

	Window w = (Window){x, y, malloc(strlen(title) + 1), kGS.componentCount - 1};
	memcpy(w.title, title, strlen(title) + 1);

	kGS.windowCount++;
	kGS.windows = realloc(kGS.windows, sizeof(Window) * kGS.windowCount);
	kGS.windows[kGS.windowCount - 1] = w;

	return kGS.componentCount - 1;
}

void _draw_window(Window w) {
	Grid grid = _get_component(w.grid).data.grid;
	int width = grid.cellWidth * grid.cols + kGS.settings.borderSize * 2;
	int height = grid.cellHeight * grid.rows + kGS.settings.borderSize * 2;

	// title bar
	Rectangle titleRect = (Rectangle){w.x, w.y, width, kGS.settings.titleBarHeight};
	DrawRectangleEx(titleRect, kGS.settings.titleBarColor);
	DrawRectangleLinesEx(titleRect, kGS.settings.borderSize, kGS.settings.borderColor);
	DrawText(w.title, w.x + kGS.settings.borderSize * 2,
			 w.y + kGS.settings.titleBarHeight / 2 - kGS.settings.fontSize / 2, kGS.settings.fontSize,
			 kGS.settings.fontColor);

	// main body
	Rectangle mainRect = (Rectangle){w.x, w.y + kGS.settings.titleBarHeight - kGS.settings.borderSize, width, height};
	DrawRectangleEx(mainRect, kGS.settings.windowColor);
	DrawRectangleLinesEx(mainRect, kGS.settings.borderSize, kGS.settings.borderColor);

	_draw_component(w.grid, w.x + kGS.settings.borderSize, w.y + kGS.settings.borderSize + kGS.settings.titleBarHeight);
}