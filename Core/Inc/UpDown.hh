#pragma once

#include <MiddleLayer.hh>

class UpDown {
public:
    explicit UpDown(LibMecha::MiddleLayer::CytronMotorDriver *rightMd, LibMecha::MiddleLayer::CytronMotorDriver *leftMd);

    ~UpDown() = default;

    inline void init() {
        _rightMd->init();
        _leftMd->init();
    }

    void up();

    void down();

    void stop();

private:
    LibMecha::MiddleLayer::CytronMotorDriver *_rightMd;
    LibMecha::MiddleLayer::CytronMotorDriver *_leftMd;
};
