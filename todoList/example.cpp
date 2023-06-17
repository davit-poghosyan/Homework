/*#include <iostream>
#include <chrono>
#include <thread>

class MyObject
{
public:
    void setState(int newState)
    {
        state = newState;
        std::cout << "State changed to: " << state << std::endl;
    }

    int getState() const
    {
        return state;
    }

private:
    int state = 0;
};

void changeStateAfterDelay(MyObject& obj, int newState, int delaySeconds)
{
    std::this_thread::sleep_for(std::chrono::seconds(delaySeconds));
    obj.setState(newState);
    std::cout << obj.getState();
}

int main()
{
    MyObject obj, obj1, obj2, obj3;

    std::thread stateChangeThread(changeStateAfterDelay, std::ref(obj), 1, 2);
    std::thread stateChangeThread1(changeStateAfterDelay, std::ref(obj1), 4, 3);
    std::thread stateChangeThread2(changeStateAfterDelay, std::ref(obj2), 14, 4);
    std::thread stateChangeThread3(changeStateAfterDelay, std::ref(obj3), 12, 5);


    stateChangeThread.join();
    stateChangeThread1.join();
    stateChangeThread2.join();
    stateChangeThread3.join();


    return 0;
}*/
#include <iostream>
#include <chrono>
#include <thread>

class MyObject
{
public:
    void changeStateAfterDelay(int newState, int delaySeconds)
    {
        std::this_thread::sleep_for(std::chrono::seconds(delaySeconds));
        setState(newState);
    }

    void setState(int newState)
    {
        state = newState;
        std::cout << "State changed to: " << state << std::endl;
    }
    int getState() const
    {
        return state;
    }
private:
    int state = 0;
};

int main()
{
    MyObject obj;

    std::cout << "Initial state: " << obj.getState() << std::endl;

    int newState = 1;
    int delaySeconds = 5;

    std::thread stateChangeThread(&MyObject::changeStateAfterDelay, &obj, newState, delaySeconds);

    // Continue running other tasks
    for (int i = 0; i < 10; i++)
    {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        std::cout << "Main thread executing..." << std::endl;
    }

    stateChangeThread.join();

    std::cout << "Final state: " << obj.getState() << std::endl;

    return 0;
}

