#ifndef _DUMMY_
# define _DUMMY_

# include "ATarget.hpp"

class Dummy: public ATarget
{
    protected:
        Dummy(Dummy const &src);
        Dummy   &operator=(Dummy const &rhs);

    public:
        Dummy(void);
        ~Dummy();

        ATarget *clone(void) const;

};


#endif