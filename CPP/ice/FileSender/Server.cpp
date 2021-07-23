// ImageSender.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <Ice/Ice.h>
#include <sender.h>
#include <fstream>
#include <filesystem> //need c++17

using namespace std;
namespace fs = std::filesystem;

// configure this parameter according with your operational system separator
// In my case, i use \\ for windows
#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
static const char separator = '\\';
#else
static const std::string separator = "/";
#endif

class SenderI : public Demo::Sender
{
    public:
        virtual void sendFile(  Demo::File file, const ::Ice::Current& current) override;
};

vector<string> splitString(const string & input_string,const char & separator)
{
    vector<string> strings;

    istringstream f(input_string);

    string s;


    while (getline(f, s, separator))
    {
        strings.push_back(s);
    }

    return strings;
}   

void SenderI::sendFile(Demo::File file, const ::Ice::Current& current)
{
    const std::string filename = splitString(file.filename, separator).back();

    const std::string new_path = ".\\files\\" + filename;

    std::ofstream out_file(new_path, std::ofstream::binary);
    if (out_file.is_open())
    {
        out_file.write(reinterpret_cast<char*>(file.data.data()), file.data.size());
        cout << "image saved with name " << new_path << endl;

    }
    else {
        throw std::invalid_argument("could not open the file " + new_path);
    }
}

int main(int argc, char ** argv)
{
    if (argc != 2)
    {
        cout << "usage ./ImageSender <filename>\n";
        return -1;
    }

    try
    {
        const string file_folder = "files";
        if (!fs::exists(file_folder))
        {
            fs::create_directory(file_folder);
        }

        Ice::CommunicatorHolder ich(argc, argv);
        // create adapter passing the endingpoint point to be localhost and port 10000
        auto adapter = ich->createObjectAdapterWithEndpoints("ImageSender", "default -p 10000");
        // create an instance of SenderI and store it in an shared_ptr
        // The servant will be a Ice Object Pointer
        auto servant = make_shared<SenderI>();
        // wrap the ice objet into the adapter and put an identity 
        adapter->add(servant, Ice::stringToIdentity("ImageSender"));
        adapter->activate();
        ich->waitForShutdown();
    }
    catch (const std::exception& e)
    {
        cerr << e.what() << endl;
        return 1;
    }

   

    return 0;
}
