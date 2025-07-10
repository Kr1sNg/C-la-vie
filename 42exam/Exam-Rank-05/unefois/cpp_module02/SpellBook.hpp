#ifndef _SPELLBOOK_
# define _SPELLBOOK_

# include <string>
# include "ASpell.hpp"

class SpellBook
{
    private:
        ASpell  *_book[4];

        SpellBook(SpellBook const &src);
        SpellBook   &operator=(SpellBook const &rhs);

    public:
        SpellBook(void);
        ~SpellBook();

        void    learnSpell(ASpell *sp);
        void    forgetSpell(std::string const &sn);
        ASpell  *createSpell(std::string const &sn);

};


#endif