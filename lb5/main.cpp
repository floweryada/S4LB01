#include <iostream>
#include "lb5.h"
#include <string>
#include <conio.h>

using namespace std;

int minMood = 0;
int maxMood = 10;

void createDialog(Person *first, Person *second)
    {
        Message message;
        string ans;
        cout << "Do you want to create dialogue? [yes/no]" << endl;
        cin >> ans;
            while (ans == "yes")
            {

                message = first->say();
                cout << "first[" << first->getMood() << "]: " << message.text << endl;
                second->listen(message);

                message = second->say();
                cout << "second[" << second->getMood() << "]: " << message.text << endl;
                first->listen(message);
                getch();
            }
    }

int main()
{
    Person *per1, *per2;

        int c1, c2, m1, m2;
        cout << "Enter the one of characters of people:" << endl;
        cout << "0 - Choleric, 1 - Sanguinik" << endl;
        cout << "2 - Phlegmatic, 3 - Melanholic" << endl;
        cout << "The character of first person: ";
        cin >> c1;
            if (c1 == 0)
                per1 = new Choleric;
            if (c1 == 1)
                per1 = new Sanguinik;
            if (c1 == 2)
                per1 = new Phlegmatic;
            if (c1 == 3)
                per1 = new Melancholic;
        per1 -> NewMood(per1 -> getMood());

        cout << "\n";
        cout << "The character of first person: ";
        cin >> c2;
        if (c2 == 0)
                per2 = new Choleric;
            if (c2 == 1)
                per2 = new Sanguinik;
            if (c2 == 2)
                per2 = new Phlegmatic;
            if (c2 == 3)
                per2 = new Melancholic;
        cout << endl;
        per2 -> NewMood(per2->getMood());

    per1 -> addPhrase("1C+", +1);
    per1 -> addPhrase("1S+", +1);
    per1 -> addPhrase("1M+", +1);
    per1 -> addPhrase("1P+", +1);
    per1 -> addPhrase("1C-", -1);
    per1 -> addPhrase("1S-", -1);
    per1 -> addPhrase("1M-", -1);
    per1 -> addPhrase("1P-", -1);

    per2 -> addPhrase("2C+", +1);
    per2 -> addPhrase("2S+", +1);
    per2 -> addPhrase("2M+", +1);
    per2 -> addPhrase("2P+", +1);
    per2 -> addPhrase("2C-", -1);
    per2 -> addPhrase("2S-", -1);
    per2 -> addPhrase("2M-", -1);
    per2 -> addPhrase("2P-", -1);


    createDialog(per1, per2);

    return 0;
}



/*
cout << "Enter the mood of first person [1-10]: ";
        cin >> m1;
        per1 -> mood == m1;
        cout << "\n";
        cout << "Enter the mood of second person [1-10]: ";
        cin >> m2;
        per1.mood == m1;
        cout << endl;
*/
