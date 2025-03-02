#include "__preprocessor__.h"
#include "__time_stamp__.h"
#include "Multi_Dimension_View_Array.hpp"

#ifdef BUILD_EXECUTABLE
int main(int argc, char* argv[])
{
    Multi_Dimension_View_Array<int> my_array;

    i64 WIDTH  = 5;
    i64 HEIGHT = 500;
    i64 DEPTH  = 10;

    my_array.set_sizes(WIDTH, HEIGHT, DEPTH);

    for(u64 z = 0; z < DEPTH; z++)
    {
        for(u64 y = 0; y < HEIGHT; y++)
        {
            for(u64 x = 0; x < WIDTH; x++)
            {
                auto* ptr = my_array.get(x, y, z);
                if(ptr == nullptr) FATAL_ERROR("dupa");

                varr(z);
                varr(y);
                varr(x);
                cout << *ptr << '\n';
            }
        }
    }

    return 0;
}
#endif