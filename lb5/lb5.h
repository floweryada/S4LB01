#ifndef LB5_H
#define LB5_H

#include <string>

class Message
{
private:
    std::string text;
    int minmood = 0;
    int maxmood = 10;
    int infl;
public:
    bool can (int mood);
    void putData(std::string text, int infl);
    std::string getText();
    int getInfl();
};

class Person
{
    protected:
        int mood = 5;
        Message *mess;
        int messNumb;
        int maxMess = 50;


    public:
        Person();
        Person(const Person& rhs);
        Person& operator=(const Person& rhs);
        virtual ~Person();


        void changeMood(int infl);
        int getMood() const;

        void addPhrase(std::string text, int infl);

        int NewMood(int curMood)
        {
            return curMood;
        }


        void listen(Message);

        Message say() const;

};


class Choleric: public Person
{
        Choleric(const Choleric& rhs) {};
        Choleric& operator=(const Choleric& rhs) {};

public:
    Choleric(): Person() {};
    ~Choleric() {};
    virtual int NewMood(int curMood)
    {
        return (2*curMood);
    }
};

class Melancholic: public Person
{
        Melancholic(const Melancholic& rhs) {};
        Melancholic& operator=(const Melancholic& rhs) {};
    public:
        Melancholic(): Person() {};
        ~Melancholic() {};
    virtual int NewMood(int curMood)
    {
        return (curMood/2);
    }
};

class Phlegmatic: public Person
{
        Phlegmatic(const Phlegmatic& rhs) {};
        Phlegmatic& operator=(const Phlegmatic& rhs) {};
    public:
        Phlegmatic(): Person() {};
        ~Phlegmatic() {};
    virtual int NewMood(int curMood)
    {
        return (curMood-2);
    }
};

class Sanguinik: public Person
{
        Sanguinik(const Sanguinik& rhs) {};
        Sanguinik& operator=(const Sanguinik& rhs) {};
    public:
        Sanguinik(): Person() {};
        ~Sanguinik() {};

virtual int NewMood(int curMood)
    {
        return (2+curMood);
    }
};

#endif
