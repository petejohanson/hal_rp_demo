#ifndef __RP2040_PINCTRL_H__
#define __RP2040_PINCTRL_H__

#define PINCTRL_GPIO_FUNC_XIP 0
#define PINCTRL_GPIO_FUNC_SPI 1
#define PINCTRL_GPIO_FUNC_UART 2
#define PINCTRL_GPIO_FUNC_I2C 3
#define PINCTRL_GPIO_FUNC_PWM 4
#define PINCTRL_GPIO_FUNC_SIO 5
#define PINCTRL_GPIO_FUNC_PIO0 6
#define PINCTRL_GPIO_FUNC_PIO1 7
#define PINCTRL_GPIO_FUNC_GPCK 8
#define PINCTRL_GPIO_FUNC_USB 9
#define PINCTRL_GPIO_FUNC_NULL 0xf

#define ALT_FUNC_POS 0
#define ALT_FUNC_MASK 0xf

#define PIN_NUM_POS 4
#define PIN_NUM_MASK 0x1f

#define RP2040_PINMUX(pin_num, alt_func) (pin_num << PIN_NUM_POS |	\
					alt_func << ALT_FUNC_POS)

#define UART0_TX_P0 RP2040_PINMUX(0, PINCTRL_GPIO_FUNC_UART)
#define UART0_RX_P1 RP2040_PINMUX(1, PINCTRL_GPIO_FUNC_UART)
#define UART0_CTS_P2 RP2040_PINMUX(2, PINCTRL_GPIO_FUNC_UART)
#define UART0_RTS_P3 RP2040_PINMUX(3, PINCTRL_GPIO_FUNC_UART)
#define UART1_TX_P4 RP2040_PINMUX(4, PINCTRL_GPIO_FUNC_UART)
#define UART1_RX_P5 RP2040_PINMUX(5, PINCTRL_GPIO_FUNC_UART)
#define UART1_CTS_P6 RP2040_PINMUX(6, PINCTRL_GPIO_FUNC_UART)
#define UART1_RTS_P7 RP2040_PINMUX(7, PINCTRL_GPIO_FUNC_UART)
#define UART1_TX_P8 RP2040_PINMUX(8, PINCTRL_GPIO_FUNC_UART)
#define UART1_RX_P9 RP2040_PINMUX(9, PINCTRL_GPIO_FUNC_UART)
#define UART1_CTS_P10 RP2040_PINMUX(10, PINCTRL_GPIO_FUNC_UART)
#define UART1_RTS_P11 RP2040_PINMUX(11, PINCTRL_GPIO_FUNC_UART)
#define UART0_TX_P12 RP2040_PINMUX(12, PINCTRL_GPIO_FUNC_UART)
#define UART0_RX_P13 RP2040_PINMUX(13, PINCTRL_GPIO_FUNC_UART)
#define UART0_CTS_P14 RP2040_PINMUX(14, PINCTRL_GPIO_FUNC_UART)
#define UART0_RTS_P15 RP2040_PINMUX(15, PINCTRL_GPIO_FUNC_UART)
#define UART0_TX_P16 RP2040_PINMUX(16, PINCTRL_GPIO_FUNC_UART)
#define UART0_RX_P17 RP2040_PINMUX(17, PINCTRL_GPIO_FUNC_UART)
#define UART0_CTS_P18 RP2040_PINMUX(18, PINCTRL_GPIO_FUNC_UART)
#define UART0_RTS_P19 RP2040_PINMUX(19, PINCTRL_GPIO_FUNC_UART)
#define UART1_TX_P20 RP2040_PINMUX(20, PINCTRL_GPIO_FUNC_UART)
#define UART1_RX_P21 RP2040_PINMUX(21, PINCTRL_GPIO_FUNC_UART)
#define UART1_CTS_P22 RP2040_PINMUX(22, PINCTRL_GPIO_FUNC_UART)
#define UART1_RTS_P23 RP2040_PINMUX(23, PINCTRL_GPIO_FUNC_UART)
#define UART1_TX_P24 RP2040_PINMUX(24, PINCTRL_GPIO_FUNC_UART)
#define UART1_RX_P25 RP2040_PINMUX(25, PINCTRL_GPIO_FUNC_UART)
#define UART1_CTS_P26 RP2040_PINMUX(26, PINCTRL_GPIO_FUNC_UART)
#define UART1_RTS_P27 RP2040_PINMUX(27, PINCTRL_GPIO_FUNC_UART)
#define UART0_TX_P28 RP2040_PINMUX(28, PINCTRL_GPIO_FUNC_UART)
#define UART0_RX_P29 RP2040_PINMUX(29, PINCTRL_GPIO_FUNC_UART)

#define SPI0_RX_P0 RP2040_PINMUX(0, PINCTRL_GPIO_FUNC_SPI)
#define SPI0_CSN_P1 RP2040_PINMUX(1, PINCTRL_GPIO_FUNC_SPI)
#define SPI0_SCK_P2 RP2040_PINMUX(2, PINCTRL_GPIO_FUNC_SPI)
#define SPI0_TX_P3 RP2040_PINMUX(3, PINCTRL_GPIO_FUNC_SPI)

#define SPI0_RX_P4 RP2040_PINMUX(4, PINCTRL_GPIO_FUNC_SPI)
#define SPI0_CSN_P5 RP2040_PINMUX(5, PINCTRL_GPIO_FUNC_SPI)
#define SPI0_SCK_P6 RP2040_PINMUX(6, PINCTRL_GPIO_FUNC_SPI)
#define SPI0_TX_P7 RP2040_PINMUX(7, PINCTRL_GPIO_FUNC_SPI)

#define SPI1_RX_P8 RP2040_PINMUX(8, PINCTRL_GPIO_FUNC_SPI)
#define SPI1_CSN_P9 RP2040_PINMUX(9, PINCTRL_GPIO_FUNC_SPI)
#define SPI1_SCK_P10 RP2040_PINMUX(10, PINCTRL_GPIO_FUNC_SPI)
#define SPI1_TX_P11 RP2040_PINMUX(11, PINCTRL_GPIO_FUNC_SPI)

#define SPI1_RX_P12 RP2040_PINMUX(12, PINCTRL_GPIO_FUNC_SPI)
#define SPI1_CSN_P13 RP2040_PINMUX(13, PINCTRL_GPIO_FUNC_SPI)
#define SPI1_SCK_P14 RP2040_PINMUX(14, PINCTRL_GPIO_FUNC_SPI)
#define SPI1_TX_P15 RP2040_PINMUX(15, PINCTRL_GPIO_FUNC_SPI)

#define SPI0_RX_P16 RP2040_PINMUX(16, PINCTRL_GPIO_FUNC_SPI)
#define SPI0_CSN_P17 RP2040_PINMUX(17, PINCTRL_GPIO_FUNC_SPI)
#define SPI0_SCK_P18 RP2040_PINMUX(18, PINCTRL_GPIO_FUNC_SPI)
#define SPI0_TX_P19 RP2040_PINMUX(19, PINCTRL_GPIO_FUNC_SPI)

#define SPI0_RX_P20 RP2040_PINMUX(20, PINCTRL_GPIO_FUNC_SPI)
#define SPI0_CSN_P21 RP2040_PINMUX(21, PINCTRL_GPIO_FUNC_SPI)
#define SPI0_SCK_P22 RP2040_PINMUX(22, PINCTRL_GPIO_FUNC_SPI)
#define SPI0_TX_P23 RP2040_PINMUX(23, PINCTRL_GPIO_FUNC_SPI)

#define SPI1_RX_P24 RP2040_PINMUX(24, PINCTRL_GPIO_FUNC_SPI)
#define SPI1_CSN_P25 RP2040_PINMUX(25, PINCTRL_GPIO_FUNC_SPI)
#define SPI1_SCK_P26 RP2040_PINMUX(26, PINCTRL_GPIO_FUNC_SPI)
#define SPI1_TX_P27 RP2040_PINMUX(27, PINCTRL_GPIO_FUNC_SPI)

#define SPI1_RX_P28 RP2040_PINMUX(28, PINCTRL_GPIO_FUNC_SPI)
#define SPI1_CSN_P29 RP2040_PINMUX(29, PINCTRL_GPIO_FUNC_SPI)

#endif /* __RP2040_PINCTRL_H__ */
