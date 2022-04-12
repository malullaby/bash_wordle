#include <iostream>
#include "wordle.hpp"

using namespace wordle;
int main()
{
	Wordle wordle;
	wordle.NewGame();
	wordle.Play();
	return 0;
}
