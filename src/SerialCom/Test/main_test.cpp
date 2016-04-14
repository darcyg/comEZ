/*
 * main_test.cpp
 *
 *  Created on: 05.03.2013
 *      Author: m1ch1
 */


#include <iostream>
#include <string>

#include "../SerialCom.h"




int main(int argc, char *argv[])
{
	if(argc != 2)
	{
		std::cout << "Syntax error: Using: \"./" << argv[0] << " [port] \n";
		exit(-1);
	}
	std::string argDev;
	argDev = argv[1];
	apps::SerialCom serialport(argDev);//,apps::B_9600,apps::F_8N1);

	std::cout << "try to connect: \n";
	serialport.connect();
	std::cout << "connected ... \n";

	usleep(5000000);

	unsigned char transmited = 0;
//   for(unsigned int i=0; i<200; ++i)
//   {
//
//      std::cout << "try to transmit: " << (int)transmited << "\n";
//      serialport.transmit(transmited);
//      std::cout << "transmited data: " << (int)transmited << std::endl;
//      usleep(5000);
//   }
	while(1)
	{
	   //for(unsigned int i=0; i<20; ++i)
      //{

	      std::cout << "try to transmit: " << (int)transmited << "\n";
		   serialport.transmit(transmited);
		   std::cout << "transmited data: " << (int)transmited << std::endl;
		   //usleep(10000);
      //}

		//sleep 1s
		//usleep(1000000);
		unsigned char received = 0;

		std::cout << "try to receive with timeout(500ms):" << std::endl;
		if(serialport.receive(received,500000) == apps::DeviceReceiveFail)
		{
			std::cout << "main: timed out after 500ms" << std::endl;
			received = 0;
		}
		else
		{
			std::cout << "received data: " << (int)received << std::endl;
		}


//		if(serialport.receive(received) == apps::DeviceSucces)
//		{
//			std::cout << "redeived data: " << (int)received << std::endl;
//		}
//		else
//		{
//			std::cout << "error at receive data with blocking mode" << std::endl;
//		}
//
//
//		if(transmited != received)
//		{
//			std::cout << "no match between send and received..." << std::endl;
//			//exit(-1);
//		}

		//sleep 1s
		usleep(50000);
		transmited++;

	}

	return 0;
}
