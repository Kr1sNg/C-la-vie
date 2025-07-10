#include "TargetGenerator.hpp"
#include "ATarget.hpp"

TargetGenerator::TargetGenerator(void)
{
    for (int i = 0; i < 4; ++i)
        _list[i] = NULL;
}
TargetGenerator::~TargetGenerator()
{
    for (int i = 0; i < 4; ++i)
    {
        delete _list[i];
        _list[i] = NULL;
    }
}

void    TargetGenerator::learnTargetType(ATarget *tg)
{
    if (!tg)
        return ;
    for (int i = 0; i < 4; ++i)
    {
        if (_list[i] && _list[i]->getType() == tg->getType())
            return ;
        if (!_list[i])
        {
            _list[i] = tg->clone();
            return ;
        }
    }
}

void    TargetGenerator::forgetTargetType(std::string const &tn)
{
    for (int i = 0; i < 4; ++i)
    {
        if (_list[i] && _list[i]->getType() == tn)
        {
            delete _list[i];
            _list[i] = NULL;
            return ;
        }
    }
}

ATarget *TargetGenerator::createTarget(std::string const &tn)
{
    for (int i = 0; i < 4; ++i)
    {
        if (_list[i] && _list[i]->getType() == tn)
        {
            return _list[i]->clone();
        }
    }
    return NULL;
}
