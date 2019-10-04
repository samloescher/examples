#include <zmq.hpp>
#include <string>
#include <chrono>
#include <thread>
#include <iostream>

int main ()
{
    zmq::context_t context(1);
    zmq::socket_t socket(context, ZMQ_REP);

    socket.bind("tcp://*:5555");

    while (true)
    {
        zmq::message_t request;
        socket.recv (&request);

        std::cout << request.str();

        std::this_thread::sleep_for(std::chrono::seconds{1});

        std::string message{"World"};
        zmq::message_t reply(5);
        std::memcpy(reply.data(), message.data(), message.size());

        std::cout << " -> " << reply.str() << std::endl;
        socket.send(reply);
    }
    return 0;
}
