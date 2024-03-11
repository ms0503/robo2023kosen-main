#pragma once

#include "Arm.hh"
#include "ComRecv.hh"
#include "ComSend.hh"
#include "RemoteEncoder.hh"
#include "UpDown.hh"
#include "params.hh"
#include "usart.h"
#include <Controller.hh>
#include <LED.hh>
#include <LowLayer.hh>
#include <MiddleLayer.hh>
#include <Steering.hh>
#include <memory>
#include <stm32f3xx_ll_usart.h>

SendBuffer buf;
bool comRecvComplete;
bool sbdbtRecvComplete;
std::vector<std::uint8_t> encBuf(6);

LibMecha::LowLayer::GPIO::Pin led1 {
    .gpio = GPIOE,
    .pin = LL_GPIO_PIN_12,
    .mode = LibMecha::LowLayer::GPIO::PinMode::OUTPUT
};

LibMecha::LowLayer::GPIO::Pin led2 {
    .gpio = GPIOE,
    .pin = LL_GPIO_PIN_13,
    .mode = LibMecha::LowLayer::GPIO::PinMode::OUTPUT
};

LibMecha::LowLayer::GPIO::Pin led3 {
    .gpio = GPIOE,
    .pin = LL_GPIO_PIN_14,
    .mode = LibMecha::LowLayer::GPIO::PinMode::OUTPUT
};

LibMecha::LowLayer::GPIO::Pin led4 {
    .gpio = GPIOE,
    .pin = LL_GPIO_PIN_15,
    .mode = LibMecha::LowLayer::GPIO::PinMode::OUTPUT
};

LibMecha::LED led({
    led1,
    led2,
    led3,
    led4
});

ComSend comTx(COM_USART, buf);
ComRecv comRx(COM_USART, comRecvComplete, [](const std::vector<std::uint8_t> &data) -> bool {
    encBuf = data;
    return true;
});

auto steeringRightMdEnc = std::make_unique<RemoteEncoder>(MD_ONE_ENC_ID, comTx, encBuf, comRecvComplete);
auto steeringLeftMdEnc = std::make_unique<RemoteEncoder>(MD_TWO_ENC_ID, comTx, encBuf, comRecvComplete);
auto upDownRightMdEnc = std::make_unique<RemoteEncoder>(MD_THREE_ENC_ID, comTx, encBuf, comRecvComplete);
auto upDownLeftMdEnc = std::make_unique<RemoteEncoder>(MD_FOUR_ENC_ID, comTx, encBuf, comRecvComplete);
auto armOpenCloseMdEnc = std::make_unique<RemoteEncoder>(MD_FIVE_ENC_ID, comTx, encBuf, comRecvComplete);
auto armUpDownMdEnc = std::make_unique<RemoteEncoder>(MD_SIX_ENC_ID, comTx, encBuf, comRecvComplete);

auto steeringRightMd = std::make_unique<LibMecha::MiddleLayer::CytronMotorDriver>(MAX_SPEED_RIGHT, steeringRightMdEnc.get(), MD_ONE_TIM, MD_ONE_TIM_CH, MD_ONE_PIN_DIR, 0, 0, 0, LibMecha::MiddleLayer::RotateDirection::NORMAL);
auto steeringLeftMd = std::make_unique<LibMecha::MiddleLayer::CytronMotorDriver>(MAX_SPEED_LEFT, steeringLeftMdEnc.get(), MD_TWO_TIM, MD_TWO_TIM_CH, MD_TWO_PIN_DIR, 0, 0, 0, LibMecha::MiddleLayer::RotateDirection::NORMAL);
auto upDownRightMd = std::make_unique<LibMecha::MiddleLayer::CytronMotorDriver>(100, upDownRightMdEnc.get(), MD_THREE_TIM, MD_THREE_TIM_CH, MD_THREE_PIN_DIR, 0, 0, 0, LibMecha::MiddleLayer::RotateDirection::NORMAL);
auto upDownLeftMd = std::make_unique<LibMecha::MiddleLayer::CytronMotorDriver>(100, upDownLeftMdEnc.get(), MD_FOUR_TIM, MD_FOUR_TIM_CH, MD_FOUR_PIN_DIR, 0, 0, 0, LibMecha::MiddleLayer::RotateDirection::REVERSE);
auto armOpenCloseMd = std::make_unique<LibMecha::MiddleLayer::CytronMotorDriver>(100, armOpenCloseMdEnc.get(), MD_FIVE_TIM, MD_FIVE_TIM_CH, MD_FIVE_PIN_DIR, 0, 0, 0, LibMecha::MiddleLayer::RotateDirection::NORMAL);
auto armUpDownMd = std::make_unique<LibMecha::MiddleLayer::CytronMotorDriver>(100, armUpDownMdEnc.get(), MD_SIX_TIM, MD_SIX_TIM_CH, MD_SIX_PIN_DIR, 0, 0, 0, LibMecha::MiddleLayer::RotateDirection::NORMAL);

auto steering = std::make_unique<LibMecha::Steering::CrawlerSteering<LibMecha::MiddleLayer::CytronMotorDriver>>(steeringRightMd.get(), steeringLeftMd.get());
auto upDown = std::make_unique<UpDown>(upDownRightMd.get(), upDownLeftMd.get());
auto arm = std::make_unique<Arm>(armOpenCloseMd.get(), armUpDownMd.get());

auto sbdbt = std::make_unique<LibMecha::MiddleLayer::SBDBT>(SBDBT_USART, sbdbtRecvComplete, MX_USART2_UART_Init);

LibMecha::Controller<LibMecha::Steering::CrawlerSteering<LibMecha::MiddleLayer::CytronMotorDriver>> ctrl(sbdbt.get(), steering.get());
