#include "lb5.h"
#include <string>
#include <cstdlib>
#include <ctime>


using namespace std;

Person::Person()
{
    mood = 5;
    messNumb = 5;
    mess = new Message;
    mess[0].putData("phrase", +2);
}

Person::Person(const Person& rhs) {}
Person& Person::operator=(const Person& rhs) {}
Person::~Person() {}


bool Message::can (int mood)
    {
        if (mood > 0 && mood < 10)
            return true;
        return false;
    }

void Message::putData(string text, int infl)
    {
        this -> text = text;
        this -> infl = infl;
    }

void Person::changeMood(int infl)
{
    mood = mood + infl;
    if (mood < 0)
        mood = 0;
    else if (mood > 10)
        mood = 10;
}

int Person::getMood() const
{
    return mood;
}

void Person::addPhrase(string text, int infl)
{
    if (messNumb != maxMess)
        mess[messNumb++].putData(text, infl);
}


void Person::listen(Message mess)
{
    changeMood(mess.infl);
}

 Message Person::say() const
{
    srand(time(NULL));
    int em = rand() % 10;
    for (int i = 0; i < messNumb; i++)
        return mess[i];
    return *(new Message());
}

