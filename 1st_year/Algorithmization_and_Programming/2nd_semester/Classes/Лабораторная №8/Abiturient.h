#pragma once
#include "Person.h"
class Abiturient :
    public Person
{
public:
    Abiturient();
    ~Abiturient();
    void Show();
    void Input();
    Abiturient(string, int, int, string);
    Abiturient(const Abiturient&);

    int getScore() { return score; }
    string getSpeciality() { return spec; }

    void setScore(int);
    void setSpec(string);

    Abiturient& operator=(const Abiturient&);
protected:
    int score;
    string spec;
   

};

