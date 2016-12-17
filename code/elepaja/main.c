#include "main.h"
#include <stdint.h>
#include <stdio.h>
#if PLATFORM_MSP430
#include <msp430.h>
#elif PLATFORM_PSOC
#else
#error "Platform not specified"
#endif
#include "com.h"
// Include platform-specific libraries

void init_msp_clocks() {
  BCSCTL1 |= CALBC1_1MHZ;
  DCOCTL |= CALDCO_1MHZ;
}

void main(void)
{
#if PLATFORM_MSP430
  WDTCTL = WDTPW + WDTHOLD;     // Stop WDT
  init_msp_clocks();
  setup_spi();
#elif PLATFORM_PSOC
#error "Init not conf'd for PSOC yet"
#endif

  uint8_t tx[4] = {0x20, 0x4E, 0x24, 0x00};

  while(1)
  {
    transfer_packet(tx, NULL, 0); // send the first conf to SPI
#if PLATFORM_MSP430
    __bis_SR_register(LPM0_bits); // Go to eternal sleep - also MSP-specific
#elif PLATFORM_PSOC
#error "Loop not conf'd for PSOC yet"
#endif
  }
}
