#include "kGui.h"

void print_button() {
	printf("Button was pressed\n");
}

void print_string(char *text) {
	printf("Text inputted: %s\n", text);
}

int main(void) {
	InitWindow(800, 600, "test");
	SetTargetFPS(30);
	SetExitKey(0);

	init_gui();
	ComponentID g1 = create_window(20, 20, 2, 2, 200, 100, "Test");
	ComponentID l1 = add_component(g1, 0, 0, create_label("label 1"));
	add_component(g1, 1, 0, create_button(75, 25, "button", print_button));
	add_component(g1, 0, 1, create_label("label 2"));

	ComponentID g2 = add_component(g1, 1, 1, create_grid(1, 2, 50, 50));

	add_component(g2, 0, 0, create_label("l1"));
	add_component(g2, 0, 1, create_label("l2"));

	ComponentID g3 = create_window(100, 100, 2, 1, 200, 100, "Window 2");
	add_component(g3, 0, 0, create_textbox(200, 25, "", print_string));

	ComponentID g4 = create_window(400, 400, 1, 2, 100, 100, "Window 3");
	ComponentID t1 = add_component(g4, 0, 0, create_pos_tracker());

	while (!WindowShouldClose()) {
		change_component_text(l1, "(%d, %d)", get_pos_tracker_x(t1), get_pos_tracker_y(t1));
		process_gui();
		draw_gui();
	}
}