#include "wordle.hpp"
#include <iostream>  //cout
#include <algorithm> //trasform

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
    std::getline(std::cin, str);
    return str;
}

bool Wordle::HandleLine(int line)
{
    std::string userInput = GetLine();

    while (!IsGuessValid(userInput))
    {
        std::cout << "This is not a valid word. Enter a new one: ";
        userInput = GetLine();
    };

    std::cout << std::endl;

    m_board.m_lines[line].Set(userInput, m_word);

    return userInput == m_word;
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

bool Wordle::IsGuessValid(std::string &word) const
{
    std::transform(word.begin(), word.end(), word.begin(), ::toupper);
    return m_dict.InDictionary(word);
}