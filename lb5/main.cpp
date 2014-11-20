#include <iostream>
#include "lb.h"
#include <string>

using namespace std;

int minMood = 0;
int maxMood = 10;

int main()
{

    Person per1, per2;

    per1.addPhrase("1C+", 0, +1);
    per1.addPhrase("1S+", 1, +1);
    per1.addPhrase("1M+", 2, +1);
    per1.addPhrase("1P+", 3, +1);
    per1.addPhrase("1C-", 0, -1);
    per1.addPhrase("1S-", 1, -1);
    per1.addPhrase("1M-", 2, -1);
    per1.addPhrase("1P-", 3, -1);

    per2.addPhrase("2C+", 0, +1);
    per2.addPhrase("2S+", 1, +1);
    per2.addPhrase("2M+", 2, +1);
    per2.addPhrase("2P+", 3, +1);
    per2.addPhrase("2C-", 0, -1);
    per2.addPhrase("2S-", 1, -1);
    per2.addPhrase("2M-", 2, -1);
    per2.addPhrase("2P-", 3, -1);


    createDialog(&per1, &per2);

    return 0;
}

void createDialog(Person *first, Person *second)
    {
        Message message;
        string ans, an;
        cout << "Do you want to create dialogue? [yes/no]" << endl;
        cin >> ans;
        if (ans == "yes")
        {
            int c1, c2, m1, m2;
            cout << "Enter the one of characters of people:" << endl;
            cout << "0 - Choleric, 1 - Sanguinik" << endl;
            cout << "2 - Phlegmatic, 3 - Melanholic" << endl;
            cout << "The character of first person: ";
            cin >> c1;
            cout << "\n";
            cout << "The character of first person: ";
            cin >> c2;
            cout << endl;
            cout << "Enter the mood of first person [1-10]: ";
            cin >> m1;
            cout << "\n";
            cout << "Enter the mood of second person [1-10]: ";
            cin >> m2;
            cout << endl;

            cout << "Do you want to start dialogue? [yes/no]" << endl;
            cin >> an;
            while (an == "yes")
            {
                message = first->say();
                cout << "first[" << first->getMood() << "]: " << message.text << endl;
                second->listen(phrase);

                message = second->say();
                cout << "second[" << second->getMood() << "]: " << message.text << endl;
                first->listen(phrase);

                cout << "Do you want to continue the dialogue? [yes/no]" << endl;
                cin >> an;
            }
        }
