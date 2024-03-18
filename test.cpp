#include "Command.hpp"

int main(){
	Command command_class;

	std::string message;
	std::cin >> message;
	command_class.recCommand(1, message);
}