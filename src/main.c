#include "kGui.h"

void print_hello() {
	printf("Hello, world!\n");
}

int main(void) {
	InitWindow(800, 600, "test");
	SetTargetFPS(30);

	init_gui();
	ComponentID g1 = create_window(20, 20, 2, 2, 200, 100, "Test");
	ComponentID l1 = add_component(g1, 0, 0, create_label(100, 40, "label 1"));
	add_component(g1, 1, 0, create_button(75, 25, "button", print_hello));
	add_component(g1, 0, 1, create_label(100, 40, "label 2"));

	ComponentID g2 = add_component(g1, 1, 1, create_grid(1, 2, 50, 50));

	add_component(g2, 0, 0, create_label(100, 40, "l1"));
	add_component(g2, 0, 1, create_label(100, 40, "l2"));

	ComponentID g3 = create_window(100, 100, 2, 1, 100, 100, "Window 2");
	ComponentID g4 = create_window(400, 400, 1, 2, 100, 100, "Window 3");

	int i = 0;
	while (!WindowShouldClose()) {
		i++;
		change_component_text(l1, "i: %d", i);
		process_gui();
		draw_gui();
	}
}