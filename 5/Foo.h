//
// Created by NikBe on 02.05.2023.
//

#ifndef INC_4_FOO_H
#define INC_4_FOO_H


#include <ostream>

class Foo {
private:
    int member_;

public:
    Foo(int arg);

    virtual void ToStream(std::ostream&) const;
};

inline std::ostream& operator<<(std::ostream& stream, const Foo& foo) {
    foo.ToStream(stream);
    return stream;
}


#endif //INC_4_FOO_H
