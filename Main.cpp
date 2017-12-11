/**
  * cmdline：系统启动时输入给内核命令行参数
  * cpuinfo：CPU的硬件信息 (型号, 家族, 缓存大小等)
  * devices：主设备号及设备组的列表，当前加载的各种设备（块设备/字符设备）
  * dma：使用的DMA通道
  * filesystems：当前内核支持的文件系统，当没有给 mount(1) 指明哪个文件系统的时候， mount(1) 就依靠该文件遍历不同的文件系统
  * interrupts ：中断的使用及触发次数，调试中断时很有用
  * ioports I/O：当前在用的已注册 I/O 端口范围
  * kcore：该伪文件以 core 文件格式给出了系统的物理内存映象(比较有用)，可以用 GDB 查探当前内核的任意数据结构。该文件的总长度是物理内存 (RAM) 的大小再加上 4KB
  * kmsg：可以用该文件取代系统调用 syslog(2) 来记录内核日志信息，对应dmesg命令
  * kallsym：内核符号表，该文件保存了内核输出的符号定义, modules(X)使用该文件动态地连接和捆绑可装载的模块
  * loadavg：负载均衡，平均负载数给出了在过去的 1、 5,、15 分钟里在运行队列里的任务数、总作业数以及正在运行的作业总数。
  * locks：内核锁 。
  * meminfo物理内存、交换空间等的信息，系统内存占用情况，对应df命令。
  * misc：杂项 。
  * modules：已经加载的模块列表，对应lsmod命令 。
  * mounts：已加载的文件系统的列表，对应mount命令，无参数。
  * partitions：系统识别的分区表 。
  * slabinfo：sla池信息。
  * stat：全面统计状态表，CPU内存的利用率等都是从这里提取数据。对应ps命令。
  * swaps：对换空间的利用情况。
  * version：指明了当前正在运行的内核版本。
  */
//本机环境 ：Linux version 4.13.0-19-generic (buildd@lcy01-amd64-021) (gcc version 7.2.0 (Ubuntu 7.2.0-8ubuntu3)) #22-Ubuntu SMP Mon Dec 4 11:58:07 UTC 2017
#include<bits/extc++.h>
using namespace std;

class MyClass {
    public:
        MyClass()=default;
        void GetOsInfo();
        void GetCpuInfo();
        void GetMemoryInfo();
    private:
        int data;

};
void MyClass::GetOsInfo(){
    FILE *fp = fopen("/proc/version", "r");
    if(NULL == fp)
        cout<<"failed to open version"<<endl;
    char szTest[1000] = {0};
    while(!feof(fp))
    {
        memset(szTest, 0, sizeof(szTest));
        fgets(szTest, sizeof(szTest) - 1, fp); // leave out \n
        cout<< szTest;
    }
    fclose(fp);
    fp = nullptr;
}
void MyClass::GetCpuInfo() {
    FILE *fp = fopen("/proc/cpuinfo", "r");
    if(NULL == fp)
        cout<<"failed to open cpuinfo"<<endl;
    char szTest[1000] = {0};
    // read file line by line
    while(!feof(fp))
    {
        memset(szTest, 0, sizeof(szTest));
        fgets(szTest, sizeof(szTest) - 1, fp); // leave out \n
        cout<<szTest;
    }
    fclose(fp);
    fp=nullptr;
}
void MyClass::GetMemoryInfo() {
    FILE *fp = fopen("/proc/meminfo", "r");
    if(NULL == fp)
        cout<<"failed to open meminfo"<<endl;
    char szTest[1000] = {0};
    while(!feof(fp))
    {
        memset(szTest, 0, sizeof(szTest));
        fgets(szTest, sizeof(szTest) - 1, fp);
        cout<<szTest;
    }
    fclose(fp);
    fp = nullptr;
}
int main()
{
    MyClass XX;
    //while(1)
    //{
        cout<<"===OsInfo==="<<endl;
        XX.GetOsInfo();
        cout<<"===CpuInfo==="<<endl;
        XX.GetCpuInfo();
        cout<<"===MemInfo==="<<endl;
        XX.GetMemoryInfo();
        //sleep(1);
    //}
    return 0;
}
