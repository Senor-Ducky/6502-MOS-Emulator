#include<stdio.h>
#include<stdlib.h>

using Byte = unsigned char;
using Word = unsigned short;
using u32 = unsigned int;

struct MEM 
{
    static constexpr u32 MAX_MEM = 1024 * 64;
    Byte Data[MAX_MEM];

    void initialize() 
    {
        for (u32 = 0; i < MAX_MEM; i++)
        {
            Data[i] = 0;
        };
    };
};

struct CPU
{
    

    Word PC; //program counter
    Word SP; // stack pointer

    Byte A,X,Y; //registers

    Byte C : 1; //status flags
    Byte Z : 1;
    Byte I : 1;
    Byte D : 1;
    Byte B : 1;
    Byte V : 1;
    Byte N : 1;

    void Reset(MEM& memory) 
    {
        PC = 0xFFFC;
        C = Z = I = D = B = V = N = 0;
        SP = 0x0100;
        A = X = Y = 0;
        memory.initialize();
    };

    Byte FetchByte(u32 Cycles, MEM& memory)
    {
        Byte Data = memory[PC];
        PC++;
        Cycles--;
        return Data;
    };

    Byte operator[] (u32 address) const //read 1 byte
    {
        return Data[address];
    }

    void execute(u32 Cycles, MEM& memory)
    {
        while(Cycle > 0)
        {
            Byte ins = FetchByte(Cycles, memory);
            (void)ins;
        };
    };
    
};

int main() {
    MEM mem;
    CPU cpu;
    cpu.Reset(mem);
    cpu.execute(2, mem);
    return 0;
};