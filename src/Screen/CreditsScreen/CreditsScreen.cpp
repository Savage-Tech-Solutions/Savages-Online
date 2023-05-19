#ifndef CreditsScreen_hpp
#define CreditsScreen_hpp

#include "../Screen.hpp"

struct TeamMembers {
    std::string name;
    std::string role;
    std::string email;
    std::string github;
};

class CreditsScreen : protected Screen {

public:
    CreditsScreen();
    ~CreditsScreen();

    void update();
    void draw();

};



#endif /* CreditsScreen_hpp */