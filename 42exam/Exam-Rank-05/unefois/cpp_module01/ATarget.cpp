#include "ATarget.hpp"
#include "ASpell.hpp"

ATarget::ATarget(std::string const &t): type(t)
{
}

ATarget::~ATarget()
{
}

std::string const &ATarget::getType(void) const
{
    return (type);
}

void    ATarget::getHitBySpell(ASpell const &sp) const
{
    std::cout << type << " has been " << sp.getEffects() << "!" << std::endl;
}
