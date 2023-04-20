//
// Created by NikBe on 19.04.2023.
//

#ifndef INC_3_COUNTERCATALOGUE_H
#define INC_3_COUNTERCATALOGUE_H


#include <string>
#include <map>
#include "Counter.h"

class CounterCatalogue {
private:
    std::map<const std::string, Counter*> counters_;
public:
    Counter &Add(const std::string &name);

    void Touch(const std::string &name, unsigned int increment);

    void Print() const;

    std::ostream &WriteToStream(std::ostream &stream) const;

    std::istream &ReadFromStream(std::istream &stream);
};

inline std::ostream &operator<<(std::ostream &stream, const CounterCatalogue& counters) {
    return counters.WriteToStream(stream);
}

inline std::istream &operator>>(std::istream &stream, CounterCatalogue& counters) {
    return counters.ReadFromStream(stream);
}


#endif //INC_3_COUNTERCATALOGUE_H
