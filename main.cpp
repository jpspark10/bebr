#include <iostream>
#include <string>
#include <stdlib.h>
#include <windows.h>

template<typename T>
class Recipe {
public:
    Recipe(const T& name) : name_(name) {
        counter_++;
    }

    virtual void showInformation() const = 0;

    virtual void cook() const = 0;

    static int getCount() {
        return counter_;
    }

protected:
    T name_;

private:
    static int counter_;
};

template<typename T>
int Recipe<T>::counter_ = 0;

template<typename T>
class Pastry : public Recipe<T> {
public:
    Pastry(const T& name, const T& filling) : Recipe<T>(name), filling_(filling) {}

    void showInformation() const override {
        std::cout << "-----Recipe Info:-----" << std::endl;
        std::cout << "Recipe for pastry: " << this->name_ << std::endl;
        std::cout << "Filling: " << filling_ << std::endl;
        std::cout << "---------------------" << std::endl;
        Sleep(2000);
        printf("\e[1;1H\e[2J");
    }

    void cook() const override {
        std::cout << "Cooking pastry: " << this->name_ << std::endl;
        Sleep(1000);
        std::cout << "Adding filling: " << filling_ << std::endl;
        Sleep(1000);
        std::cout << "Baking in the oven" << std::endl;
        Sleep(1000);
        printf("\e[1;1H\e[2J");
    }

private:
    T filling_;
};

template<typename T>
class Salad : public Recipe<T> {
public:
    Salad(const T& name, const T& base) : Recipe<T>(name), base_(base) {}

    void showInformation() const override {
        std::cout << "-----Recipe Info:-----" << std::endl;
        std::cout << "Recipe for salad: " << this->name_ << std::endl;
        std::cout << "Base: " << base_ << std::endl;
        std::cout << "---------------------" << std::endl;
        Sleep(3000);
        printf("\e[1;1H\e[2J");
    }

    void cook() const override {
        std::cout << "Cooking salad: " << this->name_ << std::endl;
        Sleep(1000);
        std::cout << "Using base: " << base_ << std::endl;
        Sleep(1000);
        std::cout << "Adding vegetables and dressing" << std::endl;
        Sleep(1000);
        printf("\e[1;1H\e[2J");
    }

private:
    T base_;
};

template<typename T, typename U>
class Drink : public Recipe<T> {
public:
    Drink(const T& name, const U& ingredient) : Recipe<T>(name), ingredient_(ingredient) {}

    void showInformation() const override {
        std::cout << "-----Recipe Info-----" << std::endl;
        std::cout << "Recipe for drink: " << this->name_ << std::endl;
        std::cout << "Ingredient: " << ingredient_ << std::endl;
        std::cout << "---------------------" << std::endl;
        Sleep(3000);
        printf("\e[1;1H\e[2J");
    }

    void cook() const override {
        std::cout << "Cooking drink: " << this->name_ << std::endl;
        Sleep(1000);
        std::cout << "Using ingredient: " << ingredient_ << std::endl;
        Sleep(1000);
        std::cout << "Mixing and cooling" << std::endl;
        Sleep(1000);
        printf("\e[1;1H\e[2J");
    }

private:
    U ingredient_;
};

int main() {
    int choice;
    std::string recipeName;
    std::string ingredient;
    while (true){
        std::cout << "Number of created recipes: " << Recipe<std::string>::getCount() << std::endl;
        std::cout << "What type of Recipe do u wanna to create? ;)\n"
                  << "\t 1 - Pastry\n"
                  << "\t 2 - Salad\n"
                  << "\t 3 - Drink\n";
        std::cin >> choice;
        printf("\e[1;1H\e[2J");
        switch (choice){
        case 1:{
                std::cout << "Enter pastry name and ingredient:\n";
                std::cout << "Pastry name: \n" ;
                std::cin >> recipeName;
                std::cout << "Ingredient name:\n";
                std::cin >> ingredient;
                Pastry<std::string> pastry(recipeName, ingredient);
                pastry.cook();
                pastry.showInformation();
        }break;

        case 2:{
                std::cout << "Enter salad name and ingredient:" << std::endl;
                std::cout << "Salad name: " << std::endl;
                std::cin >> recipeName;
                std::cout << std::endl;
                std::cout << "Ingredient name:" << std::endl;
                std::cin >> ingredient;
                std::cout << std::endl;
                Salad <std::string> salad (recipeName,ingredient);
                salad.cook();
                salad.showInformation();
        }break;
        case 3:{
            std::cout << "Enter drink name and ingredient:" << std::endl;
            std::cout << "Drink name: " << std::endl;
            std::cin >> recipeName;
            std::cout << std::endl;
            std::cout << "Ingredient name: " << std::endl;
            std::cin >> ingredient;
            std::cout << std::endl;
            Drink <std::string,std::string> drink(recipeName,ingredient);
            drink.cook();
            drink.showInformation();
        }break;
        default:
            std::cout << "Wrong choice =(" << std::endl;
            break;
        }


    }

    return 0;
}
