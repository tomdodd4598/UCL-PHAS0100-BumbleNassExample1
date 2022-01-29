#ifndef BOWLER_H
#define BOWLER_H

#include <vector>
#include <string>

namespace lambdas {

    class Bowler {
    public:
        Bowler(std::string&& name, int runs, int balls, int wickets);
        
        double get_average();

        double get_strike_rate();

        double get_economy_rate();

        std::string to_string();

        std::string name;
        int runs;
        int balls;
        int wickets;
    };
}

#endif
