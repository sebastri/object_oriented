#include "Simple_window.h"
#include "Emoji.h"
#include "animal.h"

// Size of window and emoji radius
constexpr int xmax = 1000;
constexpr int ymax = 600;
constexpr int emojiRadius = 50;

int main()
{
	
	using namespace Graph_lib;

	const Point tl{100, 100};
	const string win_label{"Emoji factory"};
	Simple_window win{tl, xmax, ymax, win_label};
	
	
	//Oppgave 1
	testAnimal();
	/* TODO:
	 *  - initialize emojis
	 *  - connect emojis to window
	 *
	 **/
	EmptyFace face{Point{500,300}, emojiRadius};
	face.attach_to(win);
	SmilingFace smiling{Point{600, 300}, emojiRadius};
	smiling.attach_to(win);
	SadFace sad{Point{700, 300}, emojiRadius};
	sad.attach_to(win);
	AngryFace angry{Point{800, 300}, emojiRadius};
	angry.attach_to(win);
	WinkingFace wink{Point{900, 300}, emojiRadius};
	wink.attach_to(win);

	/*
	Vector_ref<Emoji> vec;
	vec.push_back(face);
	vec.push_back(smiling);
	*/

	
	

	win.wait_for_button();
	
	


	keep_window_open();
}
