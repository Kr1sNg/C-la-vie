#ifndef _BRICKWALL_
# define _BRICKWALL_

# include "ATarget.hpp"

class BrickWall: public ATarget
{
    protected:
        BrickWall(BrickWall const &src);
        BrickWall   &operator=(BrickWall const &rhs);

    public:
        BrickWall(void);
        ~BrickWall();

        ATarget *clone(void) const;

};


#endif