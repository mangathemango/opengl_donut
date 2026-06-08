#include <component.h>

void Component::display(std::ostream& os) const {
    os << "if you see this something went wrong" << std::endl;
}
std::ostream& operator<<(std::ostream& os, const Component& component) {
    component.display(os);
    return os;
}