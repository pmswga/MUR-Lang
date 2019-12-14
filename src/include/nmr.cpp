#include "nmr.h"

NMR::NMR() : registers(nullptr), registers_count(0)
{
}

NMR::NMR(int *registers, int registers_count) : registers_count(registers_count)
{
    if (registers != nullptr) {
        this->registers = new int[registers_count];

        for (int i = 0; i < registers_count; i++) {
            this->registers[i] = registers[i];
        }
    }
}

int NMR::R(int n)
{
    if (n >= 1 && n <= registers_count) {
        return registers[n-1];
    }

    return 0;
}

void NMR::Z(int n)
{
    if (n >= 1 && n <= registers_count) {
        registers[n-1] = 0;
    }
}

void NMR::S(int n)
{
    if (n >= 1 && n <= registers_count) {
        registers[n-1]++;
    }
}

void NMR::T(int m, int n)
{
    if (n >= 1 && n <= registers_count && m >= 1 && m <= registers_count) {
        registers[n-1] = registers[m-1];
    }
}

bool NMR::J(int m, int n)
{
    if (n >= 1 && n <= registers_count && m >= 1 && m <= registers_count) {
        return registers[n-1] == registers[m-1];
    }

    return false;
}
