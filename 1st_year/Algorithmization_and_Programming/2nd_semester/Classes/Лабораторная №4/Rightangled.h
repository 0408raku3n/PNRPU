#pragma once
#include "pair.h"

class Rightangled : public Pair
{
public:
    Rightangled(void);
    Rightangled(int, int);
    ~Rightangled(void);
    Rightangled(const Rightangled&);

    Rightangled& operator=(const Rightangled&);
    friend istream& operator>>(istream& in, Rightangled& r);
    friend ostream& operator<<(ostream& out, const Rightangled& r);

    int calculatingHypotenuse();
};

