//
// Created by user on 22.05.2022.
//

#include <exception>
#include <string>


namespace stack
{

struct EStackException
{
private:
std::string msg_;

public:

explicit EStackException(const std::string& msg)
{
    msg_ = msg;
}

~EStackException() = default;

std::string what() const
{
    return msg_;
}

};

struct EStackEmpty :public EStackException
{
public:
    EStackEmpty()
    : EStackException("stack is empty.")
    {}
    ~EStackEmpty() = default;
};

} // namespace stack