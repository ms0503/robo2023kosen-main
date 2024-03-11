#include "LowLayer.hh"
#include "RemoteEncoder.hh"
#include <cstdint>
#include <vector>

RemoteEncoder::RemoteEncoder(std::uint8_t id, ComSend &sender, std::vector<std::uint8_t> &buf, bool &recvComplete):
    _id(id),
    _sender(sender),
    _buf(buf),
    _recvComplete(recvComplete) {
}

template<typename RET_TYPE>
RET_TYPE RemoteEncoder::getData(Cmd cmd) const {
    _sender.send({
        static_cast<std::uint8_t>(cmd),
        _id
    });
    while(!_recvComplete);
    std::vector<std::uint8_t> result(_buf.begin() + 1, _buf.end() - 1);
    _recvComplete = false;
    auto &data = reinterpret_cast<RET_TYPE &>(*result.data());
    return data;
}
