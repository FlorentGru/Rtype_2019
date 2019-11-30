//
// Created by tfian on 28/11/2019.
//

#include "RawData.hpp"
#include <cstring>

RawData::RawData()
{
    memset(this->data, 0, LENGTH);
    this->size = 0;
}

RawData::RawData(const char *_data, size_t size_)
{
    memset(this->data, 0, LENGTH);
    if (size_ <= LENGTH) {
        memcpy(this->data, _data, size_);
        this->size = size_;
    }
}
