#ifndef SORT_THE_PEOPLE_HPP
#define SORT_THE_PEOPLE_HPP

// https://leetcode.com/problems/sort-the-people/

#include <string>
#include <vector>

class SortThePeople {
public:
    std::vector<std::string> sortPeople(std::vector<std::string>& names,
                                        std::vector<int>& heights) const;
};

#endif