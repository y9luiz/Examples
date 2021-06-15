#include <iostream>
#include <vector>

using  namespace std;

#define INPUT_SIZE 100

int main()
{
   vector<int> vec(INPUT_SIZE);
   
   for(int i=0;i<INPUT_SIZE;i++)
   {
        vec[i] = i;
   }

   int sum = 0;
   
   for(int i=0;i<INPUT_SIZE;i++)
   {    
        sum += vec[i];
   }
   
   std::cout<<sum<<"\n";
   
   return 0;
}
