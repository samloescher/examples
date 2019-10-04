#include <zmq.hpp>
#include <string>
#include <iostream>

int main ()
{
    zmq::context_t context (1);
    zmq::socket_t socket (context, ZMQ_REQ);

    socket.connect ("tcp://localhost:5555");

    while (true)
    {
        std::string message{"Hello"};
        zmq::message_t request(message.size());
        std::memcpy(request.data(), message.data(), message.size());

        std::cout << request.str() << " -> ";
        socket.send(request);

        zmq::message_t reply;
        socket.recv(&reply);

        std::cout << reply.str() << std::endl;
    }


    return 0;
}
