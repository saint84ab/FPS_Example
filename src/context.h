#ifndef __CONTEXT_H__
#define __CONTEXT_H__

#include "common.h"
#include "shader.h"
#include "program.h"
#include "buffer.h"
#include "vertex_layout.h"
#include "texture.h"
#include "mesh.h"
#include "model.h"
#include "framebuffer.h"
#include "shadow_map.h"

CLASS_PTR(Context)
class Context {
public:
    static ContextUPtr Create();
    void Render();       
    void ProcessInput(GLFWwindow* window);
    void Reshape(int width, int height);
    void MouseMove(double x, double y);
    void MouseButton(int button, int action, double x, double y);
    void DrawScene(const glm::mat4& view,
        const glm::mat4& projection,
        const Program* program);
    void DrawGuns(const glm::mat4& view,
        const glm::mat4& projection,
        const Program* program);
    void HUD();

private:
    Context() {}
    bool Init();
    bool isHUD { false };
    ProgramUPtr m_program;    	
    ProgramUPtr m_simpleProgram;
    ProgramUPtr m_textureProgram;
    ProgramUPtr m_postProgram;
    float m_gamma {1.0f};

    MeshUPtr m_box;
    MeshUPtr m_plane;

    // animation
    bool m_animation { true };

    // clear color
    glm::vec4 m_clearColor { glm::vec4(0.1f, 0.4f, 0.4f, 0.0f) };

    // light parameter
    struct Light {
        bool directional { false };
        glm::vec3 position { glm::vec3(2.0f, 4.0f, 4.0f) };
        glm::vec3 direction { glm::vec3(-0.5f, -1.5f, -1.0f) };
        glm::vec2 cutoff { glm::vec2(50.0f, 5.0f) };
        float distance { 150.0f };
        glm::vec3 ambient { glm::vec3(0.1f, 0.1f, 0.1f) };
        glm::vec3 diffuse { glm::vec3(0.8f, 0.8f, 0.8f) };
        glm::vec3 specular { glm::vec3(1.0f, 1.0f, 1.0f) };
    };
    Light m_light;
    bool m_flashLightMode { false };
    bool m_blinn { true };

    // material parameter
    MaterialPtr m_planeMaterial;
    MaterialPtr m_box1Material;
    MaterialPtr m_box2Material;
    TexturePtr m_windowTexture;

    // camera parameter
    float cameraRotSpeed { 0.45f };
    bool m_cameraControl { true };
    glm::vec2 m_prevMousePos { glm::vec2(0.0f) };
    float m_cameraPitch { -20.0f };
    float m_cameraYaw { 0.0f };
    glm::vec3 m_cameraPos { glm::vec3(0.0f, 7.0f, 8.0f) };
    glm::vec3 m_cameraFront { glm::vec3(0.0f, 0.0f, -1.0f) };
    glm::vec3 m_cameraUp { glm::vec3(0.0f, 1.0f, 0.0f) };
    float cameraSpeed = 0.1f;
    float fov { 45.0f };
    std::string handtype;

    // moving parameter
    float jumpPower { 3.0f };
    float jumptime { 0.0f };
    bool isJump = { false };
    bool isBottom = { true };
    
    // physics parameter
    float gravity { 9.8f };
    float velocity { 0.0f };
    float acceleration { 10.0f };
    float massive { 2.0f };

    // framebuffer
    FramebufferUPtr m_framebuffer;

    // cubemap
    CubeTextureUPtr m_cubeTexture;
    ProgramUPtr m_skyboxProgram;
    ProgramUPtr m_envMapProgram;

    TexturePtr m_grassTexture;
    ProgramUPtr m_grassProgram;
    std::vector<glm::vec3> m_grassPos;
    BufferUPtr m_grassPosBuffer;
    VertexLayoutUPtr m_grassInstance;

    // shadow map
    ShadowMapUPtr m_shadowMap;
    ProgramUPtr m_lightingShadowProgram;

    // normal map
    TextureUPtr m_brickDiffuseTexture;
    TextureUPtr m_brickNormalTexture;
    ProgramUPtr m_normalProgram;

    int m_width { WINDOW_WIDTH };
    int m_height { WINDOW_HEIGHT };

    // deferred shading
    FramebufferUPtr m_deferGeoFramebuffer;
    ProgramUPtr m_deferGeoProgram;

    ProgramUPtr m_deferLightProgram;

    struct DeferLight {
        glm::vec3 position;
        glm::vec3 color;
    };
    std::vector<DeferLight> m_deferLights;

    // ssao
    FramebufferUPtr m_ssaoFramebuffer;
    ProgramUPtr m_ssaoProgram;
    ModelUPtr m_model;  // for test rendering
    TextureUPtr m_ssaoNoiseTexture;
    std::vector<glm::vec3> m_ssaoSamples;
    float m_ssaoRadius { 1.0f };
    			
    ProgramUPtr m_blurProgram;
    FramebufferUPtr m_ssaoBlurFramebuffer;
    bool m_useSsao { true };

    // City
    ModelUPtr m_city_curve;
    MaterialPtr m_city_curve_material;
    ModelUPtr m_city_straight;
    MaterialPtr m_city_straight_material;

    // Guns Status
    std::string gun_name[3] { "AK-47", "Kriss Vector", "Beretta" };
    int select_gun { 1 };

	// Guns - AK-47 - body
    ModelUPtr m_gun_ak_body;
    MaterialPtr m_gun_ak_body_material;
    bool isFire { false };

    // Guns - AK-47 - mag
    ModelUPtr m_gun_ak_mag;
    MaterialPtr m_gun_ak_mag_material;
    int bulletCount_ak { 30 };
    float rpm_ak { 600.0f };

    // Guns - AK-47 - pull
    ModelUPtr m_gun_ak_pull;
    MaterialPtr m_gun_ak_pull_material;

    // Guns - Kriss Vector
    ModelUPtr m_gun_vector;
    MaterialPtr m_gun_vector_material;

    // Guns - Beretta
    ModelUPtr m_gun_beretta;
};

#endif // __CONTEXT_H__