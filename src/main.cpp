#include <Engine/Engine.hpp>

#include <PluginSDK.hpp>

PLUGIN_FUNC void OnInit(obe::Engine::Engine &engine) {
    const obe::Debug::Logger Log = engine.getLogger();
    Log->info("Hello, world!");
}
