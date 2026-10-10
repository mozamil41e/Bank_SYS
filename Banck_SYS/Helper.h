#pragma once

#pragma warning(disable : 4996)

#include <iostream>
#include <ctime>
#include <vector>
#include <iomanip>
#include <cstdlib>
#include <string>
#include <fstream>
#include <limits>

using namespace std;

// ============================================================
// Date & Time
// ============================================================

namespace config
{
    //const string UsersFile = "Users.txt";

    const string mark = "#__#";
    const string Tapspace = "\n";

    const string Shape = "*";

    const size_t countP = 60;

    const vector<string> OptionsMainMenu = { "Show All Users .","Show User .","Add New Use .","Exit ." };
    const vector<string> OptionsUserMenu = { "Update Users .","Delete User .","Back ." };
}
// ============================================================
// Date & Time
// ============================================================

namespace dt
{
    tm* GetNow();

    string YearNow();

    string MonthsNow();

    string DayNow();

    string DateNow();

    string DateNow(char x);
}


// ============================================================
// Input
// ============================================================

namespace input
{
    template <typename T>
    T GetNumber(string message = config::Tapspace +"Select option numder ? ")
    {
        T num;

        cout << config::Tapspace << message;

        cin >> num;

        while (cin.fail())
        {
            cin.clear();

            cin.ignore(
                numeric_limits<streamsize>::max(),
                '\n'
            );

            helper::Message("Invalid number, please enter a valid one: "," Erorr ");

            cin >> num;
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

            helper::Message("Please enter a number between "
                + to_string(from)
                + " and "
                + to_string(to)
                + ": ", " Alert ");
        }
    }


    string ReadString(string message);
}


// ============================================================
// Helper
// ============================================================

namespace helper
{
    //const string UsersFile = "Users.txt";

    //const string mark = "#__#";
    //const string Tapspace = "\n\t\t\t\t";

    //const string Shape = "*";

    //const size_t countP = 52;

    //const vector<string> OptionsMainMenu = {"Show All Users .","Show User .","Add New Use .","Exit ."};
    //const vector<string> OptionsUserMenu = {"Update Users .","Delete User .","Back ."};

    // ========================================================
    // User Structure
    // ========================================================

    struct UserStruct
    {
        string accountNumder = "";

        string name = "";

        string username = "";

        string password = "";

        float balancs = 0.00;

        string Cerated_at = "";

        bool deletation = false;
    };


    // ========================================================
    // User Functions
    // ========================================================

    UserStruct ReadNewUser();


    string ConvertUserStructToLine(
        const UserStruct& user
    );


    vector<string> SplitString(
        const string& S1
    );


    UserStruct ConvertLineToRecord(
        const string& Line
    );


    // ========================================================
    // UI Functions
    // ========================================================
    std::string Shapeloop(string shape, size_t count);
    std::string Shapeloop(string shape, size_t count,bool last);
    void PrintShape();
    void PrintShape(string word);
    void PrintText(string mess);
    void PrintText(string mess,bool pause);

    std::string PrintOption(string num, string option);
    void PrintOption(const vector<string>& options);
    void PrintMenuBank();
    void PrintOptionUser();

    void Message(string mess, string type );

    std::string ConfirmMessage(string mess);

    void ShowUser(const UserStruct& user);

    void PrintUserRecord(
        const UserStruct& user
    );


    void PrintAllUsersData(
        const vector<UserStruct>& vUsers
    );
    
}

