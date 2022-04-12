all:
	g++ -std=c++11 *.cpp -o bash_wordle.out

.PHONY: clean

clean:
	rm bash_wordle.out