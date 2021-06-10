#include <iostream>
#include <cstring>

using namespace std;

/**
 *  This code is a just a example code
 *  of how you propertily use the reference
 *  operator in C++
 */

class Buffer
{
    public:
          Buffer(const char * data)
          {
            std::cout<<"construiu\n";
            size = strlen(data);
            this->data = new char [size];
            memcpy(this->data,data,size);
          }
          Buffer(Buffer & old)
          {
            std::cout<<"construiu pela copia\n";
            size = old.size;
            data = new char[size];
            memcpy(data,old.data,size);
          }
          Buffer(Buffer && old)
          {
            std::cout<<"move assignment\n";
            data = old.data;
            size = old.size;
            
            old.data = NULL;
            old.size = 0;

          }
          ~Buffer()
          {
              std::cout<<"destruiu\n";
              delete data;
          }
          char * data;
          int size;

};
void printBuffer(Buffer& b)
{
    if(b.data != NULL)
        std::cout<<b.data<<"\n";
}

int main()
{
   Buffer test("Hello world");
   Buffer x = test;  
   printBuffer(test);
   //printBuffer(x);
   return 0;
}
