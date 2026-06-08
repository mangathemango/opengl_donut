#include <gameobj.h>
#include <transform.h>
#include <app.h>

GameObj::GameObj() {
    addComponent<Transform>();
    app.state.scene.objs.push_back(this);
}

std::ostream& operator<<(std::ostream& os, const GameObj& obj) {
    os << "GameObj:\n";
    os << "- Components: " << obj.components.size() << "\n";
    for (auto it = obj.components.begin(); it != obj.components.end(); it++) {
        if (it == nullptr) continue;
        if (it->second == nullptr) continue;
        os << *(it->second);
    }
    return os;
}


