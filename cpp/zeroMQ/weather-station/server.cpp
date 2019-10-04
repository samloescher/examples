#include <zmq.hpp>
#include <random>
#include <thread>

int main ()
{
    zmq::context_t context(1);
    zmq::socket_t publisher(context, ZMQ_PUB);
    publisher.bind("ipc://weather.ipc");

    std::default_random_engine rand_engine;
    std::uniform_int_distribution<> rand_dist(0, 100);

    while (1)
    {
        int locationId = rand_dist(rand_engine);
        bool isRaining = rand_dist(rand_engine) > rand_dist.max() * 0.5;

        std::ostringstream message;
        message << locationId << " " << isRaining;
        auto messageStr = message.str();
        zmq::message_t update(messageStr.size());
        std::memcpy(update.data(), messageStr.data(), messageStr.size());
        publisher.send(update);

        std::this_thread::sleep_for(std::chrono::milliseconds{1});
    }
    return 0;
}
