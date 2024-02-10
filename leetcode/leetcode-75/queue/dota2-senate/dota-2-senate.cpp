#include "dota-2-senate.h"

std::string Dota2Senate::predictPartyVictory(std::string senate) const {
    int radiant = 0;
    int dire = 0;
    std::queue<char> senators;

    for (const char senator : senate) {
        senators.push(senator);
        if (senator == 'R') {
            radiant += 1;
        } else {
            dire += 1;
        }
    }

    char senator;
    int eliminate_radiant = 0;
    int eliminate_dire = 0;
    while (!senators.empty()) {
        senator = senators.front();
        senators.pop();
        if (senator == 'R') {
            if (eliminate_radiant > 0) {
                radiant -= 1;
                eliminate_radiant -= 1;
                continue;
            }
            eliminate_dire += 1;
        } else {
            if (eliminate_dire > 0) {
                dire -= 1;
                eliminate_dire -= 1;
                continue;
            }
            eliminate_radiant += 1;
        }

        if (radiant == 0 || dire == 0) {
            break;
        }
        senators.push(senator);
    }

    return (senator == 'R') ? "Radiant" : "Dire";
}
