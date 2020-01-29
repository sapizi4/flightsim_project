# flightsim_project


Flight Simulator is a C++ program that interpeters a file with commands to FlightGear program and executing them.
Creaters : Sapir Zilbershtein & Maor Bokobza

Intrudoction:
The goal is creating a program that controls the Flight Simulator using a set of commands that will be interpreted and sent to the simulator server. This project is a showcase to our programming experience. It contains: Client-Server communication programming, design pattern, data streaming and parallel programming using Threads.


Instructions for running the simulator:
Download FlightGear Simulator.
In the main menu of FlightGear, access the settings and add the following settings in "Additional ‫‪‬‬ ‫‪Settings‬":
--generic=socket,out,10,127.0.0.1,5400,tcp,generic_small
--telnet=socket,in,10,127.0.0.1,5402,tcp --httpd=8080
Open the linux terminal and compile the program:
g++ -std=c++14 *.cpp -Wall -Wextra -Wshadow -Wnon-virtual-dtor -pedantic -o a.out -pthread
Put your input text file at the same folder with your .cpp files and run the program with the following command (in the linux terminal):
./a.out file_name.txt
Press "Fly!" on FlightGear simulator.
