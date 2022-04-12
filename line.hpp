#include <array>
#include "char.hpp"

#ifndef ME_LINE_HPP
#define ME_LINE_HPP

namespace wordle
{
    struct Line
    {
        void Set(std::string user_input, std::string correct_word);
        void Draw();
        std::array<Char, 5> m_char_array;
    };
}

#endif
