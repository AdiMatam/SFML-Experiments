.SILENT:

INCLUDE = -DTGUI_STATIC -DSFML_STATIC -Iinclude
EXTERNAL = -ltgui-s -lsfml-graphics-s -lsfml-window-s -lsfml-system-s -lopengl32 -lwinmm -lgdi32 -lfreetype
STANDARD = -static-libgcc -static-libstdc++
FILES = src/main.cpp src/helpers.cpp src/checkers.cpp src/slot.cpp

all: build run
build: compile link
compile:
	echo "Compiling CPP files..."
	g++ -c $(FILES) $(INCLUDE)
link:
	echo "Linking libraries..."
	g++ $(wildcard *.o) -o main.exe $(STANDARD) -Llib $(EXTERNAL)
run:
	echo "Running main.exe..."
	./main.exe
pch:
	echo "Making pch..."
	g++ src/pch.hpp $(INCLUDE)
clean:
	echo "Removing .o/.exe..."
	rm -f *.o *.exe
# test:
# 	echo "Testing file"
# 	g++ -c src/extra/test.cpp src/helpers.cpp $(INCLUDE)
# 	g++ $(wildcard *.o) -o test.exe $(STANDARD) -Llib $(EXTERNAL)
# 	./test.exe 

