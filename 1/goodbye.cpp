//
// Created by NikBe on 13.04.2023.
//

#include <iostream>

namespace goodbye {
/*
 * Fehler ohne Namespaces
 * Semantic Analyzer???
 *
 * C:/Studium/Semester/4/gip2/praktikum/1/main.cpp:8:6: error: redefinition of 'void tell()'
 *     8 | void tell() {
 *       |      ^~~~
 * C:/Studium/Semester/4/gip2/praktikum/1/main.cpp:4:6: note: 'void tell()' previously defined here
 *     4 | void tell() {
 *       |      ^~~~
 * ninja: build stopped: subcommand failed.
 *
 * Fehler bei zwei headern:
 * linker, ld.exe
 *
 */
    void tell() {
        std::cout << "Goodbye!" << std::endl;
    }
}