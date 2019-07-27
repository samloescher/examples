#include "Vector3.hpp"

#include <boost/interprocess/ipc/message_queue.hpp>
#include <iostream>

using namespace boost::interprocess;

int main ()
{
    try
    {
        // Erase previous message queue
        message_queue::remove("message_queue");

        // Create a message_queue
        message_queue mq(create_only, "message_queue", 10, sizeof(Vector3));

        // Send 10
        for (int i = 0; i < 10; ++i)
        {
            Vector3 v;
            v.x = i; v.y = i; v.z = i;
            mq.send(&v, sizeof(v), 0);
            std::cout << "v = " << v.x << ", " << v.y << ", " << v.z << std::endl;
        }
    }
    catch (interprocess_exception &ex)
    {
        std::cout << ex.what() << std::endl;
        return 1;
    }

    return 0;
}
