#ifndef APPLICATION_H_
#define APPLICATION_H_

class CommandLineArgsException
{

};

class Application
{
public:
        Application(const int argc, const char * argv[]);
        const double value() const;
        void * converter() const;
private:
        double m_value{0};
        char * m_firstType;
        char * m_secondType;
};

Application::Application(const int argc, const char * argv[])
{
        if (argc < 5) throw CommandLineArgsException();
        if (strcmp(argv[3], "to") != 0) throw CommandLineArgsException();

        m_value = std::strtod(argv[1], nullptr);

        m_firstType = new char[strlen(argv[2])];
        std::copy(argv[2], argv[2] + strlen(argv[2]), m_firstType);

        m_secondType = new char[strlen(argv[4])];
        std::copy(argv[4], argv[4] + strlen(argv[4]), m_secondType);
}

const double
Application::value() const
{
        return m_value;
}

void *
Application::converter() const
{
        if (strcmp(m_firstType, "invalid_type") == 0) return nullptr;
        if (strcmp(m_secondType, "invalid_type") == 0) return nullptr;
        return new int;
}

#endif
