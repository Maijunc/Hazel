
#ifndef HAZEL_APPLICATION_H
#define HAZEL_APPLICATION_H

#include "Core.h"
#include "Events/Event.h"

namespace Hazel {

    class Application
    {
    public:
        Application();
        virtual ~Application();

        void Run();
    };

    // To be defined in CLIENT
    Application* CreateApplication();
}



#endif //HAZEL_APPLICATION_H
