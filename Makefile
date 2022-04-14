FLAGS = -pedantic-errors -std=c++11

Monster.o: Monster.cpp Monster.h
	g++ $(FLAGS) -c $<

Player.o: Player.cpp Player.h
	g++ $(FLAGS) -c $<

Game.o: Game.cpp
	g++ $(FLAGS) -c $<

Game: Game.o Player.o Monster.o
	g++ $(FLAGS) $^ -o $@

clean:
	rm -f Monster.o Player.o Game.o Game

.PHONY: clean

