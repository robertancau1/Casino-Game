#include <ctime>
#include <iostream>

using namespace std;

int deposit = 0, bet = 0, number = 0, message2;
string message;

void table()
{
    cout << "------------------------------------------------" << endl;
    cout << "|                                              |" << endl;
    cout << "|   " << "Your deposit: " << deposit << "                            " << endl;
    cout << "|                                              |" << endl;
    cout << "|                                              |" << endl;
    cout << "|             " << "Last bet's result: " << message << "            " << endl;
    cout << "|             " << "Secret number was: " << message2 << endl;
    cout << "|                                              |" << endl;
    cout << "|                                              |" << endl;
    cout << "|   " << "Your bet: " << bet << "                                " << endl;
    cout << "|                                              |" << endl;
    cout << "------------------------------------------------" << endl;
    return;
}

int main()
{
    cout << "Please deposit your money: " << endl;
    bool ok = true;
    while (ok == true)
    {
        cin >> deposit;
        if (deposit > 0 && deposit <= 1000000)
        {
            cin.clear();
            cin.ignore();
            ok = false;

        }
        else
        {
            cout << "Invalid Deposit" << endl;
            cin.clear();
            cin.ignore();
        }
    }
    table();
    int tries = 3, guesstries = 0, YourNumber = 0;
    while (deposit != 0)
    {
        cout << "Please place your bet: " << endl;
        ok = true;
        while (ok == true)
        {
            cin >> bet;
            if (bet >= 0 && bet <= deposit)
            {
                cin.clear();
                cin.ignore();
                ok = false;
            }
            else
            {
                cout << "Invalid Bet" << endl;
                cin.clear();
                cin.ignore();
            }
        }
        system("cls");
        table();
        srand((unsigned)time(0));
        number = (rand() % 10) + 1;
        guesstries = 0;
        while (guesstries != tries)
        {
            cout << "Your guess: " << endl;
            ok = true;
            while (ok == true)
            {
                cin >> YourNumber;
                if (YourNumber >= 1 && YourNumber <= 10)
                {
                    cin.clear();
                    cin.ignore();
                    ok = false;
                }
                else
                {
                    cout << "Invalid Guess" << endl;
                    cin.ignore();
                    cin.clear();
                }
            }
            if (YourNumber == number)
            {
                deposit += (bet * 10);

                message = "You Win!";
                break;
            }
            else
            {
                guesstries++;
            }
        }
        message2 = number;
        if (guesstries == 3)
        {
            deposit -= bet;
            message = "You lost!";
        }
        system("cls");
        table();

    }
    if (deposit == 0)
    {
        cout << "You don't have any money left" << endl;
    }
}