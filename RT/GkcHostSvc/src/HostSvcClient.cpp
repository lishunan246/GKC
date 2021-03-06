//
// Created by lishunan on 16-3-31.
//

#include "HostSvcCommon.h"

using asio::ip::tcp;
using namespace GkcHostSvc;
const static std::string server("127.0.0.1");

int main() {
    try {
        asio::io_service io_service;

        tcp::resolver resolver(io_service);
        tcp::resolver::query query(server, PORT);
        tcp::resolver::iterator endpoint_iterator = resolver.resolve(query);

        tcp::socket socket(io_service);
        asio::connect(socket, endpoint_iterator);

        for (; ;) {
            std::array<char, 128> buf;
            asio::error_code error;

            size_t len = socket.read_some(asio::buffer(buf), error);

            if (error == asio::error::eof)
                break; // Connection closed cleanly by peer.
            else if (error)
                throw asio::system_error(error); // Some other error.

            std::cout.write(buf.data(), len);
        }
    }
    catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
