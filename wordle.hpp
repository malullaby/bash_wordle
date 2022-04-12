#ifndef ME_WORDLE_HPP
#define ME_WORDLE_HPP

#include <string> // FIXME: simpler
#include <unordered_set>
#include <array>
#include <iostream> // tests
#include "dict.hpp"
#include "board.hpp"

namespace wordle
{
    class Wordle
    {
    public:
        void NewGame();
        void Play();

    private:
        std::string m_word;
        Dictionary m_dict;
        Board m_board;
        std::string GetLine();
        bool HandleLine(int line);
    };
}
#endif
