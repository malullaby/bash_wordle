#include "wordle.hpp"
#include <iostream>
#include <unordered_set>
#include <fstream>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace wordle;

Wordle::Wordle(std::string dict_path) : m_dict(Dictionary(dict_path))
{

}

    void Wordle::NewGame()
{
    m_word = m_dict.GetRandomWord();
}

std::string Wordle::GetLine()
{
    std::string str;
    std::cin >> str;
    return str;
}

bool Wordle::HandleLine(int line)
{
    std::string user_input;
    do
    {
        user_input = GetLine();
        std::transform(user_input.begin(), user_input.end(), user_input.begin(), ::toupper);
        std::cout << "This is not a valid word. Enter a new one: ";
    } while (!m_dict.InDictionary(user_input));

    std::cout << std::endl;

    m_board.m_lines[line].Set(user_input, m_word);

    return user_input == m_word;
}

void Wordle::Play()
{
    bool win = false;
    for (size_t i = 0; i < 6; ++i)
    {
        m_board.Draw();
        std::cout << "Enter a word: ";

        if ((win = HandleLine(i)))
        {
            break;
        }
        std::cout << std::endl;
    }
    m_board.Draw();

    if (win)
    {
        std::cout << "You Win!" << std::endl;
    }
    else
    {

        std::cout << "Try Again!" << std::endl;
    }
}