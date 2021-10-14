#include <lrdb/server.hpp>

#include <Engine/Engine.hpp>

#include <PluginSDK.hpp>

constexpr short DEBUGGER_PORT = 21122;

inline lrdb::server debug_server(DEBUGGER_PORT);

PLUGIN_FUNC void OnInit(obe::Engine::Engine &engine) {
  const obe::Debug::Logger Log = engine.getLogger();

  Log->info("Debugger waiting on port {}", DEBUGGER_PORT);

  obe::Script::LuaState &state = engine.getLuaState();

  debug_server.reset(state.lua_state());
}

PLUGIN_FUNC void OnExit()
{
    debug_server.reset();
}
