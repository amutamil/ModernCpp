#include <iostream>
#include <vector>
#include<random>

using namespace std;

/*
 * STACK UNWINDING -
 * when exception thrown all local objects will get deleted called stack unwinding
 * but it won't release the heap memory acquired
 * So we have to use smart pointers instead of raw pointers for objects and vectors for dynamic arrays
 */
class test
{
public:
   test() { cout << "test" << endl; };
   ~test() { cout << "~test" << endl; };
};
int ProcessRecords(int count)
{
   unique_ptr<test> t(new test);//test *t = new test();
	
   vector<int> arr; //int* arr = (int*)malloc(count * sizeof(int));
   arr.reserve(count); //reserve throws bad alloc if memory is not allocated
   vector<int> ptr;//int* ptr = new int[count];
   ptr.reserve(count);;
   if (count < 10)
   {
      throw(out_of_range("out of range"));
   }
   //processing the records
   for (int i = 0; i < count; i++)
   {
      arr.push_back(i);
   }
    //nested exception
   default_random_engine eng;
   bernoulli_distribution dist;
   int errors{};
    for(int i=0;i<count;++i)
    {
	    try
	    {
          cout << "Processing recond # : " << i << " ";
            if(!dist(eng))
            {
               ++errors;
               throw runtime_error("could not process the record");
            }
	    	cout << endl;
	    }
        catch (runtime_error &ex)
        {
           cout << "[ERROR " << ex.what() << "]" << endl;
            if(errors>4)
            {
               runtime_error err("too many failure. abondaning");
               ex = err; // modifying the original exception object, it can be done when exception object passes by ref.
               throw; // throws out of func. and catched in main.
            }
        }
    }
   /*int* arr = (int*)malloc(count * sizeof(int));
   int* ptr = new int[count];//return bad alloc exeception
   if (count < 10)
   {
      throw(out_of_range("out of range"));
   }
    if(arr == nullptr)
    {
	    throw(runtime_error("can't allocate mem"));
    }
    for(int i = 0;i<count;i++)
    {
       //arr[i] = i;
    }
    free(arr);
    delete[] ptr;*/
    return 0;
}
int main()
{
   try{
      //ProcessRecords(numeric_limits<int>::max());
      ProcessRecords(10);
   }
    catch (runtime_error &ex)
    {
       cout << ex.what() << endl;
    }
    catch (out_of_range &ex)
    {
       cout << ex.what() << endl;
    }
    catch (bad_alloc &ex)
    {
       cout << ex.what() << endl;
    }
    catch (exception &ex)
    {
       cout << ex.what() << endl;
        //from this base only all exceptions inherited
        //so this can catch all exception objects
    }
    catch (...)
    {
        // this also can be used universaly but it pass no clues
       cout << "exception";
    }
    return 0;
}