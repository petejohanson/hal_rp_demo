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

#define PULLUP_POS 5
#define PULLUP_MASK 1

#define PULLDOWN_POS 6
#define PULLDOWN_MASK 1

#define RP2040_PINCTRL(pin_num, alt_func, pullup, pulldown)	\
	(pin_num << PIN_NUM_POS |				\
	alt_func << ALT_FUNC_POS |				\
	pullup << PULLUP_POS |					\
	pulldown << PULLDOWN_POS)

#define RP2040_GET_PIN_NUM(pinctrl) ((pinctrl >> PIN_NUM_POS) & PIN_NUM_MASK)
#define RP2040_GET_ALT_FUNC(pinctrl) ((pinctrl >> ALT_FUNC_POS) & ALT_FUNC_MASK)
#define RP2040_GET_PULLUP(pinctrl) ((pinctrl >> PULLUP_POS) & PULLUP_MASK)
#define RP2040_GET_PULLDOWN(pinctrl) ((pinctrl >> PULLDOWN_POS) & PULLDOWN_MASK)

#define UART0_TX_P0 \
	RP2040_PINCTRL(0, PINCTRL_GPIO_FUNC_UART, 0, 0)

#define UART0_RX_P1 \
	RP2040_PINCTRL(1, PINCTRL_GPIO_FUNC_UART, 0, 0)

#endif /* __RP2040_PINCTRL_H__ */
