#include "UpDown.hh"

UpDown::UpDown(LibMecha::MiddleLayer::CytronMotorDriver *rightMd, LibMecha::MiddleLayer::CytronMotorDriver *leftMd):
    _rightMd(rightMd),
    _leftMd(leftMd) {
}

void UpDown::up() {
    _rightMd->setTarget(100);
    _leftMd->setTarget(-100);
}

void UpDown::down() {
    _rightMd->setTarget(-100);
    _leftMd->setTarget(100);
}

void UpDown::stop() {
    _rightMd->setTarget(0);
    _leftMd->setTarget(0);
}
