#ifndef _ATARGET_
# define _ATARGET_

# include <string>

class ASpell;

class ATarget
{
    protected:
        std::string type;

        ATarget(ATarget const &src);
        ATarget  &operator=(ATarget const &rhs);

    public:
        ATarget(std::string const &t);
        virtual ~ATarget();

        std::string const &getType(void) const;

        virtual ATarget  *clone(void) const = 0;

        void    getHitBySpell(ASpell const &sp) const;

};


#endif