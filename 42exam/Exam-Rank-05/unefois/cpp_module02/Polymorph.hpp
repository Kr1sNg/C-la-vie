#ifndef _POLYMORPH_
# define _POLYMORPH_

# include "ASpell.hpp"

class Polymorph: public ASpell
{
    private:
        Polymorph(Polymorph const &src);
        Polymorph  &operator=(Polymorph const &rhs);

    public:
        Polymorph(void);
        ~Polymorph();

        ASpell  *clone(void) const;

};


#endif