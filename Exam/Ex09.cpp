#include <iostream>
#include <vector>
#include <string>

struct Object
{
    virtual std::string print(const std::string &znak) const = 0;
};

struct ConsoleObject: public Object
{
    std::string print(const std::string &znak) const override
    {
        return type() + znak;
    }
    virtual std::string type() const = 0;
};

struct ConsoleLine: public ConsoleObject
{
    std::string type() const { return "ConsoleLine"; }
};

struct ConsoleText: public ConsoleObject
{
    std::string type() const { return "ConsoleText"; }
};

struct GuiObject: public Object
{
    std::string print(const std::string &znak) const override
    {
        return type() + znak;
    }
    virtual std::string type() const = 0;
};

struct GuiLine: public GuiObject
{
    std::string type() const { return "GuiLine"; }
};

struct GuiText: public GuiObject
{
    std::string type() const { return "GuiText"; }
};



using namespace std;

int main()
{
    std::vector<Object*> objs;
    ConsoleObject * console0 = new ConsoleLine();
    ConsoleObject * console1 = new ConsoleText();
    GuiObject* gui0 = new GuiLine();
    GuiObject* gui1 = new GuiText();

    objs.push_back(console0); objs.push_back(console1);
    objs.push_back(gui0); objs.push_back(gui1);

    for(unsigned i = 0; i != objs.size(); i++)
        cout << objs[i] -> print(",");
}