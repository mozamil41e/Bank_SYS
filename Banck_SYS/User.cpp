#include "User.h"

namespace User
{
    bool Create()
    {
        std::ofstream MyFile;

        MyFile.open(UsersFile, std::ios::out | std::ios::app);

        if (!MyFile.is_open())
        {
            return false;
        }

        helper::UserStruct user = helper::ReadNewUser();

        //check user if exists .  
        if(Find(user.accountNumder).accountNumder != "")return false;

        MyFile << helper::ConvertUserStructToLine(user) << std::endl;

        MyFile.close();

        return true;
    }

    std::vector<helper::UserStruct> All()
    {
        std::vector<helper::UserStruct> vClients;

        std::ifstream MyFile;//only read

        MyFile.open(UsersFile, std::ios::in);

        if (!MyFile.is_open())
        {
            return vClients;
        }

        std::string Line;

        while (getline(MyFile, Line))
        {
            helper::UserStruct user =
                helper::ConvertLineToRecord(Line);

            vClients.push_back(user);
        }

        MyFile.close();

        return vClients;
    }

    helper::UserStruct Find(string accountNumder) {
        std::vector<helper::UserStruct> Users = All();
        helper::UserStruct user;
        for (helper::UserStruct &use : Users) {
            if (use.accountNumder == accountNumder)
                user = use;
        }

        return user;
    }

    bool Delete(string accountNumder , std::vector<helper::UserStruct>& Users) {
        for (helper::UserStruct& user : Users) {
            if (user.accountNumder == accountNumder)
                user.deletation = true;
        }
        std::ofstream MyFile;

        MyFile.open(UsersFile, std::ios::out);

        if (!MyFile.is_open())
        {
            return false;
        }
        for (helper::UserStruct& user : Users) {
            if(!user.deletation)
            MyFile << helper::ConvertUserStructToLine(user) << std::endl;
        }

        MyFile.close();

        return true;
    }
}