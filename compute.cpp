#include <iostream>
using namespace std;

class CPU
{
public:
    virtual void caculate() = 0;
};

class VideoCard
{
public:
    virtual void display() = 0;
};

class Memory
{
public:
    virtual void storage() = 0;
};

class Computer
{
public:
    Computer(CPU *cpu, VideoCard *vc, Memory *mem)
    {
        m_cpu = cpu;
        m_vc = vc;
        m_mem = mem;
    }

    void work()
    {
        m_cpu->caculate();
        m_vc->display();
        m_mem->storage();
    }

    ~Computer()
    {
        if(m_cpu != NULL)
        {
            delete m_cpu;
            m_cpu = NULL;
        }
        if(m_vc != NULL)
        {
            delete m_vc;
            m_vc = NULL;
        }
        if(m_mem != NULL)
        {
            delete m_mem;
            m_mem = NULL;
        }
    }

private:

    CPU *m_cpu;
    VideoCard *m_vc;
    Memory *m_mem;
};

class IntelCPU:public CPU
{
public:
    virtual void caculate()
    {
        cout << "IntelCPU" << endl;
    }
};

class LenovoCPU:public CPU
{
public:
    virtual void caculate()
    {
        cout << "LenovoCPU" << endl;
    }
};

class IntelVC:public VideoCard
{
public:
    virtual void display()
    {
        cout << "IntelVC" << endl;
    }
};

class IntelMEM:public Memory
{
public:
    virtual void storage()
    {
        cout << "IntelMEM" << endl;
    }
};

void test01()
{
    CPU * intelCpu = new IntelCPU;
    VideoCard * intelVc = new IntelVC;
    Memory * intelMem = new IntelMEM;

    Computer * computer1 = new Computer(intelCpu, intelVc, intelMem);
    computer1->work();
    delete computer1;
}

int main(int argc, char const *argv[])
{
    /* code */
    test01();
    system("pause");
    return 0;
}

