#ifndef APPLICATION_H_
#define APPLICATION_H_

#include <string>

class CommandLineArgsException
{

};

class Application
{
public:
        Application(const int argc, const char * argv[]);
        const double value() const;
        std::string firstType() const;
        std::string secondType() const;
private:
        double m_value{0};
        std::string m_firstType;
        std::string m_secondType;
};

Application::Application(const int argc, const char * argv[])
{
        if (argc < 5) throw CommandLineArgsException();
        if (strcmp(argv[3], "to") != 0) throw CommandLineArgsException();

        m_value = std::strtod(argv[1], nullptr);
        m_firstType = std::string(argv[2]);
        m_secondType = std::string(argv[4]);
}

const double
Application::value() const
{
        return m_value;
}

std::string
Application::firstType() const
{
        return m_firstType;
}

std::string
Application::secondType() const
{
        return m_secondType;
}

#endif
