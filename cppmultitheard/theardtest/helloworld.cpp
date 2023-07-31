
#include <iostream>
#include <string>
#include <thread>
#include <vector>
void hello(int i=0)
{
    std::cout << "Hello World! Thread"<<i<<"\n";
}

void f(int i, std::string const& s)
{
    std::cout << i << "  " << s << std::endl;
}

void upadata_data(int& data )
{
    data+=100;
}
void oops(int p)
{
    char buffer[1024];
    sprintf(buffer, "%i", p);
    std::thread t(f, 3, std::string(buffer));
    t.detach();
}

int oops_again(int Data)
{
    int data = Data;
    std::thread t(upadata_data, std::ref(data));
    t.join();
    return data;
}
class background_task
{
public:
    void operator()() const
    {
        hello();
    }
};
int main()
{
    std::cout<<oops_again(1);
    
}