/*

    Práctica 2

    Registro: 23310166.
    Nombre: Galio Marcelo Gutiérrez Hernández.

*/

// Place where I put the libraries I'll use.

#include <iostream>
#include <string>

class User {
protected:
    // Attributes
    std::string cellphone;
    std::string name;
    std::string password;
    int age;

public:
    // Constructor
    User(const std::string& userCellphone, const std::string& userName, const std::string& userPwd, int userAge);
    
    
    
    // Methods
    void logIn();
    void logOut();
    void changePassword();

    // Virtual Method
    void displayUserInfo();

    // Add a virtual destructor
    virtual ~User() {}
};

// Constructor definition
User::User(const std::string& userCellphone, const std::string& userName, const std::string& userPwd, int userAge) {
    cellphone = userCellphone;
    name = userName;
    password = userPwd;
    age = userAge;
}

// Method definitions
void User::displayUserInfo() {
    std::cout << "Username: " << name << std::endl;
    std::cout << "Password: " << password << std::endl;
    std::cout << "Age: " << age << std::endl;
    std::cout << "Cellphone: " << cellphone << std::endl;
}

void User::logIn(){

    std::string inputName;
    std::string inputPassword;

    std::cout << "Enter username: ";
    std::cin >> inputName;

    std::cout << "Enter password: ";
    std::cin >> inputPassword;
    std::cout << std::endl;

    if (inputName  == name && inputPassword  == password) {
        std::cout << "Login successful!\n" << std::endl;
    } else {
        std::cout << "Login failed. Incorrect username or password.\n" << std::endl;
    }

}

void User::logOut(){
    std::cout << "Logged out successfully.\n" << std::endl;
}

void User::changePassword(){
    std::string oldPassword;
    std::string newPassword;

    std::cout << "Enter old password: ";
    std::cin >> oldPassword;

    if (oldPassword == password) {
        std::cout << "Enter new password: ";
        std::cin >> newPassword;
        password = newPassword;
        std::cout << std::endl;
        std::cout << "Password changed successfully.\n" << std::endl;
    } else {
        std::cout << "Invalid old password. Password change failed.\n" << std::endl;
    }
}

// Subclass Seller
class Seller : public User {
public:
    // Constructor
    Seller(const std::string& userCellphone, const std::string& userName, const std::string& userPwd, int userAge);

    // Methods
    void sell();
    void updateInventory();
};

// Constructor definition
Seller::Seller(const std::string& userCellphone, const std::string& userName, const std::string& userPwd, int userAge) :
    User(userCellphone, userName, userPwd, userAge) {}

// Method definitions
void Seller::sell() {
    std::cout << "I want to sell you this. Are you interested?\n" << std::endl;
}

void Seller::updateInventory() {
    std::cout << "Pfff... it's time to update the inventory\n" << std::endl;
}

// Subclass Client
class Client : public User {
public:
    // Constructor
    Client(const std::string& userCellphone, const std::string& userName, const std::string& userPwd, int userAge);

    // Methods
    void buyStuff();
    void claimForSomething();
    void devolution();
};

// Constructor definition
Client::Client(const std::string& userCellphone, const std::string& userName, const std::string& userPwd, int userAge) :
    User(userCellphone, userName, userPwd, userAge) {}

// Method definitions
void Client::buyStuff() {
    std::cout << "I'm going to buy that.\n" << std::endl;
}

void Client::claimForSomething() {
    std::cout << "I'm complaining because you almost scammed me.\n" << std::endl;
}

void Client::devolution() {
    std::cout << "I want to return this.\n" << std::endl;
}

// Functions
void displayMenu(User& user) {
    std::cout << "Menu:" << std::endl;
    std::cout << "1. Display user information" << std::endl;
    std::cout << "2. Log in" << std::endl;
    std::cout << "3. Change password" << std::endl;
    std::cout << "4. Log out" << std::endl;

    // Additional options for seller
    Seller* sellerPtr = dynamic_cast<Seller*>(&user);
    if (sellerPtr != nullptr) {
        std::cout << "5. Sell" << std::endl;
        std::cout << "6. Update inventory" << std::endl;
        std::cout << "7. Exit\n" << std::endl;
    }

    // Additional options for client
    Client* clientPtr = dynamic_cast<Client*>(&user);
    if (clientPtr != nullptr) {
        std::cout << "5. Buy stuff" << std::endl;
        std::cout << "6. Claim for something" << std::endl;
        std::cout << "7. Devolution" << std::endl;
        std::cout << "8. Exit\n" << std::endl;
    }

    std::cout << "Enter your choice: ";
}

void menuLoop(User& user) {
    int choice;
    bool exit = false;

    // Check if the user is a Seller or a Client
    Seller* sellerPtr = dynamic_cast<Seller*>(&user);
    Client* clientPtr = dynamic_cast<Client*>(&user);

    // Display menu options based on user type
    if (sellerPtr != nullptr) {
        // Seller-specific menu options
        while (!exit) {
            std::cout << std::endl;
            displayMenu(user);
            std::cin >> choice;
            std::cout << std::endl;

            switch (choice) {
                case 1:
                    user.displayUserInfo();
                    std::cout << std::endl;
                    break;
                case 2:
                    user.logIn();
                    std::cout << std::endl;
                    break;
                case 3:
                    user.changePassword();
                    std::cout << std::endl;
                    break;
                case 4:
                    user.logOut();
                    std::cout << std::endl;
                    break;
                case 5:
                    sellerPtr->sell();
                    break;
                case 6:
                    sellerPtr->updateInventory();
                    break;
                case 7:
                    exit = true;
                    std::cout << "Exiting the program...\n" << std::endl;
                    break;
                default:
                    std::cout << "Invalid choice. Please try again.\n" << std::endl;
                    break;
            }
        }
    } else if (clientPtr != nullptr) {
        // Client-specific menu options
        while (!exit) {
            std::cout << std::endl;
            displayMenu(user);
            std::cin >> choice;
            std::cout << std::endl;

            switch (choice) {
                case 1:
                    user.displayUserInfo();
                    std::cout << std::endl;
                    break;
                case 2:
                    user.logIn();
                    std::cout << std::endl;
                    break;
                case 3:
                    user.changePassword();
                    std::cout << std::endl;
                    break;
                case 4:
                    user.logOut();
                    std::cout << std::endl;
                    break;
                case 5:
                    clientPtr->buyStuff();
                    break;
                case 6:
                    clientPtr->claimForSomething();
                    break;
                case 7:
                    clientPtr->devolution();
                    break;
                case 8:
                    exit = true;
                    std::cout << "Exiting the program...\n" << std::endl;
                    break;
                default:
                    std::cout << "Invalid choice. Please try again.\n" << std::endl;
                    break;
            }
        }
    } else {
        std::cout << "Invalid user type. Exiting program.\n" << std::endl;
    }
}

int main() {

    std::cout << "Practica 2 - 23310166\n" << std::endl;

    // Asking the role of the user...
    std::string userType;
    std::cout << "Hello, Are you the 'seller' or the 'client'?: ";
    std::cin >> userType;

    // Creating an object depending of what the user chose.
    if (userType == "seller") {
        Seller user1("33-56-86-23-93", "Serie", "want+money", 10000);
        menuLoop(user1);
    } else if (userType == "client") {
        Client user2("33-21-55-19-02", "Frieren", "beyond23+", 1000);
        menuLoop(user2);
    } else {
        std::cout << "Invalid user type. Exiting program.\n" << std::endl;
    }

    return 0;
}