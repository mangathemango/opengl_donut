#include <component.h>
#include <mesh.h>

struct MeshRenderer: public Component {
    Mesh* mesh;
    void display(std::ostream& os) const;
    // furture todo: Material maybe?
};
