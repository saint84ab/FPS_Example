// #ifndef __KEYINPUT_H__
// #define __KEYINPUT_H__

// #include "common.h"
// #include "shader.h"
// #include "program.h"
// #include "buffer.h"
// #include "vertex_layout.h"
// #include "texture.h"
// #include "mesh.h"
// #include "model.h"
// #include "framebuffer.h"
// #include "shadow_map.h"

// CLASS_PTR(KeyInput)
// class KeyInput {
// public :
//     static KeyInputUPtr Create();
//     void ProcessInput(GLFWwindow* window);

// private :
//     // camera parameter
//     bool m_cameraControl { false };
//     glm::vec2 m_prevMousePos { glm::vec2(0.0f) };
//     float m_cameraPitch { -20.0f };
//     float m_cameraYaw { 0.0f };
//     glm::vec3 m_cameraPos { glm::vec3(0.0f, 2.5f, 8.0f) };
//     glm::vec3 m_cameraFront { glm::vec3(0.0f, 0.0f, -1.0f) };
//     glm::vec3 m_cameraUp { glm::vec3(0.0f, 1.0f, 0.0f) };
// };




// #endif // __KEYINPUT_H__