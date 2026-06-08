#pragma once
#include <component.h>
#include <concepts>
#include <unordered_map>
#include <optional>
#include <iostream>

class GameObj
{
public:
    std::unordered_map<size_t, Component *> components;
    GameObj();

    template <typename T>
    requires std::derived_from<T, Component>
    T *addComponent();
    template <typename T>
    requires std::derived_from<T, Component>
    T *getComponent();
};

template <typename T>
requires std::derived_from<T, Component>
T *GameObj::getComponent()
{
    auto it = components.find(typeid(T).hash_code());
    if (it == components.end())
        return nullptr;
    return static_cast<T*>(it->second);
}

template <typename T>
requires std::derived_from<T, Component>
T *GameObj::addComponent()
{
    Component *component = new T();
    component->parent = this;
    components.insert({typeid(T).hash_code(), component});

    return getComponent<T>();
}

std::ostream &operator<<(std::ostream &os, const GameObj &obj);