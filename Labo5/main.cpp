#include <iostream>
#include <vector>
using namespace std;

class Handler {
public:
    virtual Handler* SetNext(Handler* handler) = 0;
    virtual string Handle(string request) = 0;
};

class AbstractHandler : public Handler {
    
private:
    Handler* next_handler_;

public:
    AbstractHandler() : next_handler_(nullptr) {
    }
    Handler* SetNext(Handler* handler) override {
        this->next_handler_ = handler;
        return handler;
    }
    std::string Handle(std::string request) override {
        if (this->next_handler_) {
            return this->next_handler_->Handle(request);
        }
        return {};
    }
};

class MonkeyHandler : public AbstractHandler {
public:
    std::string Handle(std::string request) override {
        if (request == "Banana") {
            return "Mono: me comere la " + request + ".\n";
        }
        else {
            return AbstractHandler::Handle(request);
        }
    }
};
class SquirrelHandler : public AbstractHandler {
public:
    std::string Handle(std::string request) override {
        if (request == "Nuez") {
            return "Ardilla: me comere la " + request + ".\n";
        }
        else {
            return AbstractHandler::Handle(request);
        }
    }
};
class DogHandler : public AbstractHandler {
public:
    std::string Handle(std::string request) override {
        if (request == "Albondiga") {
            return "Perro: me comere la " + request + ".\n";
        }
        else {
            return AbstractHandler::Handle(request);
        }
    }
};

void ClientCode(Handler& handler) {
    vector<string> food = { "Nuez", "Banana", "Copa de cafe" };
    for (const string& f : food) {
        cout << "Cliente: quien quiere una " << f << "?\n";
        const string result = handler.Handle(f);
        if (!result.empty()) {
            cout << "  " << result;
        }
        else {
            cout << "  " << f << " se dejo intacto.\n";
        }
    }
}

int main() {
    MonkeyHandler* monkey = new MonkeyHandler;
    SquirrelHandler* squirrel = new SquirrelHandler;
    DogHandler* dog = new DogHandler;
    monkey->SetNext(squirrel)->SetNext(dog);
    cout << "Cadena: Mono > Ardilla > Perro\n\n";
    ClientCode(*monkey);
    cout << "\n";
    cout << "SubCadena: Ardilla > Perro\n\n";
    ClientCode(*squirrel);
    delete monkey;
    delete squirrel;
    delete dog;

    return 0;
}