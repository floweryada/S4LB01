#ifndef PRCONSOLE_H
#define PRCONSOLE_H


class PrettyConsoleTree:

    public Console
{
    private:
        virtual void ShowPrettyTree();

    public:
        void ShowPrettyAll();

};

#endif // PRCONSOLE_H
