#include <string>
#include <iostream>
#include "util.h"
#include <vector>
#include <sstream> // for std::stringstream
#include <functional>
#include <string_view>
#include <vector>

// #define NDEBUG // defined in makefile as cflags
// #include <assert.h>
#include <cassert>


class Base {
	public:
		Base() {}

		template <int times>
		void echo(std::string msg) {
			for (auto i = 0; i < times; i++)
				std::cout << msg << '\n';
		}

};


class Animal // This Animal is an abstract base class
{
	protected:
		std::string m_name;

	public:
		Animal(std::string name)
			: m_name(name)
		{
		}

		std::string getName() { return m_name; }
		virtual const char* speak() = 0; // note that speak is a pure virtual function
};

const char* Animal::speak()
{
	return "buzz"; // some default implementation
}

class Dragonfly: public Animal
{

	public:
		Dragonfly(std::string name)
			: Animal(name)
		{
		}

		virtual const char* speak() // this class is no longer abstract because we defined this function
		{
			return Animal::speak(); // use Animal's default implementation
		}
};


class A
{
	public:
		virtual std::string getName() const { return "A"; }
};

class B: public A
{
	public:
		virtual std::string getName() const { return "B"; }
};

class C: public B
{
	public:
		std::string getName() const { return "C"; }
};

class D: public C
{
	public:
		std::string getName() const { return "D"; }
};

typedef int (*comparator)(int,int);

int greater_than(int a, int b){
	return a > b;
}
comparator gt = greater_than;

template <typename T>
class Tmplt 
{
	public:
		T single;
		std::vector<T> multiple;
};

// A Functor
class increment
{
	private:
		int num;
	public:
		increment(int n) : num(n) {  }

		// This operator overloading enables calling
		// operator function () on objects of increment
		int operator () (int arr_num) const {
			return num + arr_num;
		}
};

void repeat(int repetitions, const std::function<void(int)> &fn)
{
	for (int i{ 0 }; i < repetitions; ++i)
	{
		fn(i);
	}
}

auto makeWalrus(const std::string& name)
{
	// Capture name by reference and return the lambda.
	return [&]() -> void {
		std::cout << "I am a walrus, my name is " << name << '\n'; // Undefined behavior
	};
}

class RunFn
{

	public:
		typedef void (*func_t)(void);
		func_t func;

		RunFn(func_t &fn): func(fn) {}

		void run() {
			this->func();
		}

};

void printShit (void)
{
	std::cout << "shit" << '\n';
}

int main(int argc, char *argv[]) {

	std::vector<int> abbas {1, 2, 3};

	const int &ref{5};

	int* p = (int* ) malloc(sizeof(int));
	fprintf(stderr, "Hello %s, score: %d", "Mahan", 100);
	fprintf(stdout, "Hello World");
	perror("errowr!");
	const char *nptr = "1A2436";
	const int &myInt{5};
	char* endptr;
	long int result = strtol(nptr, &endptr, 16);
	std::cout << result << std::endl;
	std::cout << ' ' << std::endl;
	std::cout << ' ' << std::endl;
	std::cout << times1(5) << std::endl;
	std::cout << times2(5) << std::endl;
	std::cout << gt(1, 2) << std::endl;

	std::cout << abbas.size() << std::endl;
	std::cout << abbas.capacity() << std::endl;

	std::vector<int> v = { 0, 1, 2, 3, 4 };
	std::cout << "size: " << v.size() << "  cap: " << v.capacity() << '\n';

	v.push_back(5); // add another element
	std::cout << "size: " << v.size() << "  cap: " << v.capacity() << '\n';

	// int arg1;
	// std::stringstream(argv[1]) >> arg1;

	// double arg2;
	// std::stringstream(argv[2]) >> arg2;

	// std::string arg3;
	// std::stringstream(argv[3]) >> arg3;

	// std::cout << arg1 * 5 << '\n';
	// std::cout << arg2 * 5 << '\n';
	// std::cout << arg3 << '\n';
	// std::cout << arg3 << '\n';


	auto inc = increment(5);
	std::cout << inc(10) << std::endl;

	repeat(3, [](int i) {
		std::cout << i << '\n';
	});

	auto sayName{ makeWalrus("Roofus") };
	sayName();

	D d{};
	A &a(d);
	std::cout << a.A::getName() << std::endl;

	Dragonfly dfly("Sally");
	Animal &an{dfly};
	std::cout << an.Animal::speak() << std::endl;
	std::cout << an.speak() << std::endl;

	Base base;
	base.echo<5>("greetings!");

	Tmplt<double> doubleTemplate;
	doubleTemplate.single = 5.5;
	doubleTemplate.multiple.push_back(1.0);
	doubleTemplate.multiple.push_back(2.0);
	std::cout << doubleTemplate.multiple[0] << '\n';
	std::cout << doubleTemplate.multiple[1] << '\n';

	RunFn::func_t fn = printShit;
	RunFn runFn(fn);
	runFn.run();

	assert(false && "assertion message");

}
