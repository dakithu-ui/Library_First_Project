#include "Library.h"
#include "BookManager.h"

#include <fstream>
#include <iostream>


std::vector<Book*> Library::getList_Book() const {
    return List_Book;
}

void Library::addBook(Book* b) {
    b->setID(Total_Book);
    List_Book.push_back(b);
    Total_Book += 1;
}

std::vector<Customer*> Library::getList_Customer() const {
    return List_Customer;
}

void Library::addCustomer(Customer* c) {
    c->setid(Total_Customer);
    List_Customer.push_back(c);
    Total_Customer += 1;
}

std::vector<Transaction*> Library::getList_Transaction() const {
    return List_Transaction;
}

void Library::addTransaction(Transaction* t) {
    t->setid(Total_Transaction);
    List_Transaction.push_back(t);
    Total_Transaction += 1;
}

void Library::deserialize() {

    json json_temp;
    std::ifstream json_stream("Books.json");

    if (!json_stream.is_open() || json_stream.peek() == std::ifstream::traits_type::eof()) {
        std::cout << "Initiated First Book" << std::endl;
        return;
    }

    json_stream >> json_temp;


    for (const auto& item: json_temp["Books"]) {
        List_Book.push_back(from_json(item));
    }
    for (const auto& item: json_temp["Customers"]) {
        List_Customer.push_back(from_json(item));
    }
    for (const auto& item: json_temp["Transactions"]) {
        List_Transaction.push_back(from_json(item));
    }


    json Total = json_temp.at("Data").get<json>();
    Total_Book = Total.at("Total_Book").get<int>();
    Total_Customer = Total.at("Total_Customer").get<int>();
    Total_Transaction = Total.at("Total_Transaction").get<int>();
}

void Library::serialize() {
    json json;
    json["Total_Book"] = Total_Book;
    json["Total_Customer"] = Total_Customer;
    json["Total_Transaction"] = Total_Transaction;

    json["Books"] = List_Book;
    json["Customers"] = List_Customer;
    json["Transactions"] = List_Transaction;

    std::ofstream output("Books.json");
    output << json.dump(4);
}

Library::Library() {
    deserialize();

}

Library::~Library() {
    serialize();
    for (Book* b : List_Book) {
        delete b;
    }
    List_Book.clear();
    List_Book.clear();
}

void Library::Clear_Storage() {
    json Reset;
    Total_Book = 0;

    for (Book* b : List_Book) {
        delete b;
    }
    List_Book.clear();

}

std::vector<Book*> Library::getbyName(const std::string& Name) const {
    std::vector<Book*> temp;
    for (Book* b: List_Book) {
        if(b->getName() == Name) {
            temp.push_back(b);
        }
    }
    return temp;
}

std::vector<Book*> Library::getbyAuthor(const std::string& Author) const {
    std::vector<Book*> temp;
    for (Book* b: List_Book) {
        if(b->getAuthor() == Author) {
            temp.push_back(b);
        }
    }
    return temp;
}

std::vector<Book*> Library::getbyGenre(const Genre& g) const {
    std::vector<Book*> temp;
    for (Book* b: List_Book) {
        for (Genre genre: b->getGenre()) {
            if (genre == g) {
                temp.push_back(b);
            }
        }
    }
    return temp;
}

std::vector<Book*> Library::getbyRelease(const int& Year) const {
    std::vector<Book*> temp;
    for (Book* b: List_Book) {
        if (b->getYear() == Year) {
            temp.push_back(b);
        }
    }
    return temp;
}

Book* Library::getbyId(const int& id) const {
    for (Book* b: List_Book) {
        if (b->getId() == id) {
            return b;
        }
    }
    return nullptr;
}

void Library::display(const std::vector<Book*>& Book_List_Book) const {
    for (Book* b: Book_List_Book) {
        b->display();
    }
}