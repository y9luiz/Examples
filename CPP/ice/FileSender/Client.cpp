// Client.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <sender.h>
#include <Ice/Ice.h>
#include <string>
#include <fstream>


using namespace std;

int main(int argc, char **argv)
{
	try {

        if (argc != 2)
        {
            cout << "usage ./client <filename>\n";
            return -1;
        }

        Ice::CommunicatorHolder ich(argc, argv);
        // open a proxy to handle with the ice object
        auto base = ich->stringToProxy("ImageSender:default -p 10000");
        auto sender = Ice::checkedCast<Demo::SenderPrx>(base); // instanciate a proxy to handle with the Sender Ice Object
        // a proxy works quite similar as a pointer
        if (!sender)
        {
            throw std::runtime_error("Invalid proxy");
        }

        const std::string filename = argv[1];
        // open a file that will be sended over stream

        ifstream in_file(filename, std::ofstream::binary);
        if (!in_file.is_open())
        {
            throw std::invalid_argument("could not open the file " + filename);
        }
        auto getFileSize = [](std::ifstream& file)
        {
            file.seekg(0, ios::end);
            const auto end = file.tellg();
            const auto fsize = end;
            file.seekg(0);
            return fsize;
        };

        // calculate the file size
        int input_f_size = getFileSize(in_file);

        // create a buffer with the same size of the file
        std::vector<Ice::Byte> file_buffer(input_f_size); // Ice::byte is unsigned char 

        // cast unsigned char * to char* before read the file
        in_file.read(reinterpret_cast<char*>(file_buffer.data()), file_buffer.size());

        // Use the File struct defined inside the slice file
        Demo::File file;
        file.filename = filename;
        file.data = file_buffer;

        // send over the network it
        sender->sendFile(file);

        cout << "File sended\n";

	}
    catch (const std::exception& e)
    {
        cerr << e.what() << endl;
        return 1;
    }
    return 0;

}
