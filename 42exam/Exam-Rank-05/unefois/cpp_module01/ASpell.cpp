#include "ASpell.hpp"
#include "ATarget.hpp"


ASpell::ASpell(std::string const &n, std::string const &e): name(n), effects(e)
{
}

ASpell::~ASpell()
{
}

std::string const &ASpell::getName(void) const
{
    return (name);
}

std::string const &ASpell::getEffects(void) const
{
    return (effects);
}

void    ASpell::launch(ATarget const &target) const
{
    target.getHitBySpell(*this);
}

