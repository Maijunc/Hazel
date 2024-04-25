#ifndef HAZEL_ENTRYPOINT_H
#define HAZEL_ENTRYPOINT_H

extern Hazel::Application* Hazel::CreateApplication();

int main()
{
    auto app = Hazel::CreateApplication();
    app->Run();
    delete app;
}

#endif //HAZEL_ENTRYPOINT_H
