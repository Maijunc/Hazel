//
// Created by 麦天骏 on 2024/4/23.
//

#ifndef HAZEL_APPLICATION_H
#define HAZEL_APPLICATION_H

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
