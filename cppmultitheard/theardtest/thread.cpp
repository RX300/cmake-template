#include<iostream>
#include<vector>
#include<thread>
#include<format>
#include<sstream>
static float cnt=0.0f;
std::mutex mtc;
void work(int i)
{
mtc.lock();
for(int i=0;i<10000;i++)
{
    cnt+=1.0f;
}
mtc.unlock();
std::thread::id tid = std::this_thread::get_id();    
std::stringstream sin;
sin<<tid;
std::cout<<std::format("thread {} do some work...args:{}",sin.str(),i)<<std::endl;
}
void thread_fun()
{
    std::cout << "sub thread begin,thread ID: " << std::this_thread::get_id() << std::endl;
    for (int i = 0; i < 10; i++) {
        std::cout << "i= " << i << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(1)); // 1000ms
    }
    std::cout << "sub thread is over,thread ID: " << std::this_thread::get_id() << std::endl;
}

int main()
{
    int thread_num=std::thread::hardware_concurrency();
    std::vector<std::thread>workers;
    for(int i=0;i<thread_num;i++)
    {
        workers.push_back(std::thread(work,i));
    }
        for(int i=0;i<thread_num;i++)
    {
       workers[i].join();
    }
    std::cout<<"cnt:"<<cnt<<std::endl;
    std::cout << "main thread begin,thread ID: " << std::this_thread::get_id() << std::endl;
    std::thread th(thread_fun);
    th.detach(); //子线程与主线程分离 守护线程,主线程退出后 子线程不一定退出

    std::cout << "main thread is over,thread ID: " << std::this_thread::get_id() << std::endl;

    
}