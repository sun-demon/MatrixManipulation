#ifndef MATRIXMANIPULATION_CLI_MENU_H
#define MATRIXMANIPULATION_CLI_MENU_H


#include <string>
#include <vector>

#include "FunctionalInterface/IRunnable.h"

namespace MatrixManipulation {
    namespace CLI {
        class Menu;


        class Item {
        public:
            using Accept = void (*)(Menu*);

            Item(std::string name, Accept accept);

            const std::string& getName()   const;
            const Accept& getAccept() const;

            void setName(const std::string& name);
            void setAccept(const Accept& function);

            void accept(Menu*);

        private:
            std::string name_;
            Accept      accept_;
        };


        class Menu : public FunctionalInterface::IRunnable {
        public:
            Menu(std::string name, std::initializer_list<Item> items);

            const std::string& getName()  const;
            const std::vector<Item>& getItems() const;

            void setName(const std::string& name);
            void setItems(const std::vector<Item>& items);

            void run() override;

        private:
            std::string       name_;
            std::vector<Item> items_;
        };
    }
}


#endif //MATRIXMANIPULATION_CLI_MENU_H
