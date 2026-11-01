#ifndef CHIP8_H
#define CHIP8_H

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <time.h>

struct Chip8 {
    unsigned char corriendo;
    unsigned short opcodigo;
    unsigned char memory[4096];
    unsigned char V[16];
    unsigned short I;
    unsigned short pc;
    unsigned char gfx[64 * 32];
    unsigned char draw;
    unsigned char contador_delay;
    unsigned char contador_sonido;
    unsigned short stack[16];
    unsigned short sp;
    unsigned char key[16];
};

typedef struct Chip8 Chip8;

Chip8* chip8Init(void);
void chip8Destroy(Chip8* chip8);
void chip8ExecuteOpcodigo(Chip8* chip8, short opcodigo);
void chip8UpdateTimers(Chip8* chip8);
void chip8ClearKeys(Chip8* chip8);
void chip8SetKeyDown(Chip8* chip8, unsigned char key);
void chip8SetKeyUp(Chip8* chip8, unsigned char key);
void chip8DrawGraphics(Chip8* chip8);
void chip8LoadProgram(Chip8* chip8, char* program);

#endif