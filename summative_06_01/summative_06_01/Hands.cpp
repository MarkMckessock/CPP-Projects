#include "Hands.h"

std::map<Hands::Hands, std::string> Hands::lookup = { {Hands::Straight_flush,"Straight Flush"},{Hands::Six_of_kind,"Six of a Kind"},{Hands::Flush,"Flush"},{Hands::Five_of_kind,"Five of a Kind"},{Hands::Two_three_of_kinds,"Two x Three of a Kind"},{Hands::Four_of_kind_pair,"Four of a Kind and Pair"},{Hands::Four_of_kind,"Four of a Kind"},{Hands::Straight,"Straight"},{Hands::Three_pair,"Three Pairs"},{Hands::Three_kind_pair,"Three of a Kind and Pair"},{Hands::Bust,"Bust"},{Hands::Three_kind,"Three of a Kind"},{Hands::two_pair,"Two Pairs"},{Hands::pair,"Pair"} };