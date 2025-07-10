#include "Warlock.hpp"

Warlock::Warlock(std::string const &n, std::string const &t): name(n), title(t)
{
    std::cout << name << ": This looks like another boring day." << std::endl;
}

Warlock::~Warlock()
{
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
