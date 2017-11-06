#include <iostream>
#include <thread>
#include <string>

void T1Function(int one, float two, std::string const & three)
{
	std::cout << "T1 says " << one << " " << two << " " << three << std::endl;
}
	
void T2Function(int one, std::string const & s, int two)
{
	std::cout << "T2 says " << one << " " << s << " " << two << std::endl;
}

class ThreadClass
{
private:
	int classData;
public:
	ThreadClass(int cd):classData(cd){}
	static void StaticThreadFunction(int one, int two);
	void ThreadFunction (int one, int two, int three);
};

int main()
{
	// Make a thread and let it run
	std::thread t1(T1Function,5,1.0,"hello");
	// Wait for it to die
	t1.join();
	
	// Make a different kind of thread and let it run
	std::thread t2(T2Function,4,"world",5);
	t2.join();
	
	// Make a thread using a class member and let it run
	std::thread t3(&ThreadClass::StaticThreadFunction,1,2);
	t3.join();

	// Make a thread using a class member and let it run
	ThreadClass tc(9);
	std::thread t4(&ThreadClass::ThreadFunction,&tc,1,2,3);
	t4.join();

}

void ThreadClass::ThreadFunction(int one, int two, int three)
{
	std::cout << "TC:TF says " << one << " " << two << " " << three <<" " << classData << std::endl;
}

void ThreadClass::StaticThreadFunction(int one, int two)
{
	std::cout << "TC:SCF says " << one << " " << two << std::endl;
}