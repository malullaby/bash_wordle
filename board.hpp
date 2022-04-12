
#ifndef ME_BOARD_HPP
#define ME_BOARD_HPP

#include "line.hpp"

namespace wordle
{
    class Board
    {
    public:
        void Draw() const;
        std::array<Line, 6> m_lines;
    };
}

#endif
