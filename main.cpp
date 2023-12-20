#include <iostream>
#include <string>

class Recipe {
public:
    Recipe(const std::string& name) : name_(name) {
        counter_++;
    }

    virtual void showInformation() const = 0;

    virtual void cook() const = 0;

    static int getCount() {
        return counter_;
    }

protected:
    std::string name_;

private:
    static int counter_;
};

int Recipe::counter_ = 0;

class Pastry : public Recipe {
public:
    Pastry(const std::string& name, const std::string& filling) : Recipe(name), filling_(filling) {}

    void showInformation() const override {
        std::cout << "Recipe for pastry: " << name_ << std::endl;
        std::cout << "Filling: " << filling_ << std::endl;
    }

    void cook() const override {
        std::cout << "Cooking pastry: " << name_ << std::endl;
        std::cout << "Adding filling: " << filling_ << std::endl;
        std::cout << "Baking in the oven" << std::endl;
    }

private:
    std::string filling_;
};

class Salad : public Recipe {
public:
    Salad(const std::string& name, const std::string& base) : Recipe(name), base_(base) {}

    void showInformation() const override {
        std::cout << "Recipe for salad: " << name_<< std::endl;
        std::cout << "Base: " << base_ << std::endl;
    }

    void cook() const override {
        std::cout << "Cooking salad: " << name_<< std::endl;
        std::cout << "Using base: " << base_ << std::endl;
        std::cout << "Adding vegetables and dressing" << std::endl;
    }

private:
    std::string base_;
};

template <typename T>
class Drink : public Recipe {
public:
    Drink(const std::string& name, const std::string& ingredient) : Recipe(name), ingredient_(ingredient) {}

    void showInformation() const override {
        std::cout << "Recipe for drink: " << name_ << std::endl;
        std::cout << "Ingredient: " << ingredient_ << std::endl;
    }

    void cook() const override {
        std::cout << "Cooking drink: " << name_<< std::endl;
        std::cout << "Using ingredient: " << ingredient_ << std::endl;
        std::cout << "Mixing and cooling" << std::endl;
    }

private:
    std::string ingredient_;
};

int main() {
    Pastry pastry("Sharlotka", "bebra");
    Salad salad("Greek salad", "Lettuce");
    Drink<std::string> drink("Lemonade", "Lemon juice");


    salad.showInformation();
    salad.cook();


    std::cout << "Number of created objects: " << Recipe::getCount() << std::endl;

    return 0;
}
