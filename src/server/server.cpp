#include <iostream>
#include <boost/program_options.hpp>
#include <boost/asio.hpp>

#include <ndn-cxx/name.hpp>
#include <ndn-cxx/face.hpp>
#include <ndn-cxx/util/io.hpp>

#include "ndn_producer.hpp"
#include "ndn_capture.hpp"

void usage(const boost::program_options::options_description &options){
    std::cout << "Usage: sudo build/server [options] <prefix> \n";
    std::cout << options;
    exit(0); //参数0表示正常退出
}

int main(int argc, char* argv[]){
    boost::asio::io_service io;
    ndn::Face face(io);
    ndn::KeyChain keyChain; //提供了一个接口用来管理与包签名有关的实体，比如Identity, Key, and Certificates

    Producer producer(face, keyChain);
    
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
        producer.setPrefix(optVm["prefix"].as<std::string>());
    }
    producer.start();
    return 0;
}
