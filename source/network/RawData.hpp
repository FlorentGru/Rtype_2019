//
// Created by tfian on 28/11/2019.
//

#ifndef RTYPE_RAWDATA_HPP
#define RTYPE_RAWDATA_HPP

#include <iostream>

#define LENGTH 256

/**
 * Wraps raw data with its size in bytes
 */
struct RawData {
    RawData();

    /**
    * Construct a rawdata in bytes with its size (in bytes)
    *
    * @param data raw data for the packet
    * @param size size of the packet in bytes (max size of 256 bytes)
    *
    */
    RawData(const char *, size_t size);

    size_t size;
    char data[LENGTH];
};


#endif //RTYPE_RAWDATA_HPP
