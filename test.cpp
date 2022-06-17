#include <iostream>
#include <cstddef>

int main()
{
    const std::size_t N = 10;
    char* a = new char[N];
    for (std::size_t i = 0; i < N; ++i)
        a[i] = i;
    char* end = a + N;
    for (std::ptrdiff_t i = N; i > 0; --i)
        std::cout << (*(end - i) = i) << ' ' << std::endl;
    delete[] a;
}