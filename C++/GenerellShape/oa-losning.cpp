// Assignment 3 - Open Assignment

#include "Graph.h"
#include "Simple_window.h" 

#include <sstream>
#include <string>
#include <vector>
#include <iostream>

void plot_points(vector<Graph_lib::Point> points) {
	Point tl{ 100, 100 };
	Simple_window win{ tl, 600, 400, "Canvas" };

	Open_polyline poly;
	poly.set_color(Color::red);

	for(auto point: points) {
		poly.add(point);
	}

	win.attach(poly);
	win.wait_for_button();
}

void extract_whitespace(std::istream &is) {
	while(!is.eof()) {
		char next;
		is >> next;
		if (next != ' ' && next != '\t' && next != '\r' && next != '\n') {
			is.putback(next);
			return;
		}
	}
	return;
}

vector<int> read_number_from_stream(std::istream& is) {
	vector<int> numbers;

	while(true) {
		extract_whitespace(is);
		// Read number
		int next_num;
		is >> next_num;

		if (is.fail()) {
			throw runtime_error("Failed to parse input. Expected a number.");
		} else {
			numbers.push_back(next_num);
		}

		// Now, a number should be followed by a comma and a new number, or end of file. 
		extract_whitespace(is); // To be on the safe side

		
		char next = '\0';
		is >> next;
		if (is.eof() || is.fail()) {
			// We've reached enf of file
			return numbers;
		}
		else if (next != ',') {
			throw runtime_error("Failed to parse input. Expected comma");
		}
	}
}

Point make_point(int x, int y){
	Point p;
	p.x = x;
	p.y = y;

	return p;
}

vector<Point> read_points_from_stream(std::istream &is) {
	// First read the list of numbers
	auto numbers = read_number_from_stream(is);

	// Check that is has even numbers
	if (numbers.size() % 2 != 0) {
		throw runtime_error("Incorrect number of points, should have been an even number");
	}

	vector<Point> points;
	// Otherwise, take every other number and make it a list of points
	for (int i = 0; i < numbers.size(); i += 2) {
		points.push_back(make_point(numbers[i], numbers[i+1]));
	}

	return points;
}

void read_and_plot_from_stream(std::istream &is) {
	try
	{
		auto points = read_points_from_stream(is);

		plot_points(points);
	}
	catch(const std::runtime_error& e)
	{
		std::cerr << "An error occured:\n";
		std::cerr << e.what() << '\n';
	}
}

void plot_from_file(){
	std::string file_name;
	std::cin >> file_name;

	auto file_stream = std::ifstream(file_name);
	if (!file_stream) {
		std::cerr << "The provided file could not be opened.";
		return;
	}

	read_and_plot_from_stream(file_stream);
}

void plot_from_console() {
	std::cout << "Enter points as integers separated by comma. Press enter when done.\nInput: ";

	// Clean cin
	std::cin.ignore();
	std::cin.clear();

	std::string input_line;
	std::getline(std::cin, input_line);
	// Convert it to a stream so we can reuse the code 
	auto input_line_stream = std::istringstream(input_line);

	read_and_plot_from_stream(input_line_stream);
}


int main() {
	using namespace Graph_lib;
	
	// Menu to prompt for file or console
	std::cout 	<< "Choose an option:\n"
				<< "1) Enter path to file containing points\n"
				<< "2) Enter points manually\n"
				<< "0) Exit\n"
				<< "";

	int selection = -1;
	do {
		std::cout << "Enter choice: ";
		std::cin >> selection;

		switch (selection)
		{
		case 0:
			exit(0);
			break;
		case 1:
			plot_from_file();
			break;
		case 2:
			plot_from_console();
			break;
		default:
			std::cout << "Invalid option.\n";
			// Clear input in case user entered text etc.
			std::cin.ignore();
			std::cin.clear();
			break;
		}
	} while(1);
}







