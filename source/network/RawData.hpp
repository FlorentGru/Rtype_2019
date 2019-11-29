//
// Created by tfian on 28/11/2019.
//

#ifndef RTYPE_RAWDATA_HPP
#define RTYPE_RAWDATA_HPP

#include "PacketManager.hpp"

struct RawData {
    RawData();
    RawData(const char *, size_t size);

    size_t size;
    char data[Protocol::MAX_ENTITY_LENGTH];
};


#endif //RTYPE_RAWDATA_HPP
