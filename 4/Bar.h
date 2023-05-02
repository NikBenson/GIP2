//
// Created by NikBe on 02.05.2023.
//

#ifndef INC_4_BAR_H
#define INC_4_BAR_H


#include "Foo.h"

class Bar : public Foo {
public:
    Bar(int arg);

    void ToStream(std::ostream&) const override;
};

inline std::ostream& operator<<(std::ostream& stream, const Bar& bar) {
    bar.ToStream(stream);
    return stream;
}


#endif //INC_4_BAR_H
