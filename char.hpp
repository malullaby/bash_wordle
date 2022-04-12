#ifndef ME_CHAR_HPP
#define ME_CHAR_HPP

namespace wordle
{
    struct Char
    {
        enum struct Color
        {
            WHITE,
            GREY,
            YELLOW,
            GREEN
        };
        Char(char character = '?', Color color = Color::WHITE);
        void SetCharacter(char m_character);
        void SetColor(Color color);
        void Draw();

    private:
        char m_character;
        Color m_color;
    };

}
#endif
