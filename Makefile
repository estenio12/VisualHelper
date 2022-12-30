Conpiling: ./Sources/*.cpp
	clang++ ./Sources/*.cpp -std=c++20 -o VSScript-Editor -lsfml-graphics -lsfml-window -lsfml-system -lGL -ltgui
	./VSScript-Editor
	clear