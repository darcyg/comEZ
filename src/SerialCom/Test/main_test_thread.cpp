/*
 * main_test.cpp
 *
 *  Created on: 05.03.2013
 *      Author: m1ch1
 */


#include <iostream>
#include <string>
#include <memory>

//#include <boost/thread.hpp>
#include <thread>

#include "../SerialCom.h"



class Main
{
public:
   Main(std::string port)
   {
      std::cout << "init Main" << std::endl;
      _port = std::unique_ptr<apps::SerialCom>(new apps::SerialCom(port));
      //_readThread = boost::bind(&Main::read, this);
      std::cout << "after com" << std::endl;
      _cnt = 0;
   }
   ~Main()
   {

   }

   void run()
   {
      std::cout << "connect" << std::endl;
      _port->connect();
      usleep(2000000);
      std::cout << "connected" << std::endl;
      _readThread = std::thread(&Main::read, this);

      while(1)
      {
         std::string in;
         std::cout << "transmitt data:" << std::endl;
         //std::cin >> in;

         _port->transmit(_cnt);
         std::cout << "transmitted data: " << (int)_cnt++ << std::endl;

         usleep(200000);
      }
   }

private:

   void read()
   {
      while(1)
      {
         std::cout << "-- read data: " << std::endl;
         unsigned char data;
         _port->receive(data);
         std::cout << "received data: "<< (int)data << std::endl;
         //usleep(1000000);
      }
   }


private:
   //boost::thread _readThread;
   std::thread _readThread;
   std::unique_ptr<apps::SerialCom> _port;
   unsigned char _cnt;
};

int main(int argc, char *argv[])
{
	if(argc != 2)
	{
		std::cout << "Syntax error: Using: " << argv[0] << " [port] \n";
		exit(-1);
	}
	std::string argDev;
	argDev = argv[1];

	Main main(argDev);

	main.run();



	return 0;
}
