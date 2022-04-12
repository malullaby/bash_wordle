all:
	g++ -ansi -std=c++11 -pedantic-errors -Wall -Wextra -g *.cpp -o bash_wordle.out

.PHONY: clean

clean:
	rm bash_wordle.out