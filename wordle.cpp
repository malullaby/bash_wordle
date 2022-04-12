#include "wordle.hpp"
#include <iostream>
#include <unordered_set>
#include <fstream>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace ilrd;

Dictionary::Dictionary()
{
    std::ifstream is("/usr/share/dict/american-english");
    std::string str;
    while (getline(is, str))
    {
        std::transform(str.begin(), str.end(), str.begin(), ::toupper);
        if (str.length() == 5 && std::all_of(str.begin(), str.end(), [](char c)
                                             { return isalpha(c); }))
        {
            m_set.insert(str);
        }
    }
}

bool Dictionary::InDictionary(std::string word) const
{
    return m_set.find(word) != m_set.end();
}

std::string Dictionary::GetRandomWord() const
{
    srand(time(0));
    size_t random_num = rand() % m_set.size();
    size_t count = 0;
    std::string str;
    for (auto word : m_set)
    {
        if (count++ == random_num)
        {
            str = word;
            break;
        }
    }
    return str;
}

void View::Char::Print()
{
    switch (m_color)
    {
    case View::Color::WHITE:
        std::cout << "\033[1m\033[37m";
        break;
    case View::Color::YELLOW:
        std::cout << "\033[1m\033[33m";
        break;
    case View::Color::GREEN:
        std::cout << "\033[1m\033[32m";
        break;
    case View::Color::GREY:
        std::cout << "\033[1m\033[2m";
        break;
    }
    std::cout << m_character << " "
              << "\033[0m";
}

View::View()
{
}

void View::Draw() const
{
    system("clear");
    for (auto arr : m_char_matrix)
    {
        for (auto character : arr)
        {
            character.Print();
        }
        std::cout << std::endl;
    }
}

void View::SetChar(int row, int column, Char c)
{
    m_char_matrix[row][column] = c;
}

Play::Play()
{
}

bool Play::Line(int line)
{
    std::string str;

    do
    {
        std::cin >> str;
        std::transform(str.begin(), str.end(), str.begin(), ::toupper);
        std::cout << "This is not a valid word. Enter a new one: ";
    } while (!m_dict.InDictionary(str));
    std::cout << std::endl;
    for (size_t i = 0; i < 5; ++i)
    {
        View::Color color = View::Color::GREY;
        if (str[i] == m_word[i])
        {
            color = View::Color::GREEN;
        }
        else if (m_word.find(str[i]) != m_word.npos)
        {
            color = View::Color::YELLOW;
        }
        m_view.SetChar(line, i, View::Char(str[i], color));
    }
    if (str == m_word)
    {
        std::cout << "Correct!" << std::endl;
        return true;
    }
    return false;
}

void Play::NewGame()
{
    m_word = m_dict.GetRandomWord();
    std::cout << m_word << std::endl;
    bool win = false;
    for (size_t i = 0; i < 6; ++i)
    {
        m_view.Draw();
        std::cout << "Enter a word: ";

        if (true == (win = Line(i)))
        {
            break;
        }
        std::cout << std::endl;
    }
    m_view.Draw();
    if (win)
    {
        std::cout << "You Win!" << std::endl;
    }
    else
    {

        std::cout << "Try Again!" << std::endl;
    }
    // Limit to once a day
}