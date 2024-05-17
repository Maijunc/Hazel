#ifndef MYPROJECT_MOUSEEVENT_H
#define MYPROJECT_MOUSEEVENT_H

#include "Event.h"

#include <sstream>

namespace Hazel{

    //鼠标移动事件
    class MouseMovedEvent : public Event
    {
    public:
        MouseMovedEvent(float x, float y)
            : m_MouseX(x), m_MouseY(y) {}

        inline float GetX() const { return m_MouseX; }
        inline float GetY() const { return m_MouseY; }

        std::string ToString() const override
        {
            std::stringstream ss;
            ss << "MouseMovedEvent: " << m_MouseX << ", " << m_MouseY;
            return ss.str();
        }

        EVENT_CLASS_TYPE(MouseMoved)
        EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
    private:
        float m_MouseX, m_MouseY;
    };

    //鼠标滚动事件
    class MouseScrolledEvent : public Event
    {
    public:
        //为什么MouseMovedEvent和MouseScrolledEvent的构造函数都是public的
        MouseScrolledEvent(float xOffset, float yOffset)
                : m_XOffset(xOffset), m_YOffset(yOffset) {}

        inline float GetXOffset() const { return m_XOffset; }
        inline float GetYOffset() const { return m_YOffset; }

        std::string ToString() const override
        {
            std::stringstream ss;
            ss << "MouseScrolledEvent: " << m_XOffset << ", " << m_YOffset;
            return ss.str();
        }

        EVENT_CLASS_TYPE(MouseScrolled)
        EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
    private:
        float m_XOffset, m_YOffset;
    };

    class MouseButtonEvent : public Event
    {
    public:
        inline int GetMouseButton() const { return m_Button; }

        EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
    protected:
        //为什么构造函数是protected的? 是因为作为MouseButtonPressedEvent的基类
        MouseButtonEvent(int button)
            : m_Button(button) {}

            int m_Button;
    };

    class MouseButtonPressedEvent : public MouseButtonEvent
    {
    public:
        MouseButtonPressedEvent(int button)
            : MouseButtonEvent(button) {}

        std::string ToString() const
        {
            std::stringstream ss;
            ss << "MouseButtonPressedEvent: " << m_Button;
            return ss.str();
        }

        EVENT_CLASS_TYPE(MouseButtonPressed)
    };

    class MouseButtonReleasedEvent : public MouseButtonEvent
    {
    public:
        MouseButtonReleasedEvent(int button)
                : MouseButtonEvent(button) {}

        std::string ToString() const
        {
            std::stringstream ss;
            ss << "MouseButtonReleasedEvent: " << m_Button;
            return ss.str();
        }

        EVENT_CLASS_TYPE(MouseButtonReleased)
    };
}

#endif //MYPROJECT_MOUSEEVENT_H
