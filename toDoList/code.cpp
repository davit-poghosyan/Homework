#include <iostream>
#include <string>
#include <vector>
#include <chrono>
#include <thread>

class Task
{
private:
    std::string name;
    int time;
    bool isCompeted;
public:    
    Task() : name{""}, isCompeted{false} { duration();}
    Task(std::string n) : name{n},isCompeted{false} {duration();}
    Task(int t) : time{t}, isCompeted{false} {duration();}
    Task(std::string n, int t) : name{n}, time{t}, isCompeted{false}  {}
    Task(const Task&) = default;
    Task(Task&&) = default;
    Task& operator=(const Task&) = default;
    Task& operator=(Task&&) = default;
    
    void setName(std::string n)
    {
        name = n;
    }
   
    void setTime(int t)
    {
        time = t;
    }
    
    std::string getName() const
    {
        return name;
    }
    
    int getTime() const
    {
        return time;
    }
   
    bool getState() const
    {
        return isCompeted;
    }

    void completed()
    {
        isCompeted = true;
        if (!isCompeted) {
            name = name + " COMPLETED";
        }   
    }
   
    void duration()
    {
        std::this_thread::sleep_for(std::chrono::seconds(time));
        std::cout << "time to perform " << name << std::endl;
        completed();
    }
};

Task* create()
{
    std::cout << "insert name of task\n";
    std::cin.get();
    std::string name;
    std::getline(std::cin, name);
    
    std::cout << "insert seconds to remind about task\n";
    int time;
    std::cin >> time; 
    
    Task* newTask = new Task(name, time);
    
    std::thread myThread([newTask]() {
        newTask->duration();
    });
    myThread.detach();
   
    return newTask;
}

Task* change(Task* task)
{
    std::cout << "what do you want to do with task\n";
    std::cout << "1. change name\n";
    std::cout << "2. change state\n";
    std::cout << "3. if you want to return insert RET\n";
  
    std::string changing;
    std::cin >> changing;
    if (changing == "1") {
        std::cout << "insert new name\n";
        std::cin.get();
        std::string name;
        std::getline(std::cin, name);
        task->setName(name);
    }
    else if (changing == "2") {
        task->completed();
    }
    else if (changing == "RET") {
        return task;
    }
  
    return task;
}

void myTasks(std::vector<Task*> tasks)
{
    std::cout << "which tasks do you want\n";
    std::cout << "1. all\n";
    std::cout << "2. comleted\n";
    std::cout << "3. non-completed\n";
    std::cout << "4. if you want to return insert RET\n";
   
    std::string buff;
    std::cin.get();
    std::getline(std::cin, buff);
   
    int size = tasks.size();
    
    if (buff == "1") {
        for (int i = 0; i < size; ++i) {
            std::cout << tasks[i]->getName() << std::endl;
        }
    }
    else if (buff == "2") {
        for (int i = 0; i < size; ++i) {
            if (tasks[i]->getState()) {
                std::cout << tasks[i]->getName() << std::endl;
            }
        }
    }
    else if (buff == "3") {
        for (int i = 0; i < size; ++i) {
            if (!tasks[i]->getState()) {
                std::cout << tasks[i]->getName() << std::endl;
            }
        }
    }
    else if (buff == "4") {
        return;
    }
}

int main()
{
    std::vector<Task*> task;
    int size = 0;
    std::cout << "if you want to exit insert EXIT\n";
    std::string str = "EXIT";
    do {
        std::cout << "what option do you want\n";
        std::cout << "1. create task\n";
        std::cout << "2. change task\n";       
        std::cout << "3. delete task\n";
        std::cout << "4. my tasks\n";
       
        std::cin >> str;
        
        if (str == "1") {
            task.push_back(create());
            ++size;
        } 
        else if (str == "2") {
            if (size == 0) {
                std::cout << "task is empty\n";
            }
            else {
                std::cout << "Insert name of task that you want to change\n";
                std::string buff;
                std::cin.get();
                std::getline(std::cin, buff);
                Task* tmp = new Task(buff);
                
                int i = 0;
                for (i; i < size; ++i) {
                    if (tmp->getName() == task[i]->getName())
                    {
                        task[i] = change(task[i]);
                        break;
                    }
                    else if (i == size - 1) {
                        std::cout << "task is missing\n";
                    }
                }
            }

        }
        else if (str == "3") {

            if (size == 0) {
                std::cout << "task is empty\n";
            }  

            else 
            {
                std::cout << "Insert name of task that you want to delete\n";
                std::string buff;
                std::cin.get();
                std::getline(std::cin, buff);
                Task* tmp = new Task(buff);
                
                int i = 0;
                for (i; i < size; ++i) {
                    if (tmp->getName() == task[i]->getName())
                    {
                        auto it = task.begin();
                        int j = 0;
                        while (j != i) {
                            ++it;
                        }
                        task.erase(it);
                        break;
                    }
                    else if (i == size - 1) {
                        std::cout << "task is missing\n";
                    }
                }
            }
        }
        else if (str == "4") {
             if (size == 0) {
                std::cout << "task is empty\n";
            }
            else {
                std::cout << "your tasks are\n";
                for (int i = 0; i < size; ++i) {
                    std::cout << task[i]->getName() << std::endl;

                }

            }
        }
    } while(str != "EXIT");
}

