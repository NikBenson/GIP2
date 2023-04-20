//
// Created by NikBe on 19.04.2023.
//

#ifndef INC_3_COUNTER_H
#define INC_3_COUNTER_H


#include <string>

class Counter {
private:
    std::string name_{0};
    unsigned int count_ = 0;

public:
    explicit Counter(const std::string& name);

    void Touch(unsigned int increment);

    void Print() const;

    std::ostream& WriteToStream(std::ostream& stream) const;
    std::istream& ReadFromStream(std::istream& stream);

    bool operator<(const Counter& other) const;
    bool operator>(const Counter& other) const;
    bool operator==(const Counter& other) const;
};

inline std::ostream & operator<<(std::ostream& stream, const Counter& counter) {
    return counter.WriteToStream(stream);
}

inline std::istream & operator>>(std::istream& stream, Counter& counter) {
    return counter.ReadFromStream(stream);
}


#endif //INC_3_COUNTER_H
