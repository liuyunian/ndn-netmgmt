#include <iostream>
#include <boost/program_options.hpp>

#include "ndn_server.h"

void usage(const boost::program_options::options_description &options){
    std::cout << "Usage: sudo build/server [options] <prefix> \n";
    std::cout << options;
    exit(0); //参数0表示正常退出
}

int main(int argc, char* argv[]){
    std::string prefix("/localhost");

    namespace po = boost::program_options;
    
    po::options_description visibleOptDesc("Allowed options");
    visibleOptDesc.add_options()("help,h", "print this message and exit")
                                ("prefix,p", po::value<std::string>(), "root prefix");

    po::variables_map optVm;    
    store(parse_command_line(argc, argv, visibleOptDesc), optVm);

    if(optVm.count("help")){
        usage(visibleOptDesc);
    }
    
    if(optVm.count("prefix")){
        prefix = optVm["prefix"].as<std::string>();
    }
    
    Server server(prefix.append("/ndnmgmt"));
    server.run();
    // Capture cap;
    // cap.run();

    return 0;
}
