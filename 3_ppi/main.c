#include "ppi.h"

int main()
{
    gpiote_init();
    init_PPI();

    while (1);

    return 0; 
}