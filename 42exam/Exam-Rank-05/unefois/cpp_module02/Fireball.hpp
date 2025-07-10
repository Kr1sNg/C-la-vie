#ifndef _FIREBALL_
# define _FIREBALL_

# include "ASpell.hpp"

class Fireball: public ASpell
{
    private:
        Fireball(Fireball const &src);
        Fireball  &operator=(Fireball const &rhs);

    public:
        Fireball(void);
        ~Fireball();

        ASpell  *clone(void) const;

};


#endif