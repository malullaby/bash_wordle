#include "wordle.hpp"

using namespace wordle;
int main()
{
	Wordle wordle("/usr/share/dict/american-english");
	wordle.NewGame();
	wordle.Play();
	return 0;
}
