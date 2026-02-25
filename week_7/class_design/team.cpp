#include <sstream>
#include <string>
#include "team.h"

std::string Team::WinLossTieRecord::print() const {
    std::ostringstream oss;
    oss << num_wins << "-" << num_losses << "-" << num_ties;
    return oss.str();
}

std::string Team::name() const {
    return name_;
}

void Team::set_name(const std::string& new_name) {
    name_ = new_name;
}

void Team::add_player(const Player& player) {
    players_.push_back(player);
}

std::string Team::print_roster() const {
    std::ostringstream oss;
    for (const Player& player : players_) {
        oss << player.print() << "\n";
    }
    return oss.str();
}

void Team::update_record(char result) {
    switch (result) {
        case WIN:
            record_.num_wins += 1;
            break;
        case LOSS:
            record_.num_losses += 1;
            break;
        case TIE:
            record_.num_ties += 1;
            break;
    }
}

std::string Team::print_record() const {
    return record_.print();
}
