#pragma once

#include <memory>

namespace Pilot
{
    class LogSystem;
    class InputSystem;
    class PhysicsSystem;
    class FileService;
    class AssetManager;
    class ConfigManager;
    class WorldManager;
    class SceneManager;
    class RenderSystem;
    class WindowSystem;

    struct EngineInitParams;

    /// Manage the lifetime and creation/destruction order of all global system
    class RuntimeGlobalContext
    {
    public:
        // create all global systems and initialize these systems
        void startSystems(const EngineInitParams& init_params);
        // destroy all global systems
        void shutdownSystems();

    public:
        std::shared_ptr<LogSystem>     m_logger_system;
        std::shared_ptr<InputSystem>   m_input_system;
        std::shared_ptr<FileService>   m_file_servcie;
        std::shared_ptr<AssetManager>  m_asset_manager;
        std::shared_ptr<ConfigManager> m_config_manager;
        std::shared_ptr<WorldManager>  m_world_manager;
        std::shared_ptr<SceneManager>  m_scene_manager;
        std::shared_ptr<PhysicsSystem> m_physics_system;
        std::shared_ptr<WindowSystem>  m_window_system;
        std::shared_ptr<RenderSystem>  m_render_system;
    };

    extern RuntimeGlobalContext g_runtime_global_context;
} // namespace Pilot