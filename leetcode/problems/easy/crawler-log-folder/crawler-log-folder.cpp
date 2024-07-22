#include "crawler-log-folder.hpp"

int CrawlerLogFolder::minOperations(const std::vector<std::string>& logs) const {
    int result = 0;
    for (const std::string& log : logs) {
        if (log == "./") {
            continue;
        }

        if (log[0] != '.') {
            result += 1;
        } else {
            if (result > 0) {
                result -= 1;
            }
        }
    }
    return result;
}