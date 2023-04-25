#include "Menu/Menu.h"


#include <conio.h>
#include <iostream>
#include <stdexcept>

namespace MatrixManipulation {
    namespace CLI {
        Item::Item(std::string name, Accept accept)
            : name_(std::move(name)), accept_(accept) {}

        const std::string& Item::getName()   const { return name_; }
        const Item::Accept& Item::getAccept() const { return accept_; }

        void Item::setName(const std::string& name) { name_ = name; }
        void Item::setAccept(const Accept& accept) { accept_ = accept; }

        void Item::accept(Menu* menu) { accept_(menu); }


        Menu::Menu(std::string name, std::initializer_list<Item> items)
            : name_(std::move(name)), items_(items) {
            if (items_.size() > 9)
                throw std::invalid_argument("maximal number of items is 9");
        }

        const std::string& Menu::getName()  const { return name_; }
        const std::vector<Item>& Menu::getItems() const { return items_; }

        void Menu::setName(const std::string& name) { name_ = name; }
        void Menu::setItems(const std::vector<Item>& items) { items_ = items; }

        void Menu::run() {
            while (true) {
                system("cls");
                std::cout << "Select item:\r\n";
                for (int i = 0; i < items_.size(); ++i)
                    std::cout << i + 1 << ". " << items_[i].getName() << "\r\n";
                std::cout << "0. Exit\r\n"
                    << " > "
                    << std::flush;

                while (true) {
                    int key = _getch();
                    if (key == '0' || key == -1) {
                        std::cout << "0" << std::flush;
                        return;
                    }
                    else if (isdigit(key) && (key - '1' < items_.size())) {
                        std::cout << static_cast<char>(key) << std::flush;
                        items_[key - '1'].accept(this);
                        break;
                    }
                }
            }
        }
    }
}
