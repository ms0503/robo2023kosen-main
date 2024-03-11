#pragma once

#include <MiddleLayer.hh>

class Arm {
public:
    explicit Arm(LibMecha::MiddleLayer::CytronMotorDriver *openCloseMd, LibMecha::MiddleLayer::CytronMotorDriver *upDownMd);

    ~Arm() = default;

    inline void init() {
        _openCloseMd->init();
        _upDownMd->init();
    }

    void open();

    void close();

    void openCloseStop();

private:
    LibMecha::MiddleLayer::CytronMotorDriver *_openCloseMd;
    LibMecha::MiddleLayer::CytronMotorDriver *_upDownMd;
};
