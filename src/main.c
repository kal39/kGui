#include "kGui.h"

int main(void) {
	InitWindow(GetScreenWidth(), GetScreenWidth(), "test");
	SetTargetFPS(30);
	SetExitKey(0);
	// if (!IsWindowFullscreen()) ToggleFullscreen();

	init_gui();
	WindowId w1 = create_window(0, 0, 2, 2, "AAA");

	Component c1 = create_label(100, 40, "label 1");
	ComponentId id1 = add_component(w1, 0, 0, c1);

	Component c2 = create_label(100, 40, "label 2");
	ComponentId id2 = add_component(w1, 1, 0, c2);

	int i = 0;
	while (1) {
		i++;
		change_label_text(id1, "i: %d", i);
		draw_gui();
	}
}