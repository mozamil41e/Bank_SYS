
#include "Helper.h"

using namespace std;


// ============================================================
// Date & Time
// ============================================================

namespace dt
{
    tm* GetNow()
    {
        time_t t = time(nullptr);
        return localtime(&t);
    }

    string YearNow()
    {
        tm* now = GetNow();

        return to_string(now->tm_year + 1900);
    }

    string MonthsNow()
    {
        tm* now = GetNow();

        return to_string(now->tm_mon + 1);
    }

    string DayNow()
    {
        tm* now = GetNow();

        return to_string(now->tm_mday);
    }

    string DateNow()
    {
        tm* now = GetNow();

        return to_string(now->tm_year + 1900) + "-" +
            to_string(now->tm_mon + 1) + "-" +
            to_string(now->tm_mday) + " " +
            to_string(now->tm_hour) + ":" +
            to_string(now->tm_min) + ":" +
            (now->tm_sec < 10 ? "0"+ to_string(now->tm_sec): to_string(now->tm_sec));
    }

    string DateNow(char x)
    {
        tm* now = GetNow();

        switch (x)
        {
        case 't':
            return to_string(now->tm_hour) + ":" +
                to_string(now->tm_min) + ":" +
                to_string(now->tm_sec);

        case 'd':
            return to_string(now->tm_year + 1900) + "-" +
                to_string(now->tm_mon + 1) + "-" +
                to_string(now->tm_mday);

        default:
            return DateNow();
        }
    }
}


// ============================================================
// Input
// ============================================================

namespace input
{
    string ReadString(string message)
    {
        string value;

        cout << config::Tapspace << message;
        getline(cin >> ws, value);

        return value;
    }
}


// ============================================================
// Helper
// ============================================================

namespace helper
{
    UserStruct ReadNewUser()
    {
        UserStruct user;

        user.accountNumder =
            input::ReadString("Enter Account Number for user ? ");

        user.name =
            input::ReadString("Enter name for user ? ");

        user.username =
            input::ReadString("Enter username for user ? ");

        user.password =
            input::ReadString("Enter password for user ? ");

        user.balancs =
            input::GetNumber<float>("Enter Account Balance for user ? ");

        return user;
    }


    // ========================================================
    // Convert UserStruct -> String
    // ========================================================

    string ConvertUserStructToLine(const UserStruct& user)
    {
        return user.accountNumder +
            config::mark +
            user.name +
            config::mark +
            user.username +
            config::mark +
            user.password +
            config::mark +
            to_string(user.balancs) +
            config::mark +
            dt::DateNow();
    }


    // ========================================================
    // Split String
    // ========================================================

    vector<string> SplitString(const string& S1)
    {
        vector<string> vString;

        size_t start = 0;
        size_t pos = 0;

        while ((pos = S1.find(config::mark, start)) != string::npos)
        {
            string sWord = S1.substr(start, pos - start);

            vString.push_back(sWord);

            start = pos + config::mark.length();
        }

        // Add last field
        vString.push_back(S1.substr(start));

        return vString;
    }


    // ========================================================
    // Convert String -> UserStruct
    // ========================================================

    UserStruct ConvertLineToRecord(const string& Line)
    {
        UserStruct user;

        vector<string> vUserData = SplitString(Line);

        user.accountNumder = vUserData[0];
        user.name = vUserData[1];
        user.username = vUserData[2];
        user.password = vUserData[3];
        user.balancs = stof(vUserData[4]);
        user.Cerated_at = vUserData[5];

        return user;
    }


    // ========================================================
    // UI
    // ========================================================

    void PrintText(string mess = "Please Any Key For GoTo Menu : ")
    {
        cout << config::Tapspace << mess;
    }
    void PrintText(string mess = "Please Any Key For GoTo Menu : ",bool pause = true)
    {
        cout << config::Tapspace << mess;
        if (pause) {
            system("pause>0");
        }
    }

    std::string Shapeloop(string shape , size_t count) {
        string s = "";
        for (short i = 0;i < count;i++)
            s += shape;
        return s;
    }
    std::string Shapeloop(string shape , size_t count,bool last) {
        string s = "";
        for (short i = 1;i < count;i++)
            s += " ";
        return s+=config::Shape;
    }

    void PrintShape() {
        cout << config::Tapspace << Shapeloop(config::Shape, config::countP); //****************************************************\n";
    }
    void PrintShape(string word) {
        string shape = config::Tapspace + Shapeloop(config::Shape, 4) + word + Shapeloop(config::Shape, config::countP - 4 - word.length());// +"\n";
        cout << shape;
    }

    void Message(string mess, string word = " Success ") {
        //cout << "\n\t\t\t\t**** " << setw(7) << left << type << " ********************************************\n";
        PrintShape(word);
        cout << config::Tapspace << config::Shape + mess << Shapeloop(config::Shape, config::countP - config::Shape.length() - mess.length(), true);// << "\n";
        PrintShape();
        return;
    }

    std::string ConfirmMessage(string mess) {
        //cout << "\n\t\t\t\t**** Confirmation ********************************************\n";
        PrintShape(" Confirmation ");
        cout << config::Tapspace << config::Shape << " " << mess;
        return input::ReadString(config::Shape + "->");
    }

    void ShowUser(const UserStruct& user)
    {
        if (user.accountNumder == "") {
            Message(" User Not Faund ):- "," info ");
            return;
        }
        PrintShape();

        std::string s = "";

        s = config::Shape + " Account Number " + "  : " + user.accountNumder;
        cout << config::Tapspace << s <<Shapeloop(config::Shape, config::countP - s.length(), true);

		s = config::Shape + " Account name " + "    : " + user.name;
		cout << config::Tapspace << s << Shapeloop(config::Shape, config::countP - s.length(), true);

		s = config::Shape + " Account username " + ": " + user.username;
		cout << config::Tapspace << s << Shapeloop(config::Shape, config::countP - s.length(), true);

		s = config::Shape + " Account balancs " + " : " + to_string(user.balancs);
		cout << config::Tapspace << s << Shapeloop(config::Shape, config::countP - s.length(), true);

		s = config::Shape + " Created At " + "      : " + user.Cerated_at;
        cout << config::Tapspace << s << Shapeloop(config::Shape, config::countP - s.length(), true);

        PrintShape();
        return;
    }

    void PrintUserRecord(const UserStruct& user)
    {
        
        cout << "| " << setw(15) << left
            << user.accountNumder;

        cout << "| " << setw(30) << left
            << user.name;

        cout << "| " << setw(25) << left
            << user.username;

        printf("| $ %-17.2f ", user.balancs);

        cout << "| " << setw(18) << left
            << user.Cerated_at;
        cout << "|" << endl;
    }


    void PrintAllUsersData(const vector<UserStruct>& vUsers)
    {
        cout << config::Tapspace << "Client List ("
            << vUsers.size()
            << ") Client(s).";

        cout << "\n______________________________________________________________________________";
        cout << "_________________________________________\n\n";

        cout << "| " << left << setw(15) << "Account Number";
        cout << "| " << left << setw(30) << "Client Name";
        cout << "| " << left << setw(25) << "Client UserName";
        cout << "| " << left << setw(20) << "Balance";
        cout << "| " << left << setw(18) << "Created_At";

        cout << "|\n______________________________________________________________________________";
        cout << "_________________________________________\n\n";


        for (const UserStruct& user : vUsers)
        {
            PrintUserRecord(user);

            //cout << "|" << endl;
        }


        cout << "\n______________________________________________________________________________";
        cout << "_________________________________________\n";
    }

    std::string PrintOption(string num,string option) {
        string s = config::Shape + "  [" + num + "] " + option;
        return config::Tapspace + s + Shapeloop(config::Shape, config::countP - s.length(), true);
    }
    void PrintOption(const vector<string>& options) {
        short i = 1;
        for (const string& option : options) {
           cout <<PrintOption(to_string(i),option);
           i++;
        }
    }

    void PrintMenuBank()
    {
        
        PrintShape(" Bank SYS ("+ dt::DateNow() +") ");

        PrintShape();

        PrintOption(config::OptionsMainMenu);

        PrintShape();

    }

    void PrintOptionUser()
    {
        PrintShape(" User Menu ");

        PrintOption(config::OptionsUserMenu);

        PrintShape();
       
    }

}

