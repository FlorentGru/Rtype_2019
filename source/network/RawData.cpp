//
// Created by tfian on 28/11/2019.
//

#include "RawData.hpp"
#include <cstring>

RawData::RawData()
{
    memset(this->data, 0, Protocol::MAX_ENTITY_LENGTH);
    this->size = 0;
}

RawData::RawData(const char *_data, size_t size)
{
    memset(this->data, 0, Protocol::MAX_ENTITY_LENGTH);
    if (size <= Protocol::MAX_ENTITY_LENGTH) {
        memcpy(this->data, _data, size);
        this->size = size;
    }
}
