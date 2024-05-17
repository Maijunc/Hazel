#ifndef MYPROJECT_EVENT_H
#define MYPROJECT_EVENT_H

#include "../Core.h"

#include <string>
#include <functional>

namespace Hazel {

    // Events in Hazel are currently blocking, meaning when an event orrurs it
    // immediately gets dispatched and must be dealt with right then an there
    // For the future, a better strategy might be to buffer events in an event
    // bus and process them during the "event" part of the update stage

    // 事件类型的一个枚举类
    enum class EventType
    {
        None = 0,
        WindowClose, WindowResize, WindowFocus, WindowLostFocus, WindowMoved,
        AppTick, AppUpdate, AppRender,
        KeyPressed, KeyReleased,
        MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled
    };

    // 将事件分类，不同的事件类占一个位置 如11111表示该Event同时属于5个类别
    // 用二进制码来表示各个事件的编号
    enum EventCategory
    {
        None = 0,
        EventCategoryApplication    =  BIT(0),
        EventCategoryInput          =  BIT(1),
        EventCategoryKeyboard       =  BIT(2),
        EventCategoryMouse          =  BIT(3),
        EventCategoryMouseButton    =  BIT(4)
    };

//Event Construction Macros
#define EVENT_CLASS_TYPE(type) static EventType GetStaticType() {return EventType::type;}\
                virtual EventType GetEventType() const override {return GetStaticType();}\
                virtual const char* GetName() const override {return #type;}

    //一个marco，本质上是一个GetCategoryFlags函数，用于获取Event的Category值
#define EVENT_CLASS_CATEGORY(category) virtual int GetCategoryFlags() const override { return category; }

    // param :
    // 可见，这是一个基础的事件类，有很多的纯虚函数声明需要去实现
    class Event
    {
        friend class EventDispatcher; //事件调度器
    public:
        // 纯虚函数声明 可以看作一个接口 virutal ... = 0
        virtual EventType GetEventType() const = 0;
        virtual const char* GetName() const = 0;
        virtual int GetCategoryFlags() const = 0;
        virtual std::string ToString() const { return GetName(); }

        inline bool IsInCategory(EventCategory category)
        {
            return GetCategoryFlags() & category;
        }
    protected:
        bool m_Handled = false;
    };

    //事件分发器，用来将事件与一个function绑定(bind)
    class EventDispatcher
    {
        template<typename T>
        using EventFn = std::function<bool(T&)>; //转义，相当于起别名
    public:
        EventDispatcher(Event& event)
            : m_Event(event)
        {
        }

        template<typename T>
        bool Dispatch(EventFn<T> func)
        {
            if(m_Event.GetEventType() == T::GetStaticType())
            {
                m_Event.m_Handled = func(*(T*)&m_Event);
                return true;
            }
            return false;
        }
    private:
        Event& m_Event;
    };

    inline std::ostream& operator<<(std::ostream& os, const Event& e)
    {
        return os << e.ToString();
    }
}

#endif //MYPROJECT_EVENT_H
