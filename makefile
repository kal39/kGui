#------------------------------------------------------------------------------#
# important variables                                                          #
#------------------------------------------------------------------------------#

# binary name 
BIN := gui

# include dir
INC := -I include/

# library dir
LIB := -L lib/

# libraries 
LIBS :=  -lraylib -lGL -lm -lpthread -ldl -lrt -lX11

# flags 
FLAGS := -Wall -Wno-missing-braces 

# defines
DEFS := 
#------------------------------------------------------------------------------#
# other variables                                                              #
#------------------------------------------------------------------------------#

# commands 
CC := gcc $(FLAGS) $(DEFS) $(INC) $(LIB)
MV := mv
RM := rm -rf
CP := cp
MKDIR := mkdir -p
ECHO := @echo

# folders 
BUILD := build
SRC := src

#------------------------------------------------------------------------------#
# build process                                                                #
#------------------------------------------------------------------------------#

.PHONY: default run clean

default: clean $(BIN)

run: clean $(BIN)
	./$(BIN)

debug: CC += -g
debug: clean $(BIN)
	gdb $(BIN)

$(BUILD):
	$(MKDIR) $(BUILD)

$(BIN): $(BUILD)
	$(CC) -c $(SRC)/kGui.c -o $(BUILD)/kGui.a
	$(CC) -c $(SRC)/global.c -o $(BUILD)/global.a
	$(CC) -c $(SRC)/utils.c -o $(BUILD)/utils.a
	$(CC) -c $(SRC)/component.c -o $(BUILD)/component.a
	$(CC) -c $(SRC)/grid.c -o $(BUILD)/grid.a
	$(CC) -c $(SRC)/window.c -o $(BUILD)/window.a
	$(CC) -c $(SRC)/label.c -o $(BUILD)/label.a
	$(CC) -c $(SRC)/button.c -o $(BUILD)/button.a

	$(CC) -c $(SRC)/main.c -o $(BUILD)/main.o

	$(CC) $(BUILD)/* -o $(BIN) $(LIBS)

clean:
	$(RM) $(BIN) $(BUILD)
