#ifndef _TARGEN_
# define _TARGEN_

# include <string>

class ATarget;

class TargetGenerator
{
    private:
        ATarget *_list[4];

        TargetGenerator(TargetGenerator const &src);
        TargetGenerator &operator=(TargetGenerator const &rhs);

    public:
        TargetGenerator(void);
        ~TargetGenerator();

        void    learnTargetType(ATarget *tg);
        void    forgetTargetType(std::string const &tn);
        ATarget *createTarget(std::string const &tn);

};


#endif