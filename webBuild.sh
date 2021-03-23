emcc --bind FernQuestBindings.cpp -Icpp src/Interact.cpp -s WASM=1 -s
MODULARIZE=1 -o FernQuestInteract.js
