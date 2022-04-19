#include <iostream> // cout
#include "char.hpp"

using namespace wordle;

Char::Char(char character, Color color) : m_character(character), m_color(color)
{
}

void Char::SetCharacter(char character)
{
    m_character = character;
}

void Char::SetColor(Color color)
{
    m_color = color;
}

void Char::Draw()
{
    switch (m_color)
    {
    case Color::WHITE:
        std::cout << "\033[1m\033[37m";
        break;
    case Color::YELLOW:
        std::cout << "\033[1m\033[33m";
        break;
    case Color::GREEN:
        std::cout << "\033[1m\033[32m";
        break;
    case Color::GREY:
        std::cout << "\033[1m\033[2m";
        break;
    }
    std::cout << m_character << " "
              << "\033[0m";
}