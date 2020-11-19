#ifndef __nRF24L01_H_
#define __nRF24L01_H_
#include<reg52.h>

#define ADDR_WIDTH   5  				// 5字节宽度的发送/接收地址
#define PLOAD_WIDTH 6  				// 数据通道有效数据宽度

/**************命令定义************************/
#define READ_REG        0x00  // Define read command to register
#define WRITE_REG       0x20  // Define write command to register
#define RD_RX_PLOAD     0x61  // Define RX payload register address
#define WR_TX_PLOAD     0xA0  // Define TX payload register address
#define FLUSH_TX        0xE1  // Define flush TX register command
#define FLUSH_RX        0xE2  // Define flush RX register command
#define REUSE_TX_PL     0xE3  // Define reuse TX payload register command
#define NOP             0xFF  // Define No Operation, might be used to read status register

/**********SPI(SI24R1) registers(addresses)******寄存器地址*******/
#define CONFIG          0x00  // 'Config' register address
#define EN_AA           0x01  // 'Enable Auto Acknowledgment' register address
#define EN_RXADDR       0x02  // 'Enabled RX addresses' register address
#define SETUP_AW        0x03  // 'Setup address width' register address
#define SETUP_RETR      0x04  // 'Setup Auto. Retrans' register address
#define RF_CH           0x05  // 'RF channel' register address
#define RF_SETUP        0x06  // 'RF setup' register address
#define STATUS          0x07  // 'Status' register address
#define OBSERVE_TX      0x08  // 'Observe TX' register address
#define RSSI            0x09  // 'Received Signal Strength Indecator' register address
#define RX_ADDR_P0      0x0A  // 'RX address pipe0' register address
#define RX_ADDR_P1      0x0B  // 'RX address pipe1' register address
#define RX_ADDR_P2      0x0C  // 'RX address pipe2' register address
#define RX_ADDR_P3      0x0D  // 'RX address pipe3' register address
#define RX_ADDR_P4      0x0E  // 'RX address pipe4' register address
#define RX_ADDR_P5      0x0F  // 'RX address pipe5' register address
#define TX_ADDR         0x10  // 'TX address' register address
#define RX_PW_P0        0x11  // 'RX payload width, pipe0' register address
#define RX_PW_P1        0x12  // 'RX payload width, pipe1' register address
#define RX_PW_P2        0x13  // 'RX payload width, pipe2' register address
#define RX_PW_P3        0x14  // 'RX payload width, pipe3' register address
#define RX_PW_P4        0x15  // 'RX payload width, pipe4' register address
#define RX_PW_P5        0x16  // 'RX payload width, pipe5' register address
#define FIFO_STATUS     0x17  // 'FIFO Status Register' register address
#define DYNPD						0x1C	//使能“动态负载长度”，即发送数据的长度可以不固定
#define	FEATURE					0x1D	//特征寄存器

/*************STATUS Register ****************/
#define RX_DR						0x40  /**/
#define TX_DS						0x20
#define MAX_RT					0x10

/***********SI24R1 PIN DEFINITION***************/
sbit	CSN   =   P3^0;        // Slave Select pin, (output to CSN)
sbit	MOSI  =   P3^1 ;        // Master Out, Slave In pin (output)
sbit	IRQ   =   P3^3;        // Interrupt signal, from nRF24L01 (input)

sbit	MISO  =   P3^5  ;       // Master In, Slave Out pin (input)
sbit	SCK   =   P3^6  ;        // Serial Clock pin, (output)
sbit	CE    =   P3^7;         // Chip Enable pin signal (output)


typedef unsigned char u8;
typedef unsigned int u16;


/****************FUNCTION's PROTOTYPES*****************/
static u8 SPI_RW(u8 byte);
void SI24R1_Init(void); //SI24R1 Pin Init
u8 SI24R1_Write_Reg(u8 reg, u8 value); 
u8 SI24R1_Write_Buf(u8 reg, const u8 *pBuf, u8 bytes);
u8 SI24R1_Read_Reg(u8 reg);
u8 SI24R1_Read_Buf(u8 reg, u8 *pBuf, u8 bytes);

void SI24R1_RX_Mode(void);
void SI24R1_RX_Mode_multichannel(void);
void SI24R1_TX_Mode(void);
void SI24R1_TX_Mode_multichannel(void);

u8 SI24R1_RxPacket(u8 *rxbuf);
u8 SI24R1_TxPacket(u8 *txbuf);

#endif
