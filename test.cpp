#include "Graph.h"
#include "GUI.h"
#include "Window.h"
#include "Simple_window.h" 
#include "string.h"
using namespace Graph_lib;
void cb_draw_rect(Address, Address pw)/*pw指向当前窗口*/ {

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
	Graph_lib::Button draw_rect(Point(0, 0), 70, 20, "draw_rect", cb_draw_rect);
	win.attach(draw_rect);
	//Graph_lib::Menu command(Point(0, 0), 70, 20, Graph_lib::Menu::vertical, "command");
	//Graph_lib::Button command1(Point(0, 0), 20, 5, "command1", cb1);
	//Graph_lib::Button command2(Point(0, 0), 20, 5, "command2", cb2);
	//Graph_lib::Button command3(Point(0, 0), 20, 5, "command3", cb3);
	//command.attach(command1);
	//command.attach(command2);
	//command.attach(command3);
	//win.attach(command);
	//Graph_lib::Out_box out(Point(200, 200), 100, 100, "begin");
	//win.attach(out);
	win.wait_for_button();
}
catch (const std::exception&)
{
	return 1;
}
//#include <FL/Fl.H>
//#include <FL/Fl_Double_Window.H>
//#include <FL/Fl_Button.H>
//#include <FL/Fl_Box.H>
//
//void button1_cb(Fl_Widget* w, void* p) {
//    Fl_Button* o1 = (Fl_Button*)w;
//    o1->value(o1->value() ? 0 : 1);
//    w->label(o1->value() ? "button1=1" : "button1=0");
//    Fl_Box* o2 = (Fl_Box*)p;
//    o2->label("1 pressed");
//}
//void button2_cb(Fl_Widget* w, void* p) {
//    Fl_Button* o1 = (Fl_Button*)w;
//    o1->value(o1->value() ? 0 : 1);
//    w->label(o1->value() ? "button2=1" : "button2=1");
//    Fl_Box* o2 = (Fl_Box*)p;
//    o2->label("2 pressed");
//}
//void quit_cb(Fl_Widget* w, void* p) {
//    exit(0);
//}
//
//int main() {
//    Fl_Double_Window window(390, 180, "callback");
//    Fl_Box* pBox = new Fl_Box(50, 50, 290, 50, "no button pressed");
//    Fl_Button* pButton1 = new Fl_Button(50, 120, 100, 30, "button1");
//    Fl_Button* pButton2 = new Fl_Button(170, 120, 100, 30, "button2");
//    Fl_Button* pQuitButton = new Fl_Button(290, 120, 50, 30, "quit");
//
//    pButton1->callback(button1_cb, (void*)pBox);
//    pButton2->callback(button2_cb, (void*)pBox);
//    pQuitButton->callback(quit_cb, nullptr);
//
//    window.end();
//    window.show();
//    return Fl::run();
//}