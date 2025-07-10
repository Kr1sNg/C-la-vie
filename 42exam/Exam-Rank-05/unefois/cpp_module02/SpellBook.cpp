#include "SpellBook.hpp"

SpellBook::SpellBook(void)
{
    for (int i = 0; i < 4; ++i)
        _book[i] = NULL;
}

SpellBook::~SpellBook()
{
    for (int i = 0; i < 4; ++i)
    {
        delete _book[i];
        _book[i] = NULL;
    }
}

void    SpellBook::learnSpell(ASpell *sp)
{
    if (!sp)
        return ;
    for (int i = 0; i < 4; ++i)
    {
        if (_book[i] && _book[i]->getName() == sp->getName())
            return ;
        if (!_book[i])
        {
            _book[i] = sp->clone();
            return ;
        }
    }
}

void    SpellBook::forgetSpell(std::string const &sn)
{
    for (int i = 0; i < 4; ++i)
    {
        if (_book[i] && _book[i]->getName() == sn)
        {
            delete _book[i];
            _book[i] = NULL;
            return ;
        }
    }
}

ASpell  *SpellBook::createSpell(std::string const &sn)
{
    for (int i = 0; i < 4; ++i)
    {
        if (_book[i] && _book[i]->getName() == sn)
            return _book[i]->clone();
    }
    return NULL;
}


