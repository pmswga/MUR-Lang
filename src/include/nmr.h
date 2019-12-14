#ifndef NMR_H_INCLUDED
#define NMR_H_INCLUDED

class NMR
{
    int *registers;
    int registers_count;

public:
    NMR();
    NMR(int *registers, int registers_count);
    int R(int n); /// Get value from `n` register

    void Z(int n); /// Set zero in `n` register
    void S(int n); /// Increment `n` register
    void T(int m, int n); /// Copy value from `m` register to `n` register
    bool J(int m, int n); /// In original J(m, n, q)
};


#endif // NMR_H_INCLUDED
