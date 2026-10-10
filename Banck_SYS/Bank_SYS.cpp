#include <iostream>
#include <vector>
#include "Helper.h"
#include "User.h"
#include <cstdlib>

using namespace std;

void runApp()
{
    while (true)
    {
        system("cls");

        helper::PrintMenuBank();

        short option = input::GetNumberInRange(1, 4);

        switch (option)
        {
            case 1:
            {
                system("cls");
            
                helper::PrintAllUsersData(User::All());
            
                helper::PrintText("Please Any Key For GoTo Menu : ", true);

                break;
            }

            case 2:
            {
                //string AccountNumder = input::ReadString("Enter account numder for user : ");
                string AccountNumder = input::ReadString("Enter account numder for user : ");
                bool stopWhile = true;
                while (stopWhile) {
                    system("cls");
                    helper::UserStruct user = User::Find(AccountNumder);
                    helper::ShowUser(user);
                    if (user.accountNumder != "") {
                        helper::PrintOptionUser();
                        short option = input::GetNumberInRange(1, 3);

                        switch (option) {
                        case 2:
                        {

                            string Confirm = helper::ConfirmMessage("If you want delete account write (" + user.username + ") ");
                            if (Confirm == user.username) {
                                vector <helper::UserStruct> Users = User::All();
                                stopWhile = !User::Delete(AccountNumder, Users);

                                helper::Message(" Successful deletion the user (" + user.username + ")!", " Success ");
                                
                            }
                            else helper::PrintText("Failed to delete the user decause the username is incorrect ...");

                            break;
                        }
                        case 3:
                        {
                            stopWhile = !stopWhile;
                            break;
                        }
                        }
                    }
                    //cout << "\t\t\t\t";system("pause");
                    AccountNumder = input::ReadString("Enter account numder for user Or (m) for goto Menu : ");
                    stopWhile = (AccountNumder == "m") ? false : true;
                }

                break;
            
            }

            case 3:
            {
                while (true) {
                    system("cls");

                    if (User::Create()) {
                        system("cls");
                        helper::Message(" User Added Successfully..!", " Success ");
                    }
                    else {
                        system("cls");
                        helper::Message(" The user already exists..!", " Info ");
                    }

                    string AccountNumder = input::ReadString("Enter ( Y Or y ) for add another new user Or anything for goto Menu : ");
                    if(AccountNumder != "y" && AccountNumder != "Y") break;
                }
                break;
           
            }

            case 4:
            {
                cout << config::Tapspace << "exit...\n\n";
                return;
            }
        }
    }
}
int main()
{
    runApp();

    //cout << helper::Shape("*",10);
    //helper::PrintShape(" opo ");
    //helper::PrintShape(" oiofgldfljhjd gjhgjh ");
    //string s = "";
    //s.append("fsd");

    //cout << s;

    system("pause>0");
    return 0;
}


