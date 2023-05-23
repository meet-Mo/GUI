//#include <iostream>
//using namespace std;
//int main() {
//	int a = 0xffffff63;
//	int* pa = &a;
//	void* v = pa;
//	cout << pa << "\t" << v <<"\t"<< * pa <<"\t"<< * (char*)v;
//}
#include "Graph.h"
#include "GUI.h"
#include "Window.h"
#include "Simple_window.h" 
using namespace Graph_lib;
void cb_draw_rect(Address, Address pw) {

}
void cb1(Address, Address pw) {

}
void cb2(Address, Address pw) {

}
void cb3(Address, Address pw) {

}
int main() 
try
{
	Simple_window win(Point(200, 200), 600, 400, "test window");
	//Graph_lib::Rectangle rect1(Point(0, 0), Point(100, 100));
	//win.attach(rect1);
	//Graph_lib::Button draw_rect(Point(0, 0), 70, 20, "draw_rect", cb_draw_rect);
	//win.attach(draw_rect);
	Graph_lib::Menu command(Point(0, 0), 70, 20, Graph_lib::Menu::vertical, "command");
	Graph_lib::Button command1(Point(0, 0), 20, 5, "command1", cb1);
	Graph_lib::Button command2(Point(0, 0), 20, 5, "command2", cb2);
	Graph_lib::Button command3(Point(0, 0), 20, 5, "command3", cb3);
	command.attach(command1);
	command.attach(command2);
	command.attach(command3);
	win.attach(command);
	win.wait_for_button();
}
catch (const std::exception&)
{
	return 1;
}