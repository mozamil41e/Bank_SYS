#pragma once

#include <string>
#include <vector>
#include "Helper.h"

namespace User
{
    const string UsersFile = "Users.txt";

    helper::UserStruct Find(string accountNumder);

    bool Create();

    std::vector<helper::UserStruct> All();


    bool Delete(string accountNumder, std::vector<helper::UserStruct>& Users);
}