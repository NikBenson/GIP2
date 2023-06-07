//
// Created by NikBe on 02.05.2023.
//

#include "Bar.h"

Bar::Bar(int arg) : Foo(arg) {
}

void Bar::ToStream(std::ostream & stream) const {
    stream << "Bar" << " ";
    return Foo::ToStream(stream);
}
