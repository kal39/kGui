#include "kGui.h"

int main(void) {
	InitWindow(800, 600, "test");
	SetTargetFPS(30);
	SetExitKey(0);
	// if (!IsWindowFullscreen()) ToggleFullscreen();

	init_gui();
	WindowId w1 = create_window(20, 20, 2, 2, "Test");

	Component l1 = create_label(100, 40, "label 1");
	ComponentId id1 = add_component(w1, 0, 0, l1);

	Component b1 = create_button(100, 40, "button", NULL);
	ComponentId id2 = add_component(w1, 1, 0, b1);

	int i = 0;
	while (1) {
		i++;
		change_label_text(id1, "i: %d", i);
		draw_gui();
	}
}