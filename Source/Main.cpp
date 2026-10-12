#include "Chip8.hpp"
#include "Platform.hpp"
#include <chrono>
#include <iostream>

int main(int argc, char** argv){
    if(argc != 4){
        std::cerr << "Usage: " << argv[0] << " <Scale> <Delay> <ROM>\n";
        std::exit(EXIT_FAILURE);
    }

    int videoScale = std::stoi(argv[1]);
    int CycleDelay = std::stoi(argv[2]);
    char const* romFilename = argv[3];

    Platform platform("CHIP-8 EMULATOR", VIDEO_WIDTH * videoScale, VIDEO_HEIGHT * videoScale, VIDEO_WIDTH, VIDEO_HEIGHT);


    Chip8 chip8;
    chip8.LoadROM(romFilename);

    int videoPitch = sizeof(chip8.video[0]) * VIDEO_WIDTH;

    auto lastCycleTime = std::chrono::high_resolution_clock::now();


    float instructionAccumulator = 0.0f;

    bool quit = false;

    while(!quit){
        quit = platform.ProcessInput(chip8.keypad);

        auto currentTime = std::chrono::high_resolution_clock::now();
        float dt = std::chrono::duration<float, std::chrono::milliseconds::period>(currentTime - lastCycleTime).count();
        lastCycleTime = currentTime;

        instructionAccumulator += dt;

        while (instructionAccumulator >= CycleDelay) {
            chip8.Cycle();
            instructionAccumulator -= CycleDelay;
        }

        chip8.UpdateTimers();

        chip8.waitingForVBlank = false;

        platform.Update(chip8.video, videoPitch);
    }

    return 0;
}
