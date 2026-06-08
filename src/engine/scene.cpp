#include <scene.h>
#include <mat4.h>
#include <meshrenderer.h>
#include <app.h>
#include <vec2.h>
#include <algorithm>

void Scene::render()
{
    std::cout << "Rendering " << objs.size() << std::endl;
    if (mainCamera == nullptr)
    {
        return;
    }
    std::vector<Vec3> vertices;
    std::vector<int> indices;
    std::vector<float> lighting;

    Transform *cameraTf = mainCamera->parent->getComponent<Transform>();
    for (GameObj *obj : objs)
    {

        MeshRenderer *mr = obj->getComponent<MeshRenderer>();
        Transform *tf = obj->getComponent<Transform>();

        if (mr == nullptr || tf == nullptr)
        {
            continue;
        }
        Mat4 view =  Mat4::identity()
            .translate(-cameraTf->position)
            .rotate(cameraTf->rotation.inverse());
        if ((view * tf->position).z < 5) continue;
        
        Mat4 model = Mat4::TRS(tf->position, tf->rotation, tf->scale);
        vector<Vec3> tempVertices;
        for (int i = 0; i < mr->mesh->vertices.size(); i++)
        {
            Vec3 transformed = view * model * mr->mesh->vertices[i];
            tempVertices.push_back(transformed);

            lighting.push_back(tf->position.distance(cameraTf->position));
        }

        vector<Vec3> tempIndices(mr->mesh->indices);
        sort(tempIndices.begin(), tempIndices.end(), [tempVertices](const Vec3 &a, const Vec3 &b){
            float depthA = tempVertices[a.x].z + tempVertices[a.y].z + tempVertices[a.z].z;
            float depthB = tempVertices[b.x].z + tempVertices[b.y].z + tempVertices[b.z].z;
            return depthA > depthB; 
        });

        int vertexCount = vertices.size();
        for (Vec3 &indexVec : tempIndices)
        {
            float depth = tempVertices[indexVec.x].z + tempVertices[indexVec.y].z + tempVertices[indexVec.z].z;
            indices.push_back(indexVec.x + vertexCount);
            indices.push_back(indexVec.y + vertexCount);
            indices.push_back(indexVec.z + vertexCount);
        }
        vertices.insert(vertices.end(), tempVertices.begin(), tempVertices.end());
    }

    std::vector<Vec2> vertices2D;
    for (Vec3 &vertex : vertices)
    {
        // Convert to -1 -> 1 coords
        float fovY = (mainCamera->fov * M_PI / 180.0f);
        float fovX = fovY / app.config.screen_height * app.config.screen_width;
        float x = std::atanf(vertex.x / vertex.z) / fovX;
        float y = std::atanf(vertex.y / vertex.z) / fovY;
        vertices2D.push_back(Vec2(x, y));
    }

    for (Vec2 &vertex2D : vertices2D)
    {
        vertex2D.x += 1;                       // Shift -1 -> 1 to 0 -> 2
        vertex2D.x /= 2;                       // 0 -> 2 to 0 -> 1
        vertex2D.x *= app.config.screen_width; // 0 -> screenWidth
        vertex2D.y -= 1;                       // Shift 1 -> -1 to 0 -> -2
        vertex2D.y /= -2;                      // 0 -> -2 to  0 -> 1
        vertex2D.y *= app.config.screen_height;
        vertex2D.x = clamp(0.0f, vertex2D.x, (float) app.config.screen_width);
        vertex2D.y = clamp(0.0f, vertex2D.y, (float) app.config.screen_height);
    }

    // SDL_Vertex *sdlVertices = (SDL_Vertex *)malloc(sizeof(SDL_Vertex) * vertices2D.size());
    // int *sdlIndices = (int *)malloc(sizeof(int) * indices.size());
    // for (int i = 0; i < vertices2D.size(); i++)
    // {
    //     sdlVertices[i] = (SDL_Vertex){
    //         (SDL_FPoint){
    //             vertices2D[i].x,
    //             vertices2D[i].y
    //         },
    //         (SDL_Color){lighting[i] * 255, lighting[i] * 255, lighting[i] * 255, 255},
    //         (SDL_FPoint){0, 0}};
    // }
    // for (int i = 0; i < indices.size(); i++)
    // {
    //     sdlIndices[i] = indices[i];
    // }

    // SDL_RenderGeometry(
    //     app.resources.renderer,
    //     NULL,
    //     sdlVertices,
    //     vertices2D.size(),
    //     sdlIndices,
    //     indices.size());
    

    // free(sdlVertices);
    // free(sdlIndices);
}