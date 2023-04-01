#include <iostream>

/**
 * \brief
 *	the following is function object
 *	func obj = function with state
 */
struct Free
{
	void operator()(int* p)
	{
		free(p);
		std::cout << "ptr freed\n";
	}
};

void MallocFree(int* p)
{
	free(p);
	std::cout << "malloc freed\n";
}
void UniquePointer()
{
	//std::unique_ptr<int>p{(int*) malloc(4)}; // though this works fine, can't guarantee this will work all time because the dynamic pointer is created using malloc so free shoulbe be called, but instead unique ptr will call delete that may cause error, so need to create user defined deleter that unique pr can call that will invoke free instead of delete
	std::unique_ptr<int, Free>up1{(int*)malloc(4), Free{}};
	std::unique_ptr<int, void(*)(int*)>up2{(int*)malloc(4), MallocFree};//mallocfree = type to pass == address of function
	 //void(*)(int *) = type of function pointer
}

void SharedPointer()
{
	std::shared_ptr<int>sp1{(int*)malloc(4), Free{}};
	std::shared_ptr<int>sp2{(int*)malloc(4), MallocFree};//
}
//!!! though we create ptr using function on second, funtion deleter is called 1st instead of function object
int main()
{
	UniquePointer();
	SharedPointer();
	
}