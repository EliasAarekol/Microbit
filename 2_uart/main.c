#include "gpio.h"
#include "uart.h"

int main() {


    while (1)
    {
        if (!((GPIO0->IN)&((0x1<<14)))) {
			uart_send('A');
		}
        if (!((GPIO0->IN)&((0x1<<23)))) {
			uart_send('B');
        }
    }

    if (uart_read() != '\0') {
        if (GPIO0->OUT == 0x2FFFF7FF) {
            GPIO0->OUT = !0x2FFFF7FF;
			GPIO1->OUT = 0x1 << 5;
        }
        else {
            GPIO0->OUT = 0x2FFFF7FF;
			GPIO1->OUT = 0x0 << 5;
        }

    }
    

    return 0;
}