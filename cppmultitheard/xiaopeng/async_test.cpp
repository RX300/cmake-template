#include<iostream>
#include<string>
#include<thread>
#include<future>
#include<format>
int download(std::string file){
    std::cout<<"download thread id:"<<std::this_thread::get_id()<<std::endl;
    for(int i=0;i<10;i++){
        std::cout<<std::format("Downding ({}%)...",i*10)<<std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
    std::cout<<"Download complete:"<<file<<std::endl;
    return 404;
}

void interact(){
    std::string name;
    std::cin>>name;
    std::cout<<"Hi, "<<name<<std::endl;
}

int main(){
 std::cout<<"main thread id:"<<std::this_thread::get_id()<<std::endl;
    std::future<int>fret=std::async([&]{return download("hello.zip");});
    interact();
    int ret=fret.get();
    std::cout<<std::format("download result: {}",ret)<<std::endl;
    return 0;
}