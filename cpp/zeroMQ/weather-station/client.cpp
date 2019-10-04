#include <zmq.hpp>
#include <iostream>
#include <sstream>

int main (int argc, char *argv[])
{
    zmq::context_t context(1);

    std::cout << "Collecting updates from weather server..." << std::endl;
    zmq::socket_t subscriber (context, ZMQ_SUB);
    subscriber.connect("ipc://weather.ipc");

    std::string filter{"12"};
    subscriber.setsockopt(ZMQ_SUBSCRIBE, filter.c_str(), filter.size());

    int totalWet = 0;
    int updateCount = 100;
    for (auto i = 0; i < updateCount; i++)
    {
        zmq::message_t update;
        int location;
        bool isRaining = false;

        subscriber.recv(&update);
        std::cout << update.str() << std::endl;
        std::istringstream iss(static_cast<char*>(update.data()));
        iss >> location >> isRaining;
        totalWet += isRaining ? 1 : 0;
    }
    std::cout << "The percentage it rains in location '" << filter << "' is "
    << static_cast<double>(totalWet)/updateCount << std::endl;
    return 0;
}
