

#ifndef CHIP_8_CHIP8_H
#define CHIP_8_CHIP8_H

#include <cstdint>
#include <string>
#include <stack>
#include <SDL3/SDL.h>

typedef struct Chip8configuration{
    uint32_t fg_colour = 0xFff0F0f0;
    float F_colour[4] = {255.0f,0xf0,0xf0,0xf0};
    float B_colour[4] = {0,255,19,90};

    uint32_t bg_colour = 0x505050f0;
    int height = 32;
    int width = 64;
    float scale = 10;

    bool BNNN_quirk = false;//Activate or not the quirk
    bool SHIFT = false;//Activate the shift quirk
    bool MEM_QUIRK = false;//adivina

}ChipConfig;

typedef struct{
    uint8_t h3 ;
    uint8_t h2;
    uint8_t h1 ;
    uint8_t h0;
} inst_format;

class Chip8
{

public:
    int state = 0;
    bool tecla_pulsada = false;
    bool released = true;
    uint8_t presed_key;
    bool started = false;

    ChipConfig config;

    uint16_t pcAnterior = 0;
    uint16_t instruccionActual = 0 ;
    inst_format instruccionActual_Formated;
    bool draw_flag = false;



    //Registros
    bool error;
        uint8_t V[16];//16 8 bit general porpoise register Vx x form 0 to F

        uint16_t I, PC; // 16 bit register I for memory addresses and PC counter

        int sp;


        uint16_t stack[16];

        uint8_t delay_timer,sound_timer;


    //Memoria ram
        uint8_t memoryRam[4096]; // 0x000-0x1FF Reserved for interpreter, 0x200-0xFFF Program
    //Teclado
        bool keyboard[16]; //teclado exadecimal
    //Display
        int display[64*32];
public:
    Chip8(const char *,Chip8configuration);

    void executeInst();
    void formatInstruction ();
    void drawDisplay(SDL_Renderer *renderer,SDL_Texture *displayTexture);
    bool fetch();
};





#endif //CHIP_8_CHIP8_H

