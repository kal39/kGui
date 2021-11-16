#include "kGui.h"

void init_gui() {
	kGS.windowCount = 0;

	kGS.settings.fontColor = BLACK;
	kGS.settings.fontSize = 20;

	kGS.settings.windowColor = LIGHTGRAY;

	kGS.settings.titleBarHeight = 30;
	kGS.settings.titleBarColor = GRAY;

	kGS.settings.borderSize = 4;
	kGS.settings.borderColor = DARKGRAY;
}

void draw_gui() {
	BeginDrawing();
	ClearBackground(BLACK);

	for (int i = 0; i < kGS.windowCount; i++) {
		_draw_window(i);
	}

	EndDrawing();
}