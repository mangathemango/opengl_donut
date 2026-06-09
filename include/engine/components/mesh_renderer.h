#include <component.h>
#include <mesh.h>
#include <memory>

struct MeshRenderer: public Component {
    std::shared_ptr<Mesh> mesh;
    void display(std::ostream& os) const;
    // furture todo: Material maybe?
};
