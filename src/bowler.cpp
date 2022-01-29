#include "bowler.hpp"

#include <string>

#define DCAST(x) static_cast<double>(x)

namespace lambdas {
    
    Bowler::Bowler(std::string&& name, int runs, int balls, int wickets) : name{name}, runs{runs}, balls{balls}, wickets{wickets} {}

    double Bowler::get_average() {
        return DCAST(runs) / DCAST(wickets);
    }

    double Bowler::get_strike_rate() {
        return DCAST(balls) / DCAST(wickets);
    }

    double Bowler::get_economy_rate() {
        return 6.0 * DCAST(runs) / DCAST(balls);
    }

    std::string Bowler::to_string() {
        return
            "Name: " + name
            + " | Wickets: " + std::to_string(wickets)
            + " | Average: " + std::to_string(get_average())
            + " | Strike Rate: " + std::to_string(get_strike_rate())
            + " | Economy Rate: " + std::to_string(get_economy_rate())
            ;
    }
}
