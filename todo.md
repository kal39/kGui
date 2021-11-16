# kGui

```
- kGui.c
  - initGui()
  - drawGui()
- window.c
  - createWindow(x, y, width, height, title)
    width, height: grid width and height
  - addComponent(window, x, y, component)
    x, y: grid pos
  - getGridCell(window, &x, &y, &width, &height)
- textbox.c
  - createTextbox(text, alignment, width, height)
    alignment: 'c', 'r', 'l'
  - createEditableTextBox(text, alignment, width, height, fn)
  - changeText(textBox, newText)
- button.c
  - createButton(text, alignment, width, height, fn)  
```

```c
struct Window {
    int x, y;
    int width, height;
    char *title;
    
    int gridWidth, gridHeight;
    Component **components;
}

struct Component {
    int type;
    union {
        TextBox,
        Button
    } data;
}

struct TextBox {
    int width, height;
    int editable;
    char *text;
    void (*fn)(char *);
}

struct Button {
    int width, height;
    char *text;
    void (*fn)();
}
```

