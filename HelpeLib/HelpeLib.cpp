// HelpeLib.cpp : Defines the functions for the static library.
//
#pragma once

#pragma warning(disable : 4996)
#include <ctime>
#include <string>
#include <iostream>
#include "HelpeLib.h"
using namespace std;

namespace dt {
    std::tm* GetNow()
    {
        std::time_t t = std::time(nullptr);
        return std::localtime(&t);
    }
    std::string YearNow() {
        std::time_t t = std::time(0);
        std::tm* now = std::localtime(&t);
        return std::to_string(now->tm_year + 1900);
    }
    std::string MonthsNow() {
        std::time_t t = std::time(0);
        std::tm* now = std::localtime(&t);
        return std::to_string(now->tm_mon + 1);
    }
    std::string DayNow() {
        std::time_t t = std::time(0);
        std::tm* now = std::localtime(&t);
        return std::to_string(now->tm_mday);
    }
    std::string DateNow() {
        std::time_t t = std::time(0);
        std::tm* now = std::localtime(&t);
        return std::to_string(now->tm_year + 1900) + "-" + std::to_string(now->tm_mon + 1) + "-" + std::to_string(now->tm_mday) + " "
            + std::to_string(now->tm_hour) + ":" + std::to_string(now->tm_min) + ":" + std::to_string(now->tm_sec);
    }
    std::string DateNow(char x) {
        std::time_t t = std::time(0);
        std::tm* now = std::localtime(&t);
        switch (x) {
        case 't': return std::to_string(now->tm_hour) + ":" + std::to_string(now->tm_min) + ":" + std::to_string(now->tm_sec);
        case 'd': return std::to_string(now->tm_year + 1900) + "-" + std::to_string(now->tm_mon + 1) + "-" + std::to_string(now->tm_mday);
        default:return dt::DateNow();
        }
    }
}

namespace input
{
    template <typename T>
    T GetNumber()
    {
        T num;

        std::cin >> num;

        while (std::cin.fail())
        {
            std::cin.clear();

            std::cin.ignore(
                std::numeric_limits<std::streamsize>::max(),
                '\n'
            );

            std::cout << "Invalid number, please enter a valid one: ";

            std::cin >> num;
        }

        return num;
    }

    template <typename T>
    bool IsBetween(T num, T from, T to)
    {
        return num >= from && num <= to;
    }

    template <typename T>
    T GetNumberInRange(T from, T to)
    {
        while (true)
        {
            T num = GetNumber<T>();

            if (IsBetween(num, from, to))
                return num;

            std::cout << "Please enter a number between "
                << from << " and " << to << ": ";
        }
    }

    std::string ReadString() {
        std::string S1;
        std::cout << "Please Enter Your String?\n";
        getline(cin, S1);
        return S1;
    }

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