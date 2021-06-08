// #ifndef __MOVING_H__
// #define __MOVING_H__

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
// #include <time.h>

// CLASS_PTR(Moving)
// class Moving {
// public :
//     static MovingUPtr create();
//     void Move(GLFWwindow* window);
    
// private :
//     Moving() {}
//     bool m_cameraControl { false };
//     glm::vec3 m_cameraPos { glm::vec3(0.0f, 2.5f, 8.0f) };
//     glm::vec3 m_cameraFront { glm::vec3(0.0f, 0.0f, -1.0f) };
//     glm::vec3 m_cameraUp { glm::vec3(0.0f, 1.0f, 0.0f) }; 
    
//     // moving parameter
//     float jumpPower { 7.0f };
//     float jumptime { 0.0f };
//     bool isJump = { false };
    
//     // physics parameter
//     float gravity { 9.8f };
//     float velocity { 0.0f };
//     float acceleration { 0.0f };
//     float massive { 0.0f };
// }


// #endif // __MOVING_H__