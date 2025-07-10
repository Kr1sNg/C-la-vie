#ifndef _FWOOSH_
# define _FWOOSH_

# include "ASpell.hpp"

class Fwoosh: public ASpell
{
    private:
        Fwoosh(Fwoosh const &src);
        Fwoosh  &operator=(Fwoosh const &rhs);

    public:
        Fwoosh(void);
        ~Fwoosh();

        ASpell  *clone(void) const;

};


#endif