//
// Created by lishunan on 16-3-31.
//

#ifndef GKC_HOSTSVCCOMMON_H
#define GKC_HOSTSVCCOMMON_H
#define ASIO_STANDALONE 
#define ASIO_HAS_STD_ADDRESSOF
#define ASIO_HAS_STD_ARRAY
#define ASIO_HAS_CSTDINT
#define ASIO_HAS_STD_SHARED_PTR
#define ASIO_HAS_STD_TYPE_TRAITS

#ifdef _MSC_VER
#pragma comment(linker, "/SUBSYSTEM:CONSOLE")
#endif
#include <iostream>
#include <asio.hpp>
#include <string>

namespace GkcHostSvc {
    static const int PORT_INT(10000);
    static const std::string PORT("10000");
}
#endif //GKC_HOSTSVCCOMMON_H
