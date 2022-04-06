#include "ppi.h"
#include "gpiote.h"

void init_PPI()
{
    PPI->CHEN = 15;
    for (int i = 0; i < 5; i++) {
        PPI->PPI_CH[i].EEP = (uint32_t)&(GPIOTE->EVENTS_IN[0]);
        PPI->PPI_CH[i].TEP = (uint32_t)&(GPIOTE->TASKS_OUT[i+1]);
    }

}
