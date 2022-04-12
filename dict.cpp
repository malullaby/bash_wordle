#include <unordered_set>
#include <fstream>
#include <algorithm>
#include <cstdlib>
#include <ctime> // time
#include "dict.hpp"

using namespace wordle;

Dictionary::Dictionary(std::string dict_location)
{
    std::ifstream is(dict_location);
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
