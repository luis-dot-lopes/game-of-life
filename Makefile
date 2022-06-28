
OBJS = engine/Sources/*.c engine/Sources/shapes/*.c src/*.c

CC = clang

LINKER_FLAGS = -lSDL2

OBJ_NAME = game

all: $(OBJS)
	$(CC) $(OBJS) $(LINKER_FLAGS) -o $(OBJ_NAME)

