
#include <iostream>
#include <string>
#include <asio.hpp>
#include <fstream>

using std::cout;
using std::ifstream;
using asio::ip::tcp;

int main()
{
    try
    {
       asio::io_context io_context;
       
       tcp::endpoint endpoint(asio::ip::make_address("192.168.1.64"),5000);

       tcp::socket socket(io_context);

       socket.connect(endpoint);

       std::array<char,14216> buffer;

       ifstream file("../pizza.jpeg",std::ifstream::binary);

       file.read(buffer.data(),buffer.size());

       socket.write_some(asio::buffer(buffer));

    }
    catch (std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
  
    return 0;
}