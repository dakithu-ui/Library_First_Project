#ifndef BOOKMANAGER_H
#define BOOKMANAGER_H

#include "Book.h"
#include <iostream>

inline void to_json(json& book_json ,const Book* book) {
    if (book == nullptr) {
        return;
    }
    book_json["Released_Year"] = book->getYear();
    book_json["Name"] = book->getName();
    book_json["Author"] = book->getAuthor();
    book_json["Genre_List"] = book->getGenre();
    book_json["id"] = book->getId();
}

inline Book* from_json(const json& book_json) {
    int Released_Year = book_json.at("Released_Year").get<int>();
    std::string Name = book_json.at("Name").get<std::string>();
    std::string Author = book_json.at("Author").get<std::string>();
    std::vector<Genre> Genre_List = book_json.at("Genre_List").get<std::vector<Genre>>();
    int id = book_json.at("id").get<int>();

    Book* temp = new Book(Released_Year, Name, Author, Genre_List, id);

    return temp;
}


#endif // BOOKMANAGER_H
