#pragma once

#include <LowLayer.hh>
#include <MiddleLayer.hh>
#include <cstdint>
#include <stm32f3xx_ll_gpio.h>
#include <stm32f3xx_ll_tim.h>
#include <stm32f3xx_ll_usart.h>

constexpr const std::int32_t MAX_SPEED_RIGHT = 250;
constexpr const std::int32_t MAX_SPEED_LEFT = 250;

USART_TypeDef *const COM_USART = USART3;
USART_TypeDef *const SBDBT_USART = USART2;

TIM_TypeDef *const MD_ONE_TIM = TIM4;
constexpr const std::uint32_t MD_ONE_TIM_CH = LL_TIM_CHANNEL_CH1;
const LibMecha::LowLayer::GPIO::Pin MD_ONE_PIN_DIR = {
    .gpio = GPIOG,
    .pin = LL_GPIO_PIN_13,
    .mode = LibMecha::LowLayer::GPIO::PinMode::OUTPUT
};
constexpr const std::uint8_t MD_ONE_ENC_ID = 0;

TIM_TypeDef *const MD_TWO_TIM = TIM4;
constexpr const std::uint32_t MD_TWO_TIM_CH = LL_TIM_CHANNEL_CH2;
const LibMecha::LowLayer::GPIO::Pin MD_TWO_PIN_DIR = {
    .gpio = GPIOG,
    .pin = LL_GPIO_PIN_12,
    .mode = LibMecha::LowLayer::GPIO::PinMode::OUTPUT
};
constexpr const std::uint8_t MD_TWO_ENC_ID = 1;

TIM_TypeDef *const MD_THREE_TIM = TIM4;
constexpr const std::uint32_t MD_THREE_TIM_CH = LL_TIM_CHANNEL_CH3;
const LibMecha::LowLayer::GPIO::Pin MD_THREE_PIN_DIR = {
    .gpio = GPIOG,
    .pin = LL_GPIO_PIN_11,
    .mode = LibMecha::LowLayer::GPIO::PinMode::OUTPUT
};
constexpr const std::uint8_t MD_THREE_ENC_ID = 2;

TIM_TypeDef *const MD_FOUR_TIM = TIM4;
constexpr const std::uint32_t MD_FOUR_TIM_CH = LL_TIM_CHANNEL_CH4;
const LibMecha::LowLayer::GPIO::Pin MD_FOUR_PIN_DIR = {
    .gpio = GPIOG,
    .pin = LL_GPIO_PIN_10,
    .mode = LibMecha::LowLayer::GPIO::PinMode::OUTPUT
};
constexpr const std::uint8_t MD_FOUR_ENC_ID = 3;

TIM_TypeDef *const MD_FIVE_TIM = TIM8;
constexpr const std::uint32_t MD_FIVE_TIM_CH = LL_TIM_CHANNEL_CH1;
const LibMecha::LowLayer::GPIO::Pin MD_FIVE_PIN_DIR = {
    .gpio = GPIOB,
    .pin = LL_GPIO_PIN_12,
    .mode = LibMecha::LowLayer::GPIO::PinMode::OUTPUT
};
constexpr const std::uint8_t MD_FIVE_ENC_ID = 4;

TIM_TypeDef *const MD_SIX_TIM = TIM8;
constexpr const std::uint32_t MD_SIX_TIM_CH = LL_TIM_CHANNEL_CH2;
const LibMecha::LowLayer::GPIO::Pin MD_SIX_PIN_DIR = {
    .gpio = GPIOB,
    .pin = LL_GPIO_PIN_13,
    .mode = LibMecha::LowLayer::GPIO::PinMode::OUTPUT
};
constexpr const std::uint8_t MD_SIX_ENC_ID = 5;
