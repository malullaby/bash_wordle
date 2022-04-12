#include <iostream>
#include "board.hpp"

using namespace wordle;

void Board::Draw() const
{
    system("clear");
    for (auto arr : m_lines)
    {
        arr.Draw();
        std::cout << std::endl;
    }
}