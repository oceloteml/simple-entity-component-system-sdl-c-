compile: build run

build:
	g++ src/main.cpp src/include/game.cpp \
src/include/Vector2/vector2.cpp \
src/include/Entities/entities.cpp \
-o out/game.exe -I src/include -L src/lib -lSDL3 -lSDL3_image -lmingw32 \


run:
	./out/game.exe
