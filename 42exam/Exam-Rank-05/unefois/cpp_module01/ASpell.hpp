#ifndef _ASPELL_
# define _ASPELL_

# include <string>
# include <iostream>

class ATarget;

class ASpell
{
    protected:
        std::string name;
        std::string effects;

        ASpell(ASpell const &src);
        ASpell  &operator=(ASpell const &rhs);

    public:
        ASpell(std::string const &n, std::string const &e);
        virtual ~ASpell();

        std::string const &getName(void) const;
        std::string const &getEffects(void) const;

        virtual ASpell  *clone(void) const = 0;

        void    launch(ATarget const &target) const;

};


#endif