#include "Warlock.hpp"
#include "ASpell.hpp"
#include "ATarget.hpp"

Warlock::Warlock(std::string const &n, std::string const &t): name(n), title(t)
{
    for (int i = 0; i < 4; ++i)
        _spells[i] = NULL;
    std::cout << name << ": This looks like another boring day." << std::endl;
}

Warlock::~Warlock()
{
    for (int i = 0; i < 4; ++i)
    {
        delete _spells[i];
        _spells[i] = NULL;
    }
    std::cout << name << ": My job here is done!" << std::endl;
}

std::string const   &Warlock::getName(void) const
{
    return (name);
}

std::string const   &Warlock::getTitle(void) const
{
    return (title);
}

void    Warlock::setTitle(std::string const &s)
{
    title = s;
}

void    Warlock::introduce() const
{
    std::cout << name << ": I am " << name << ", " << title << "!" << std::endl;
}

void    Warlock::learnSpell(ASpell *sp)
{
    if (!sp)
        return ;
    for (int i = 0; i < 4; ++i)
    {
        if (_spells[i] && _spells[i]->getName() == sp->getName())
            return ;
        if (!_spells[i])
        {
            _spells[i] = sp->clone();
            return ;
        }
    }
}

void    Warlock::forgetSpell(std::string const &sn)
{
    for (int i = 0; i < 4; ++i)
    {
        if (_spells[i] && _spells[i]->getName() == sn)
        {
            delete _spells[i];
            _spells[i] = NULL;
            return ;
        }
    }
}

void    Warlock::launchSpell(std::string const &sn, ATarget const &target)
{
    for (int i = 0; i < 4; ++i)
    {
        if (_spells[i] && _spells[i]->getName() == sn)
        {
            _spells[i]->launch(target);
            return ;
        }
    }
}
