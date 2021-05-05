//
// Created by Codie Cottrell on 3/21/21.
//

#include <emscripten.h>
#include <emscripten/bind.h>
#include <string>
#include "src/Interact.h"

using namespace emscripten;

EMSCRIPTEN_BINDINGS(Interact) {
    function("playerMove", optional_override([]() -> std::string {
        return Interact::playerMove();
    }));

    function("playerItemInteract", optional_override([](std::string item) -> std::string {
        return Interact::playerItemInteract(item);
    }));
};