#pragma once
#include <string>

class Entity {
protected:
    int id;

public:
    Entity(int id) : id(id) {}
    virtual ~Entity() = default;

    virtual int getId() const { return id; }
    virtual std::string getInfo() const = 0;
};
