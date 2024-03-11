#pragma once

#include "ComRecv.hh"
#include "ComSend.hh"
#include "LowLayer.hh"
#include <cstdint>
#include <vector>

class RemoteEncoder : public LibMecha::LowLayer::Encoder {
public:
    enum class Cmd : std::uint8_t {
        GET_ROT        = 0b00010,
        GET_DELTA_ROT  = 0b00011,
        GET_DEG        = 0b00100,
        GET_DELTA_DEG  = 0b00101,
        GET_RAD        = 0b01000,
        GET_DELTA_RAD  = 0b01001,
        GET_REVL       = 0b10000,
        GET_DELTA_REVL = 0b10001
    };

    explicit RemoteEncoder(std::uint8_t id, ComSend &sender, std::vector<std::uint8_t> &buf, bool &recvComplete);

    [[nodiscard]] inline std::int32_t getRot() const override {
        return getData<std::int32_t>(Cmd::GET_ROT);
    }

    [[nodiscard]] inline std::int32_t getDeltaRot() const override {
        return getData<std::int32_t>(Cmd::GET_DELTA_ROT);
    }

    [[nodiscard]] inline float getDegree() const override {
        return getData<float>(Cmd::GET_DEG);
    }

    [[nodiscard]] inline float getDeltaDegree() const override {
        return getData<float>(Cmd::GET_DELTA_DEG);
    }

    [[nodiscard]] inline float getRadian() const override {
        return getData<float>(Cmd::GET_RAD);
    }

    [[nodiscard]] inline float getDeltaRadian() const override {
        return getData<float>(Cmd::GET_DELTA_RAD);
    }

    [[nodiscard]] inline std::int32_t getRevolution() const override {
        return getData<std::int32_t>(Cmd::GET_REVL);
    }

    [[nodiscard]] inline std::int32_t getDeltaRevolution() const override {
        return getData<std::int32_t>(Cmd::GET_DELTA_REVL);
    }

private:
    std::uint8_t _id;
    ComSend &_sender;
    std::vector<std::uint8_t> &_buf;
    bool &_recvComplete;

    template<typename RET_TYPE>
    [[nodiscard]] RET_TYPE getData(Cmd cmd) const;
};
