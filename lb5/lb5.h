#ifndef LB5_H
#define LB5_H

#include <string>

using namespace std;


class Message
{
    int infl;
    string text;
    int chara;
    int minmood;
    int maxmood;

    Message(const Message& rhs);
    Message& operator=(Message& rhs);

public:
    Message();
    ~Message();

    bool can (int mood);
    void putData(string text, string charact, int infl);

};

class Person
{
    protected:
        int charact;
        int mood;
        int numb = 10;

        Message *mess;



    public:
        Person();
        Person(const Personr& rhs);
        Person& operator=(const Person& rhs);
        virtual ~Person();

        void changeMood(int infl);
        int getMood() const;

        void addPhrase(string text, int charact, int infl);
        virtual void listen(mess);

        virtual Message say() const;

};


class Choleric: public Person
{
    int quanMess0;
    int *ch0;
    ch0 = new mess[numb];
    public:
        Choleric();
        Choleric(const Choleric& rhs);
        Choleric& operator=(const Choleric& rhs);
        virtual ~Choleric();

};

class Melancholic: public Person
{
    int quanMess1;
    int *ch1;
    ch1 = new mess[numb];
    public:
        Melancholic();
        Melancholic(const Melancholic& rhs);
        Melancholic& operator=(const Melancholic& rhs);
        virtual ~Melancholic();

};

class Phlegmatic: public Person
{
    int quanMess2;
    int *ch2;
    ch2 = new mess[numb];
    public:
        Phlegmatic();
        Phlegmatic(const Phlegmatic& rhs);
        Phlegmatic& operator=(const Phlegmatic& rhs);
        virtual ~Phlegmatic();

};

class Sanguinik: public Person
{
    int quanMess3;
    int *ch3;
    ch3 = new mess[numb];
    public:
        Sanguinik();
        Sanguinik(const Sanguinik& rhs);
        Sanguinik& operator=(const Sanguinik& rhs);
        virtual ~Sanguinik();

};

#endif
