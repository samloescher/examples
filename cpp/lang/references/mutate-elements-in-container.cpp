// https://stackoverflow.com/questions/48289807/how-do-i-mutate-elements-in-a-container-in-a-loop/48290032

#include <list>
#include <iostream>

class Obj
{
public:
	void increase() { count++; }
	void printCount() { std::cout << count << '\n'; }
private:
	int count = 0;
};

int main()
{
	{
		std::list<Obj> passByValueObjs;
		Obj obj;
		passByValueObjs.push_back(obj);

		for (Obj obj : passByValueObjs)
		{
			obj.increase();
		}

		for (Obj obj : passByValueObjs)
		{
			obj.printCount();
		}
	}
	{
		std::list<Obj> passByReferenceObjs;
		Obj obj;
		passByReferenceObjs.push_back(obj);

		for (Obj &obj : passByReferenceObjs)
		{
			obj.increase();
		}

		for (Obj obj : passByReferenceObjs)
		{
			obj.printCount();
		}
	}

    return 0;
}
