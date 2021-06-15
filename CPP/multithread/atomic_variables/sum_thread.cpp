// In this example we are creating a code that sums all numbers
// between 0 and 9999999 using the CPP multithread API, to compile it
// certify that you have the pthread installed and that you are using 
// C++11 
#include <iostream>
#include <vector>
#include <thread>
#include <atomic> 

using  namespace std;

#define INPUT_SIZE 10000000
#define N_THREADS 4


// rvalue and lvalue
// basically rvalues doesn't point to anything
// and lvalues points for something
// in the function sumVec() the parameters vec and sum are lvalues
// while the others are rvalues
void sumVec(vector<int> & vec, int start,int end, atomic<long int> & sum)
{
    for(int i=start;i<end;i++)
    {   
        sum+=vec[i];
    }
}

int main()
{
   vector<int> vec(INPUT_SIZE);
   
   int batch_size = INPUT_SIZE/N_THREADS;

   for(int i=0;i<INPUT_SIZE;i++)
   {
        vec[i] = i;
   }
   //atomic variable only can be readed
   //and writed by one thread for time
   atomic<long int> sum (0);
   
   int start, end;
    
   vector<thread> vec_ths;

   for(int i=0;i<N_THREADS;i++)
   {    
        start = i*batch_size;
        end = start + batch_size;
        //the ref() function deal with rvalue conversion problems
        //in this case our function sumVec() expect that vec and sum
        //must be lvalues but std::thread() expect that all parameters
        //been rvalue and to deal with this problem we use the ref()
        //function
        vec_ths.push_back(thread(&sumVec,ref(vec),start,end,ref(sum)));
   }
   
   for(auto & th:vec_ths)
   {    
        //we use join here to make our main function wait for the
        //other threads finalize it tasks
        th.join(); 
   }

   std::cout<<sum<<"\n";
   
   return 0;
}
