// #include "keyInput.h"
// #include "image.h"
// #include <imgui.h>

// void KeyInput::ProcessInput(GLFWwindow* window) {

//     if (!m_cameraControl)
//         return;

//     const float cameraSpeed = 0.05f;
//     if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
//         m_cameraPos += cameraSpeed * m_cameraFront;
//     if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
//         m_cameraPos -= cameraSpeed * m_cameraFront;

//     auto cameraRight = glm::normalize(glm::cross(m_cameraUp, -m_cameraFront));
//     if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
//         m_cameraPos += cameraSpeed * cameraRight;
//     if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
//         m_cameraPos -= cameraSpeed * cameraRight;    

//     // JUMP CODE
//     auto cameraUp = glm::normalize(glm::cross(-m_cameraFront, cameraRight));
//     if (glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS) {
//         m_cameraPos += cameraSpeed * cameraUp;

//     }
    
//     // SIT CODE
//     if (glfwGetKey(window, GLFW_KEY_LEFT_CONTROL) == GLFW_PRESS)
//         m_cameraPos -= cameraSpeed * cameraUp;

// }
