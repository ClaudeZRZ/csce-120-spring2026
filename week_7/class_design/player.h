#ifndef PLAYER_H_
#define PLAYER_H_

#include <string>

class Player {
 private:
    std::string name_;
    unsigned int jersey_number_;
    std::string position_;

 public:  // everyting that follows is public
    void set_name(const std::string& new_name);
    void set_jersey_number(unsigned int new_jersey_number);
    void set_position(const std::string& new_position);
    std::string name() const;
    std::string position() const;
    unsigned int jersey_number() const;
    std::string print() const;
};

#endif  // PLAYER_H_
