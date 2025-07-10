#ifndef _WARLOCK_
# define _WARLOCK_

#include <string>
#include <iostream>

class Warlock
{
    private:
        std::string name;
        std::string title;

        Warlock(void);
        Warlock(Warlock const &src);
        Warlock &operator=(Warlock const &rhs);

    public:
        Warlock(std::string const &n, std::string const &t);
        ~Warlock();

        std::string const   &getName(void) const;
        std::string const   &getTitle(void) const;
        void    setTitle(std::string const &s);
        void    introduce() const;

};

#endif