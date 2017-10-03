#ifndef RAT_H
#define RAT_H

#include <string>
#include "creature.h"

using namespace std;

///Rat class. Instantiable.
/**
 * A simple rat.
 */
class Rat: public Rodent {
private:
protected:
public:
    Rat(
        int=1,
        int=1,
        int=1,
        int=1,
        int=1,
        int=1,
        int=1,
        int=1
    );
    ~Rat();
};

///Giant Rat class. Instantiable.
/**
 * A giant rat. Not to be taken as lightly as regular rats.
 */
class GiantRat: public Rodent {
private:
protected:
public:
    GiantRat(
            int=3,
            int=4,
            int=3,
            int=3,
            int=3,
            int=3,
            int=3,
            int=2
    );
    ~GiantRat();
};
#endif //RAT_H
