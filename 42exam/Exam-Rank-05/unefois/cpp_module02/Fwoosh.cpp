#include "Fwoosh.hpp"

Fwoosh::Fwoosh(void): ASpell("Fwoosh", "fwooshed")
{
}

Fwoosh::~Fwoosh()
{

}

ASpell  *Fwoosh::clone(void) const
{
    return (new Fwoosh());
}