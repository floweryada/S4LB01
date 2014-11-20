#include "lb5.h"
#include <string>


using namespace std;

Person::Person() {}
Person::Person(const Person& rhs) {}
Person& Person::operator=(const Person& rhs) {}
Person::~Person() {}


Choleric::Choleric(): Person()
{
    charact = 0;

}
Choleric::Choleric(const Choleric& rhs) {}
Choleric& Choleric::operator=(const Choleric& rhs) {}
Choleric::~Choleric(){}


Sanguinik::Sanguinik(): Person()
{
    charact = 1;

}
Sanguinik::Sanguinik(const Sanguinik& rhs) {}
Sanguinik& Sanguinik::operator=(const Sanguinik& rhs) {}
Sanguinik::~Sanguinik(){}


Phlegmatic::Phlegmatic(): Person()
{
    charact = 2;

}
Phlegmatic::Phlegmatic(const Phlegmatic& rhs) {}
Phlegmatic& Phlegmatic::operator=(const Phlegmatic& rhs) {}
Phlegmatic::~Phlegmatic(){}


Melancholic::Melancholic(): Person()
{
    charact = 3;

}
Melancholic::Melancholic(const Melancholic& rhs) {}
Melancholic& Melancholic::operator=(const Melancholic& rhs) {}
Melancholic::~Melancholic(){}

bool Message::can (int mood)
    {
        if (mood > minmood && mood < maxmood)
            return true;
        return false;
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

void Message::putData(string text, string charact, int infl)
    {
        this->text = text;
        this->infl = infl;
        this->chara = charact;
    }

void Person::listen(mess)
{
    changeMood(mess.infl);
}


void Person::addPhrase(string text, int charact, int infl)
{
    if (charact == 0)
    {
        if (quanMess0 != numb)
        ch0[quanMess0++].putData(text, infl);
    }

     if (charact == 1)
    {
        if (quanMess1 != numb)
        ch1[quanMess1++].putData(text, infl);
    }
     if (charact == 2)
    {
        if (quanMess2 != numb)
        ch2[quanMess2++].putData(text, infl);
    }
     if (charact == 3)
    {
        if (quanMess3 != numb)
        ch3[quanMess3++].putData(text, infl);
    }
}

 Message Person::say() const
{

}

