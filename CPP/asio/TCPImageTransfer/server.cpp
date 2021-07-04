
#include <iostream>
#include <string>
#include <asio.hpp>
#include <fstream>

using asio::ip::tcp;
using std::cout;
using std::ofstream;
int main()
{
    try
    {
      asio::io_context io_context;

      tcp::acceptor acceptor(io_context,tcp::endpoint(tcp::v4(),5000));

      tcp::socket socket(io_context);

      std::cout<<"aguardando conexões\n";

      acceptor.accept(socket);

      std::array<char,14216> buffer;

      socket.read_some(asio::buffer(buffer));

      ofstream file("minha_pizza.jpeg",std::ofstream::binary);

      file.write(buffer.data(),buffer.size());
      

    }
    catch (std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}
