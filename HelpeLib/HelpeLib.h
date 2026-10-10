#pragma once

#pragma warning(disable : 4996)
#include <ctime>
#include <string>
#include <iostream>
using namespace std;

namespace dt {
    std::tm* GetNow();
    std::string YearNow();
    std::string MonthsNow();
    std::string DayNow();
    std::string DateNow();
    std::string DateNow(char x);
}

namespace input
{
    template <typename T>
    T GetNumber();

    template <typename T>
    bool IsBetween(T num, T from, T to);

    template <typename T>
    T GetNumberInRange(T from, T to);

    std::string ReadString();

    //char MyTolower(char c)
    //{
    //    if (c >= 'A' && c <= 'Z')
    //        return c + ('a' - 'A');

    //    return c;
    //}

    //char MyToupper(char c)
    //{
    //    if (c >= 'a' && c <= 'z')
    //        return c - ('a' - 'A');

    //    return c;
    //}

    //char InvertLetterCase(char c)
    //{
    //    if (c >= 'a' && c <= 'z')
    //        return MyToupper(c);

    //    if (c >= 'A' && c <= 'Z')
    //        return MyTolower(c);

    //    return c;
    //}
}