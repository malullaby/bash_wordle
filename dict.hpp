#ifndef ME_DICT_HPP
#define ME_DICT_HPP

#include <unordered_set>

namespace wordle
{
class Dictionary
{
public:
    Dictionary(std::string dict_location);
    bool InDictionary(std::string word) const;
    std::string GetRandomWord() const;

private:
    std::unordered_set<std::string> m_set;
};

} // namespace wordle

#endif
