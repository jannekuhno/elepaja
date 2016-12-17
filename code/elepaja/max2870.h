/*
 * max2870.h
 *
 *  Created on: 17 Dec 2016
 *      Author: Janne Kuhno
 */

#ifndef MAX2870_H_
#define MAX2870_H_

#define REG0 0x00
#define REG1 0x01
#define REG2 0x02
#define REG3 0x03
#define REG4 0x04
#define REG5 0x05
#define REG6 0x06

//Reg 0 conf
#define INT 0x80000000 //integer-n mode, conf LDF bit accordingly
#define I_SHIFT 15 // Integer Division Value location
#define FRAC_SHIFT 3 // Fractional Division Value location

//Reg 1 conf
#define CPOC 0x80000000 // Charge pump output clamp enable
#define CPL_0 0x00000000 // Disable CP linearity (int-n)
#define CPL_1 0x20000000 // Enable CP linearity (frac-n)
#define CPT_0 0x00000000 // Normal mode
#define CPT_2 0x10000000 // Force CP source mode
#define CPT_3 0x18000000 // Force CP sink mode
#define P_SHIFT 15 // Phase value location
#define M_SHIFT 3 // Modulus value location

//Reg 2 conf
#define LDS 0x80000000 // Lock-detect speed adjustment
#define SDN_0 0x00000000 // Low-noise mode
#define SDN_2 0x40000000 // Low-spur mode 1
#define SDN_3 0x60000000 // Low-spur mode 2
// MUXOUT pin conf
#define MUX_0 0x00000000 // Three-state output
#define MUX_1 0x04000000 // D_VDD
#define MUX_2 0x08000000 // D_GND
#define MUX_3 0x0C000000 // R-divider output
#define MUX_4 0x10000000 // N-divider output/2
#define MUX_5 0x14000000 // Analog clock detect
#define MUX_6 0x18000000 // Digital clock detect
#define MUX_12 0x10000000 // MUXOUT confd as serial out for REG6

#define DBR 0x02000000 // Reference doubler enable
#define RDIV2 0x01000000 // Reference divide by 2
#define R_SHIFT 14 // Reference divider value location
#define REG4DB 0x00002000 // Double buffer enable
#define CP_SHIFT 9 // Charge pump current location
#define LDF 0x00000100 // Int-N lock detect
#define LDP 0x00000080 // Lock detect precision 6nS
#define PDP 0x00000040 // Phase detector positive polarity
#define SHDN 0x00000020 // Device shutdown
#define TRI 0x00000010 // Charge pump three-state mode enable
#define RST 0x00000008 // Reset R and N counters

// Reg 3 conf
#define VCO_SHIFT 26 // VCO sub-band select location
#define VAS_SHDN 0x04000000 // VAS disabled
#define RETUNE 0x02000000 // VAS auto-retune over temp enabled
#define CDM_0 0x00000000 // Clock divider off
#define CDM_1 0x00008000 // Fast-lock enabled
#define CDM_2 0x00010000 // Phase mode
#define CDIV_SHIFT 3 // CLock divider 12-bit value location

// Reg 4 conf
#define FB 0x01000000 // VCO to N counter fundamental feedback mode
#define MAX_DIVA_1 0x00000000 // Divide by 1
#define MAX_DIVA_2 0x00200000 // Divide by 2
#define MAX_DIVA_4 0x00400000 // Divide by 4
#define MAX_DIVA_8 0x00600000 // Divide by 8
#define MAX_DIVA_16 0x00800000 // Divide by 16
#define MAX_DIVA_32 0x00A00000 // Divide by 32
#define MAX_DIVA_64 0x00C00000 // Divide by 64
#define MAX_DIVA_128 0x00E00000 // Divide by 128

#define BS_MSBs_SHIFT 24 // Band select 2 MSBs
#define BS_SHIFT 12 // 10-bit band select location, check 2 MSBs

#define BDIV 0x00000200 // RFOUTB VCO fundamental frequency

#define RFB_EN 0x00000100 // RFOUTB output enabled
#define BPWR_0 0x00000000 // single-ended power -4dBm
#define BPWR_1 0x00000040 // -1dBm
#define BPWR_2 0x00000080 // +2dBm
#define BPWR_3 0x000000C0 // +5dBm

#define RFA_EN 0x00000020 // RFOUTB output enabled
#define APWR_0 0x00000000 // single-ended power -4dBm
#define APWR_1 0x00000008 // -1dBm
#define APWR_2 0x00000010 // +2dBm
#define APWR_3 0x00000018 // +5dBm

// Reg 5 conf
#define F01 0x01000000 // If F[11:0] = 0, Int-N mode auto set
#define LD_0 0x00000000 // Lock-detect pin Low
#define LD_1 0x00400000 // Digital lock detect
#define LD_2 0x00800000 // Analog lock detect
#define LD_3 0x00C00000 // Lock-detect pin High
#define MUX 0x00040000 // MUX MSB

#endif /* MAX2870_H_ */
