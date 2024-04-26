#ifndef HAZEL_ENTRYPOINT_H
#define HAZEL_ENTRYPOINT_H

extern Hazel::Application* Hazel::CreateApplication();

int main()
{
    //初始化Log
    Hazel::Log::Init();
    HZ_CORE_WARN("Initialized Log!");
    int a = 5;
    HZ_INFO("Hello! Var={0}", a);

    auto app = Hazel::CreateApplication();
    app->Run();
    delete app;
}

#endif //HAZEL_ENTRYPOINT_H
