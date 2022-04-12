#include "line.hpp"

using namespace wordle;

void Line::Set(std::string user_input, std::string correct_word)
{
    for (size_t i = 0; i < 5; ++i)
    {
        Char::Color color = Char::Color::GREY;
        if (user_input[i] == correct_word[i])
        {
            color = Char::Color::GREEN;
        }
        else if (correct_word.find(user_input[i]) != correct_word.npos)
        {
            color = Char::Color::YELLOW;
        }
        m_char_array[i].SetCharacter(user_input[i]);
        m_char_array[i].SetColor(color);
    }
}

void Line::Draw()
{
    for (auto c : m_char_array)
    {
        c.Draw();
    }
}