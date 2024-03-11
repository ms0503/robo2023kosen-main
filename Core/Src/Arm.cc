#include "Arm.hh"
#include <MiddleLayer.hh>

Arm::Arm(LibMecha::MiddleLayer::CytronMotorDriver *openCloseMd, LibMecha::MiddleLayer::CytronMotorDriver *upDownMd):
    _openCloseMd(openCloseMd),
    _upDownMd(upDownMd) {
}

void Arm::open() {
    _openCloseMd->setTarget(300);
}

void Arm::close() {
    _openCloseMd->setTarget(-300);
}

void Arm::openCloseStop() {
    _openCloseMd->setTarget(0);
}
