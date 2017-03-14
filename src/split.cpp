#include "split.h"

std::vector<std::string> split(const std::string& line, const std::string& delim)
{
    int start = 0;
    int end = 0;
    std::vector<std::string> elements;

    while (start < line.length())
    {
        end = line.find(delim, start);

        if(end < 0)
        {
            end = line.length();
        }

        elements.push_back(line.substr(start, end-start));

        //need to go past the delimiter
        start = end + delim.length();
    }

    return elements;
}