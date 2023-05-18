#ifndef Game_hpp
#define Game_hpp

#include "Main/Main.hpp"

using namespace std;

// Function Prototypes

class Game : protected Screen {
    public:
        Screen();
        ~Screen();
        void run();
        void printVersion();
        void printHelp();
        void printUsersOnline();
        void printLicense();
        void printContributors();

    protected:
        void setVersion(string version) const;
        void setHelp(string help);
        void setUsersOnline(string usersOnline);
        void setLicense(string license);
        void setContributors(string contributors);

    private:
        string version;
        string help;
        string usersOnline;
        string license;
        string contributors;
};


#endif /* Game_hpp */