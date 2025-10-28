#include "rollingball.h"
#include "../components/mesh.h"
#include "../components/terrain.h"
#include <glm/gtc/matrix_transform.hpp>

RollingBall::RollingBall()
{
}

void RollingBall::Init()
{
    ballMesh = new Mesh("Assets/Models/ball.obj");
    ballMesh->Scale(0.1f);

    terrainMesh = new Terrain();//("Assets/terrain.png");

    camera.position = glm::vec3(0.0f, 0.0f, 4.0f);

    renderer->SetLightPos(glm::vec3(0,2,0));
}

void RollingBall::Update()
{
    float ballMass = 2;
    glm::vec3 pos = ballMesh->GetPosition();

    if (input.Held(input.Key.SPACE))
    {
        pos = glm::vec3();
        velocity = glm::vec3();
        pos = glm::vec3(0.5,0,0.5);
        velocity = glm::vec3(0,0,0);
    }

    velocity += glm::vec3();
    velocity += glm::vec3(terrainMesh->GetNormal(ballMesh->GetPosition())) + glm::vec3(0, ballMass*-9.81, 0);

    pos += velocity / 480.0f;
    pos.y = terrainMesh->GetHeightAt(pos) + 0.1f;

    if(ballMesh->GetPosition().x < 0 || ballMesh->GetPosition().x > 2
        || ballMesh->GetPosition().z < 0 || ballMesh->GetPosition().z > 1)
    {
        velocity = glm::vec3(0,0,0);
    }

    ballMesh->SetPosition(pos);
}
