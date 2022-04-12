#ifndef ILRD_RD1123_WORDLE_HPP
#define ILRD_RD1123_WORDLE_HPP

#include <string> // FIXME: simpler
#include <unordered_set>
#include <array>
#include <iostream> // tests

namespace ilrd
{
    class Dictionary
    {
    public:
        Dictionary();
        bool InDictionary(std::string word) const;
        std::string GetRandomWord() const;

    private:
        std::unordered_set<std::string> m_set;
    };

    class View
    {
    public:
        enum struct Color
        {
            WHITE,
            GREY,
            YELLOW,
            GREEN
        };
        struct Char
        {
            Char(char character = '?', Color color = View::Color::WHITE) : m_character(character),
                                                                           m_color(color)
            {
            }
            void Print();
            Color m_color;
            char m_character;
        };

        View();
        void Draw() const;
        void SetChar(int row, int column, Char c);

    private:
        std::array<std::array<Char, 5>, 6> m_char_matrix;
    };

    class Play
    {
    public:
        Play();
        bool Line(int line);
        void NewGame();


    private:
        std::string m_word;
        Dictionary m_dict;
        View m_view;
    };
}
#endif
