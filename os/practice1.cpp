#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int curTime;

int getLastTime(int num1, int num2);

typedef struct job
{
    int id;
    int lastTime;
    int arriveSystemTime; // %100 可得分钟， /100 可得小时
    int arriveMemoryTime;
    int finishTime;
} job;

bool cmp(const job &a, const job &b)
{
    return a.arriveSystemTime < b.arriveSystemTime || (a.arriveSystemTime == b.arriveSystemTime && a.lastTime < b.lastTime);
}

bool cmpByLastTime(const job &a, const job &b)
{
    return a.lastTime < b.lastTime || (a.lastTime == b.lastTime && a.arriveSystemTime < b.arriveSystemTime);
}

bool hrnCmp(const job &a, const job &b)
{
    // 记得用类型强转，不然会变成 整型加减后 再根据变量类型转换赋值
    double r1 = 1 + (getLastTime(curTime, a.arriveSystemTime) * 1.0 / a.lastTime);
    double r2 = 1 + (getLastTime(curTime, b.arriveSystemTime) * 1.0 / b.lastTime);

    return r1 > r2 || (r1 == r2 && a.arriveSystemTime < b.arriveSystemTime);
}

int getLastTime(int num1, int num2)
{
    if (num1 > num2)
    {
        int tmp = num1;
        num1 = num2;
        num2 = tmp;
    }
    int h1, h2, m1, m2;
    h1 = num1 / 100;
    h2 = num2 / 100;
    m1 = num1 % 100;
    m2 = num2 % 100;

    return (h2 * 60 + m2 - h1 * 60 - m1);
}

class Solution
{
private:
    vector<job> jobs;

public:
    Solution()
    {
        ifstream read;
        read.open("data.txt", ios::in);
        if (!read.is_open())
        {
            cout << "Open file failed" << endl;
            return;
        }

        int id, lastTime, arriveSystemTime;
        while (!read.eof())
        {
            job newJob;
            read >> newJob.id >> newJob.arriveSystemTime >> newJob.lastTime;
            this->jobs.push_back(newJob);
        }
        read.close();
    }

    void FCFS()
    {
        cout << "FCFS调度算法：" << endl;
        sort(this->jobs.begin(), this->jobs.end(), cmp);
        int arriveMemoryTime, finishTime;
        arriveMemoryTime = this->jobs[0].arriveSystemTime;
        for (int i = 0; i < this->jobs.size(); i++)
        {
            this->jobs[i].arriveMemoryTime = arriveMemoryTime;
            this->jobs[i].finishTime = this->timeAdd(arriveMemoryTime, this->jobs[i].lastTime);
            arriveMemoryTime = this->jobs[i].finishTime;
        }

        this->show();
    }

    void SJF()
    {
        cout << "SJF调度算法：" << endl;
        // vector<job> inMemory;
        vector<job> inSystem;

        int total = this->jobs.size();
        sort(this->jobs.begin(), this->jobs.end(), cmp);

        // 已知最先到达的系统先进入，所以把排序后的第一个元素直接压入系统中
        // inSystem.push_back(this->jobs[0]);
        this->jobs[0].arriveMemoryTime = this->jobs[0].arriveSystemTime;
        int finishTime = this->timeAdd(this->jobs[0].arriveSystemTime, this->jobs[0].lastTime);
        this->jobs[0].finishTime = finishTime;
        // inSystem.pop_back();

        // 把主要信息更新完毕的在系统中排在最前列的元素压入内存
        // inMemory.push_back(this->jobs[0]);

        int arriveMemoryTime;
        int index = 1;
        int cur = 1;
        while (cur < total)
        {
            // 把在当前job任务全部压入
            while (index < total && this->jobs[index].arriveSystemTime <= finishTime)
            {
                inSystem.push_back(this->jobs[index]);
                index++;
            }

            sort(inSystem.begin(), inSystem.end(), cmpByLastTime);

            // inMemory.erase(inMemory.begin());

            inSystem[0].arriveMemoryTime = finishTime;
            finishTime = this->timeAdd(inSystem[0].arriveMemoryTime, inSystem[0].lastTime);
            inSystem[0].finishTime = finishTime;

            this->jobs[cur] = inSystem[0];
            cur++;

            if (inSystem.size() != 0)
            {
                // inMemory.push_back(inSystem[0]);
                inSystem.erase(inSystem.begin());
            }
        }

        this->show();
    }

    void HRN()
    {
        cout << "HRN调度算法：" << endl;
        vector<job> inSystem;

        int total = this->jobs.size();
        sort(this->jobs.begin(), this->jobs.end(), cmp);

        // 已知最先到达的系统先进入，所以把排序后的第一个元素直接压入系统中
        // inSystem.push_back(this->jobs[0]);
        this->jobs[0].arriveMemoryTime = this->jobs[0].arriveSystemTime;
        int finishTime = this->timeAdd(this->jobs[0].arriveSystemTime, this->jobs[0].lastTime);
        this->jobs[0].finishTime = finishTime;
        // inSystem.pop_back();

        // 把主要信息更新完毕的在系统中排在最前列的元素压入内存
        // inMemory.push_back(this->jobs[0]);

        int arriveMemoryTime;
        int index = 1;
        int cur = 1;
        while (cur < total)
        {
            // 把在当前job任务全部压入
            while (index < total && this->jobs[index].arriveSystemTime <= finishTime)
            {
                inSystem.push_back(this->jobs[index]);
                index++;
            }

            curTime = finishTime;
            sort(inSystem.begin(), inSystem.end(), hrnCmp);

            // inMemory.erase(inMemory.begin());

            inSystem[0].arriveMemoryTime = finishTime;
            finishTime = this->timeAdd(inSystem[0].arriveMemoryTime, inSystem[0].lastTime);
            inSystem[0].finishTime = finishTime;

            this->jobs[cur] = inSystem[0];
            cur++;

            if (inSystem.size() > 0)
            {
                // inMemory.push_back(inSystem[0]);
                inSystem.erase(inSystem.begin());
            }
        }

        this->show();
    }

    int timeAdd(int num1, int num2)
    {
        int h1, h2, m1, m2, c;
        h1 = num1 / 100;
        h2 = num2 / 100;
        m1 = num1 % 100;
        m2 = num2 % 100;

        c = (m1 + m2) / 60;

        return 100 * (h1 + h2 + c) + ((m1 + m2) % 60);
    }

    void show()
    {
        cout << "作业号  进入内存时间" << endl;
        for (int i = 0; i < this->jobs.size(); i++)
        {
            job cur = this->jobs[i];
            printf("%5d %12d\n", cur.id, cur.arriveMemoryTime);
        }
    }
};

int main()
{
    Solution s;
    s.FCFS();
    cout << endl;
    s.SJF();
    cout << endl;
    s.HRN();
}