#include "Vector3.hpp"

#include <boost/interprocess/ipc/message_queue.hpp>
#include <iostream>

using namespace boost::interprocess;

int main ()
{
   try
   {
      // Open a message queue
      message_queue mq(open_only, "message_queue");

      unsigned int priority;
      message_queue::size_type recvd_size;

      // Receive 10
      for (int i = 0; i < 10; ++i)
      {
         Vector3 v;
         mq.receive(&v, sizeof(v), recvd_size, priority);
         if (recvd_size != sizeof(v))
         {
            return 1;
         }
         std::cout << "v = " << v.x << ", " << v.y << ", " << v.z << std::endl;
      }
   }
   catch (interprocess_exception &ex)
   {
      message_queue::remove("message_queue");
      std::cout << ex.what() << std::endl;
      return 1;
   }

   message_queue::remove("message_queue");
   return 0;
}
