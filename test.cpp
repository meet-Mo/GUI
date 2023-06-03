#include "Graph.h"
#include "GUI.h"
#include "Window.h"
#include "Simple_window.h"
#include "string.h"
using namespace Graph_lib;
void cb_draw_rect(Address, Address pw) {
	
	Graph_lib::Rectangle* rect1= new Graph_lib:: Rectangle(Point(100, 100), Point(120, 150));
	rect1->set_fill_color(Color::yellow);
	reference_to<Graph_lib::Window>(pw).attach(*rect1);
	
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
	Graph_lib::Window win(Point(200, 200), 600, 400, "test window");
	Graph_lib::Rectangle rect1(Point(50, 50), Point(100, 100));
	rect1.set_fill_color(Color::yellow);
	win.attach(rect1);
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
	/*win.wait_for_button();*/
	//Graph_lib::Rectangle rect2(Point(150, 150), Point(170, 180));
	//win.attach(rect2);
	win.end();
	win.show();
	return Fl::run();
}
catch (const std::exception&)
{
	return 1;
}

// --------------------------------------------------------------
////#include <FL/Fl.H>
////#include <FL/Fl_Double_Window.H>
////#include <FL/Fl_Button.H>
////#include <FL/Fl_Box.H>
////
////void button1_cb(Fl_Widget* w, void* p) {
////    Fl_Button* o1 = (Fl_Button*)w;
////    o1->value(o1->value() ? 0 : 1);
////    w->label(o1->value() ? "button1=1" : "button1=0");
////    Fl_Box* o2 = (Fl_Box*)p;
////    o2->label("1 pressed");
////}
////void button2_cb(Fl_Widget* w, void* p) {
////    Fl_Button* o1 = (Fl_Button*)w;
////    o1->value(o1->value() ? 0 : 1);
////    w->label(o1->value() ? "button2=1" : "button2=1");
////    Fl_Box* o2 = (Fl_Box*)p;
////    o2->label("2 pressed");
////}
////void quit_cb(Fl_Widget* w, void* p) {
////    exit(0);
////}
////
////int main() {
////    Fl_Double_Window window(390, 180, "callback");
////    Fl_Box* pBox = new Fl_Box(50, 50, 290, 50, "no button pressed");
////    Fl_Button* pButton1 = new Fl_Button(50, 120, 100, 30, "button1");
////    Fl_Button* pButton2 = new Fl_Button(170, 120, 100, 30, "button2");
////    Fl_Button* pQuitButton = new Fl_Button(290, 120, 50, 30, "quit");
////
////    pButton1->callback(button1_cb, (void*)pBox);
////    pButton2->callback(button2_cb, (void*)pBox);
////    pQuitButton->callback(quit_cb, nullptr);
////
////    window.end();
////    window.show();
////    return Fl::run();
////}

//
// This is example code from Chapter 16.5 "An example" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

//#include <iostream>
//#include <sstream>
//#include "Graph.h"        // get access to our graphics library facilities
//#include "GUI.h"
//#include "Window.h"
//
//using namespace Graph_lib;
//using namespace std;
//
////------------------------------------------------------------------------------
////
//struct Lines_window : Window {
//    Lines_window(Point xy, int w, int h, const string& title);
//    Open_polyline lines;
//private:
//    Button next_button;        // add (next_x,next_y) to lines
//    Button quit_button;
//    In_box next_x;
//    In_box next_y;
//    Out_box xy_out;
//
//    static void cb_next(Address, Address); // callback for next_button
//    void next();
//    static void cb_quit(Address, Address); // callback for quit_button
//    void quit();
//};
//
////------------------------------------------------------------------------------
//
//Lines_window::Lines_window(Point xy, int w, int h, const string& title)
//    :Window(xy, w, h, title),
//    next_button(Point(x_max() - 150, 0), 70, 20, "Next point", cb_next),
//    quit_button(Point(x_max() - 70, 0), 70, 20, "Quit", cb_quit),
//    next_x(Point(x_max() - 310, 0), 50, 20, "next x:"),
//    next_y(Point(x_max() - 210, 0), 50, 20, "next y:"),
//    xy_out(Point(100, 0), 100, 20, "current (x,y):")
//{
//    attach(next_button);
//    attach(quit_button);
//    attach(next_x);
//    attach(next_y);
//    attach(xy_out);
//    attach(lines);
//}
//
////------------------------------------------------------------------------------
//
//void Lines_window::cb_quit(Address, Address pw)    // "the usual"
//{
//    reference_to<Lines_window>(pw).quit();
//}
//
////------------------------------------------------------------------------------
//
//void Lines_window::quit()
//{
//    hide();        // curious FLTK idiom for delete window
//}
//
////------------------------------------------------------------------------------
//
//void Lines_window::cb_next(Address, Address pw)     // "the usual"
//{
//    reference_to<Lines_window>(pw).next();
//}
//
////------------------------------------------------------------------------------
//
//void Lines_window::next()
//{
//    int x = next_x.get_int();
//    int y = next_y.get_int();
//
//    lines.add(Point(x, y));
//    //if (x == 0) {
//    //    Graph_lib::Rectangle* rect1 = new Graph_lib::Rectangle(Point(100, 100), Point(120, 150));
//    //    rect1->set_fill_color(Color::yellow);
//    //    attach(*rect1);
//    //} 此处想测试一下示例代码的逻辑框架能否成功运行画矩形的任务
//    //update current position readout:
//    stringstream ss;
//    ss << '(' << x << ',' << y << ')';
//    xy_out.put(ss.str());
//
//    redraw();
//}
//
////------------------------------------------------------------------------------
//
//int main()
//try {
//    Lines_window win(Point(100, 100), 600, 400, "lines");
//    return gui_main();
//}
//catch (exception& e) {
//    cerr << "exception: " << e.what() << '\n';
//    return 1;
//}
//catch (...) {
//    cerr << "Some exception\n";
//    return 2;
//}

//------------------------------------------------------------------------------
