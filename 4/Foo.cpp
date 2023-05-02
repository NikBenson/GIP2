//
// Created by NikBe on 02.05.2023.
//

#include "Foo.h"

Foo::Foo(int arg) {
    member_ = arg;
}

void Foo::ToStream(std::ostream & stream) const {
    stream << "Foo" << " " << member_;
}
