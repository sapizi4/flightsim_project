# flightsim_project


Flight Simulator is a C++ program that interpeters a file with commands to FlightGear program and executing them.
Creaters : Sapir Zilbershtein & Maor 

Installation
Clone the files from the project using the webpage or by typing:

 git clone https://github.com/Ron123456/FlightSimulator
compile the files in visproject2/mitkadem3 with:

 g++ -std=c++14 */*.cpp *.cpp -o a.out -pthread  
and execute the file with the path to the text file to be parsed as an argument:

./a.out fly.txt
Usage
There are many commands you can type in the text file: For example, to open a client that updates variables on port 5402 on localhost type in the text file:
connectControlClient("127.0.0.1",5402)
Other commands are Sleep,Print,fucntions,defining variables and etc.
